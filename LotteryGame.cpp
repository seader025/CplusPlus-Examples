#include "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <ctime>
using namespace std;



int _tmain(int argc, _TCHAR* argv[]) 
{
	//Declaratons
	const int DIVISOR = 10;
	const int NUM = 3;
	int x, guess1, guess2, guess3 = 0;
	int result = 0;
	int numArray[3] = { 0, 0, 0 };
	int guessNum = 0;
	char tryAgain = 'Y';

	// Program While loop (for Trying again)
	while (tryAgain == 'y' || tryAgain == 'Y')
	{
	
	// Print rules
	cout << "Welcome to the Lottery Game!..." << endl;
	cout << endl;
	cout << "==========================================================" << endl;
	cout << "Rules: " << endl;
	cout << "==========================================================" << endl;
	cout << "No matching pairs = Game Over" << endl;
	cout << "Any one pair matching = $10 " << endl;
	cout << "Two matching pairs = $100 " << endl;
	cout << "Three matching pairs, not in order = $1,000 " << endl;
	cout << "Three matching pairs in exact ascending order = $1,000,000 " << endl;
	cout << "==========================================================" << endl;
	cout << endl;

	// Accept user input
	cout << "Please enter your first guess (a single number from 0-9): ";
	cin >> guess1;
	cout << endl;

	cout << "Now enter your second guess (a single number from 0-9): ";
	cin >> guess2;
	cout << endl;

	cout << "Now enter your third guess (a single number from 0-9): ";
	cin >> guess3;
	cout << endl;

	// Generate Random Numbers
	srand((unsigned)time(NULL));
	for (x = 0; x < NUM; ++x)
	{
		numArray[x] = rand() % DIVISOR;
		//cout << numArray[x] << "  ";
	}

	cout << " You've guessed: " << guess1 << ", " << guess2 << ", " << guess3 << endl;
	cout << " The lottery numbers were: " << numArray[0] << ", " << numArray[1] << ", " << numArray[2] << endl;
	cout << endl;
	// Compare Guesses to numArray and ouput message
	//Any One Matching
	if ((guess1 == numArray[0] && guess2 != numArray[1] && guess3 != numArray[2]) ||
		(guess2 == numArray[1] && guess1 != numArray[0] && guess3 != numArray[2]) ||
		(guess3 == numArray[2] && guess1 != numArray[0] && guess2 != numArray[1]))
	{
		cout << " Congratulations!!! You've won $10 for matching one pair of numbers!";
	}
	// Two Matching
	if ((guess1 == numArray[0] && guess2 == numArray[1] && guess3 != numArray[2]) ||
		(guess2 == numArray[1] && guess3 == numArray[2] && guess1 != numArray[0]) ||
		(guess3 == numArray[2] && guess1 == numArray[0] && guess2 != numArray[1]))
	{
		cout << "Congratulations!!! You've won $100 for matching two pairs of numbers!";
	}
	// Three Matching, in exact ascending order... else Three Matching, not in any particular order
	if ((guess1 == numArray[0] && guess2 == numArray[1] && guess3 == numArray[2]) &&
		(guess1 < guess2 && guess2 < guess3))
	{
		cout << "JACKPOT!!! You've won the Grand Prize of $1,000,000 for matching 3 pairs in exact ascending order!";
	}
	else if (guess1 == numArray[0] && guess2 == numArray[1] && guess3 == numArray[2])
	{
		cout << "Congratulations!!! You've won $1,000 for matching 3 pairs in no particular order!";
	}
	// No matches
	if (guess1 != numArray[0] && guess2 != numArray[1] && guess3 != numArray[2])
	{
		cout << "Sorry, you did not match any pairs of numbers... ";
	}
	cout << endl;
	cout << endl;

	// Try again?
	cout << "Would you like to try again? (y/n) " << endl; 
	cin >> tryAgain; // change control variable
	cout << endl;
	cout << endl;
	} // end while loop

	// Force the console to stay open until a key is pressed
	cout << "Game Ended...";
	cout << endl;
	cout << endl;
	system("pause");
	return 0;
}
