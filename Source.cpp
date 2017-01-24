// Assignment 1
// 20/10/2015
// Anonymous

#include <iostream>
#include <math.h>
#include <time.h>

using namespace std;

// This is the startNewGame subprogram.
// It is used to set a new pile of 
// pennies for the user and computer 
// to take an amount from.
void startNewGame(int &pennyPile, int &compOrUser, int &gameCurNumber,
	int &compGamesWon, int &userGamesWon)
{
	if (compOrUser == 2)	// If the user was the last to use then computer wins.
	{
		cout << "The computer won this game.\n";
		gameCurNumber = gameCurNumber + 1;
		compGamesWon = compGamesWon + 1;
	}
	else // Otherwise the user wins.
	{
		cout << "The user has won this game.\n";
		gameCurNumber = gameCurNumber + 1;
		userGamesWon = userGamesWon + 1;
	}

	cout << "The computer has won: " << compGamesWon << ".\n";
	cout << "The user has won: " << userGamesWon << ".\n";
	cout << "This is game number " << gameCurNumber << ".\n";
 	pennyPile = rand() % 75; // Needs another random number.
	cout << "A new game has begun.\n";
	int i = 0;
	for (int i = 0; i < pennyPile; i++)	// Loop through pennies and print them.
	{
		cout << "O ";
	}
	cout << "\n";	// This prevents a few visual collisions with pennies.
} // startNewGame

//  This is the showCoinsLeft subprogram.
//	It is used to check how many pennies
//	are left after each turn made by the
//	user or the computer. Once the pennies
//	reach 1 or less than 1 whoevers turn it
//	is loses and the game is reset in preperation
//	for a new game to begin if the max number of
//	games have not been surpassed.
void showCoinsLeft(int &pennyPile, int &compOrUser, int &gameCurNumber,
	int &compGamesWon, int &userGamesWon)
{
	int i = 0;
	for (i; i < pennyPile; i++) // Loop through pennies and print them.
	{
		cout << "O ";
	}
	cout << "\n";	// This prevents a few visual collisions.

} //showCoinsLeft

//  This is the compTakesTurn subprogram.
//	It is used whenever the user has
//	recently taken their turn. If there
//	are less than 7 pennies left computer
//	will specifically take a number of
//	defined pennies until it no longer
//	meets the condition whenever this
//	subprogram is called.
void compTakesTurn(int &pennyPile, int &compOrUser, int &gameCurNumber,
	int &compGamesWon, int &userGamesWon)
{
	if (pennyPile <= 0)	// Check if the user took the last penny or more.
	{
		compOrUser = 2;
		startNewGame(pennyPile, compOrUser, gameCurNumber,
			compGamesWon, userGamesWon);
	}
	else if (pennyPile == 1) // Else if there is one more penny then user wins.
	{
		compOrUser = 1;
		startNewGame(pennyPile, compOrUser, gameCurNumber,
			compGamesWon, userGamesWon);
	}
	else
	{
		int compPennyTakeAmount = rand() % 5; // Initially random number always.

		if (compPennyTakeAmount < 1)
		{
			compPennyTakeAmount = 1; // Makes sure compPennyTakeAmount is at least 1.
		}

		if (pennyPile < 7) // Specific amount taken when pennies are less than 7.
		{
			compPennyTakeAmount = 1;
		}
		pennyPile = pennyPile - compPennyTakeAmount;
		cout << "The computer has taken " << compPennyTakeAmount << " pennies.\n";
		compOrUser = 2;
		showCoinsLeft(pennyPile, compOrUser, gameCurNumber, compGamesWon,
			userGamesWon);
	}
} //compTakesTurn

//  This is the takePennies subprogram.
//	It is used whenever the user has 
//	taken their turn and selected a 
//	valid amount of pennies to take 
//	from the pile. It will then run 
//	the showCoinsLeft subprogram to
//	display how many coins are left 
//	whilst also running the compTakesTurn
//	subprogram so it automatically takes
//	coins after the user can taken a turn.
void takePennies(int amountToTake, int &pennyPile, int &compOrUser, 
int &gameCurNumber, int &compGamesWon, int &userGamesWon)
{
	pennyPile = pennyPile - amountToTake;
	cout << "You took " << amountToTake << " pennies.\n";
	compOrUser = 1;
	showCoinsLeft(pennyPile, compOrUser, gameCurNumber, compGamesWon,
		userGamesWon);
	compTakesTurn(pennyPile, compOrUser, gameCurNumber, compGamesWon,
		userGamesWon);
} //takePennies

void main()
{
	srand(time(NULL));			   // Gives a random seed for a pseudo-random number.
	bool compGoesFirst = false; // Set to true for for computers turn first.
	int pennyPile = rand() % 75; // Change the number for more range of values.
	int amountToTake;           // Amount the user inputs to take.
	int compOrUser;					// Don't change; 1 for comp, 2 for user checking.
	int maxGamesPlay = 5;		    // Change how many games can be played.
	int gameCurNumber = 1;			// This is increased per game played.
	int compGamesWon = 0;				// Keeps track of the games won by computer.
	int userGamesWon = 0;				// Keeps track of the games won by the user.

	for (int i = 0; i < pennyPile; i++)
	{
		cout << "O ";
	}
	cout << "\n";
	if (compGoesFirst)
	{
		compOrUser = 1;
		compTakesTurn(pennyPile, compOrUser, gameCurNumber, compGamesWon,
			userGamesWon);
		compGoesFirst = false;  // Set the value to false afterwards.
	}

	while (gameCurNumber < maxGamesPlay + 1)
	{
		if (pennyPile > 1)
		{
			cout << "Please enter an amount of pennies between 1 and 5 to take:\n";
			cin >> amountToTake;
		}
		else
		{
			showCoinsLeft(pennyPile, compOrUser, gameCurNumber, compGamesWon,
				userGamesWon);
		}
		while (amountToTake < 1 || amountToTake > 5)
		{
			cout << "Please enter an amount of pennies between 1 and 5 to take:\n";
			cin >> amountToTake;
		}
		compOrUser = 2;
		takePennies(amountToTake, pennyPile, compOrUser, gameCurNumber,
			compGamesWon, userGamesWon);
	}
} // main