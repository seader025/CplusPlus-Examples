// ClassPractice4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<conio.h>
using namespace std;

// Place class declarations and implementations here
class Dog
{
private:
	string name;
	string breed;
	int age;
	const static double fee;
public:
	void setDogName(string);
	void setDogBreed(string);
	void setDogAge(int);
	void displayDogInfo();
};
const double Dog::fee = 12.25;
void Dog::setDogName(string dogName)
{
	name = dogName;
}
void Dog::setDogBreed(string dogBreed)
{
	breed = dogBreed;
}
void Dog::setDogAge(int dogAge)
{
	age = dogAge;
}
void Dog::displayDogInfo()
{
	cout << "Dog Details:  " << endl
		<< "Name:   " << name << endl
		<< "Breed:  " << breed << endl
		<< "Age:    " << age << endl
		<< "License Fee:  " << fee << endl << endl;
}

int _tmain(int argc, _TCHAR* argv[]) // This is the same as main() in the book
{
	// Place main code here
	Dog sally;

	sally.setDogAge(12);
	sally.setDogBreed("Husky");
	sally.setDogName("Sally");
	sally.displayDogInfo();

	// Force the console to stay open until a key is pressed
	cout << endl;
	system("pause");
	return 0;
}

