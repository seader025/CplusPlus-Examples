// ClassPractice6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <ctime>
using namespace std;

// Place class declarations and implementations here
class Die
{
private:
	int dieFaceUpValue;
public:
	const static int MAX_DIE_VALUE;
	void setDieFaceUpValue(int);
	int getDieFaceUpValue();
};
const int Die::MAX_DIE_VALUE = 6;
void Die::setDieFaceUpValue(int faceValue)
{
	dieFaceUpValue = faceValue;
}
int Die::getDieFaceUpValue()
{
	return dieFaceUpValue;
}


int _tmain(int argc, _TCHAR* argv[]) // This is the same as main() in the book
{
	// Place main code here
	Die dice;
	char rollAgain = 'y';
	char playAgain = 'y';
	srand((unsigned)time(NULL));

	while (playAgain == 'y' || playAgain == 'Y')
	{ 
		int scoreComp = 0;
		int scorePlayer = 0;
		bool playerQuit = false;
		bool compQuit = false;
		bool gameOver = false;

		while (gameOver == false)
		{
			// Roll Die for Player turn
			if(scorePlayer < 22 && playerQuit != true)
			{ 
				dice.setDieFaceUpValue(rand() % Die::MAX_DIE_VALUE + 1);
				scorePlayer = scorePlayer + dice.getDieFaceUpValue();
				cout << "Current Score:  " << scorePlayer << endl;
			}
			cout << endl << endl;
		
			// Roll Die for Computer turn
			if (scoreComp < 19 && compQuit != true)
			{ 
				dice.setDieFaceUpValue(rand() % Die::MAX_DIE_VALUE + 1);
				scoreComp = scoreComp + dice.getDieFaceUpValue();
				cout << "Computer's Score:  " << scoreComp << endl;
			
				if (scoreComp > 21)
				{
					cout << "Player Wins!!! " << endl;
					compQuit = true;
					playerQuit = true;
				}
				else if (scorePlayer > 21)
				{
					playerQuit = true;
					compQuit = true;
					cout << "Computer Wins... " << endl;
				}
				else if ((scoreComp <= 21 && scoreComp > 18) && scorePlayer < 21 && playerQuit == true)
				{
					compQuit = true;
					cout << "Computer Wins... " << endl;
				}
				else if (scoreComp > 21 && scorePlayer < 22)
				{
					playerQuit = true;
					cout << "Player Wins!!! " << endl;
				}
				else if (scorePlayer > 21 && scoreComp < 22)
				{
					playerQuit = true;
					cout << "Computer Wins... " << endl;
				}
				else if (compQuit == true && scoreComp < 21 && scorePlayer > 21)
				{
					playerQuit = true;
					cout << "Computer Wins... " << endl;
				}
				else if (scoreComp == 21 && scorePlayer < 21 && playerQuit == true)
				{
					cout << "Computer Wins... " << endl;
				}
			}
			else
			{
				compQuit = true;
			}
		
			// Prompt Player if they want to roll again
			if (playerQuit != true && scorePlayer < 22)
			{ 
				cout << endl << endl;
				cout << "Roll again? y or n" << endl;
				cin >> rollAgain;
				if (rollAgain == 'n' || scorePlayer > 22)
				{
					playerQuit = true;
				}
			}

			// Check if both oponents quit
			if (playerQuit == true && compQuit == true)
			{
				gameOver = true;
			}
		}

		if (scoreComp == scorePlayer && scorePlayer < 22)
		{
			cout << "Player Wins!!! " << endl;
		}
		
		// Play again?
		cout << endl;
		cout << "Would you like to play again? (y or n): ";
		cin >> playAgain;
	}

	// Force the console to stay open until a key is pressed
	cout << endl;
	system("pause");
	return 0;
}

