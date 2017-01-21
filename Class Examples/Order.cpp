// ClassPractice5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<conio.h>
using namespace std;


class Order
{
private:
	int tableNumber;
	string serverName;
	int numGuests;
public:
	static double minimumCharge;
	void setTableNum(int);
	void setServerName(string);
	void setNumGuests(int);
	void displayOrder();
};
double Order::minimumCharge = 4.75;
void Order::setTableNum(int table)
{
	tableNumber = table;
}
void Order::setServerName(string name)
{
	serverName = name;
}
void Order::setNumGuests(int guests)
{
	numGuests = guests;
}
void Order::displayOrder()
{
	cout << endl << endl
		<< "=========================" << endl
		<< "Current Order" << endl
		<< "=========================" << endl
		<< "Table #:           " << tableNumber << endl
		<< "Name of Server:    " << serverName << endl
		<< "Number of Patrons: " << numGuests << endl
		<< "=========================" << endl << endl;
}

int _tmain(int argc, _TCHAR* argv[]) 
{
	
	Order orderUp;
	int numPatrons = 5;
	cout << "The minimum charge for the current table is:  " << endl;
	cout << "$" << Order::minimumCharge * numPatrons;

	orderUp.setNumGuests(numPatrons);
	orderUp.setServerName("Tasha");
	orderUp.setTableNum(10);
	orderUp.displayOrder();

	// Force the console to stay open until a key is pressed
	cout << endl;
	system("pause");
	return 0;
}

