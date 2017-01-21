#include <iostream>
#include <string>
#include "stdafx.h"

void printNameAndAddress()
{
	// Declarations
	using namespace std;

	string firstName;
	string lastName;
	string address;

	cout << "Enter your first name:  " << endl;
	cin >> firstName;
	cout << "Enter your last name:  " << endl;
	cin >> lastName;
	cout << "Your name is: " << firstName << " " << lastName << endl;
	cout << "Enter your address:  " << endl;
	cin.ignore();
	getline(cin, address);

	cout << "Your name and address are:  " << endl;
	cout << firstName << " " << lastName << endl;
	cout << address << endl;
}
