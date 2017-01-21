// ClassExcercise2.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include<iostream>
#include<string>
#include<conio.h>
using namespace std;

// Place class declarations and implementations here
class Customer
{
private:
	int customerIDN;
	string lastName;
	string firstName;
	double creditLimit;
public:
	void setcustomerIDN(int);
	void setLastName(string);
	void setFirstName(string);
	void setCreditLimit(double);
	void displayCustomerData();
};
void Customer::setcustomerIDN(int id)
{
	customerIDN = id;
}
void Customer::setLastName(string lastName)
{
	this->lastName = lastName;
}
void Customer::setFirstName(string firstName)
{
	this->firstName = firstName;
}
void Customer::setCreditLimit(double creditLimit)
{
	if (creditLimit <= 10000)
	{ 
		this->creditLimit = creditLimit;
	}
	else
	{
		cout << "ERROR: Cannot excede a limit of $10,000." << endl;
		this->creditLimit = 0.0;
	}
}
void Customer::displayCustomerData()
{
	cout << "Customer ID:     " << customerIDN << endl
		<<  "First Name:      " << firstName << endl
		<<  "Last Name:       " << lastName << endl
		<<  "Credit Limit:    " << creditLimit << endl << endl;
}



int _tmain(int argc, _TCHAR* argv[]) // This is the same as main() in the book
{
	// Place main code here
	const int SIZE = 5;
	Customer customerArray[SIZE];
	int id;
	string firstName;
	string lastName;
	double credit;

	cout << "Please enter the following information for each customer:  " << endl;
	
	for (int i = 0; i < SIZE; i++)
	{
		cout << "Customer #" << i + 1 << ":  " << endl
			<<  "ID Number   :  " << endl;
		cin >> id;
		customerArray[i].setcustomerIDN(id);
		cout << "First Name  :  " << endl;
		cin >> firstName;
		customerArray[i].setFirstName(firstName);
		cout << "Last Name   :  " << endl;
		cin >> lastName;
		customerArray[i].setLastName(lastName);
		cout << "Credit Limit:  " << endl;
		cin >> credit;
		customerArray[i].setCreditLimit(credit);
	}
	
	for (size_t i = 0; i < SIZE; i++)
	{
		customerArray[i].displayCustomerData();
	}
	// Force the console to stay open until a key is pressed
	cout << endl;
	system("pause");
	return 0;
}

