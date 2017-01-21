// Programming Exercises1.cpp : Defines the entry point for the console application.
// Code written by Chad Corsentino

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	//[1]
	printNameAndAddress();

	//[2]
	//furlongsToYards();

	//[3]
	//printAgeInMonths();
	
	//[4]
	/*
	// Celcius to Fahrenheit conversion Excersise
	int celcius; // Start of Celcius to Fahrenheit
	//Store input and Confirm if input is a positive integer
	while (std::cout << "Please enter a celcius value (must be a positive number): " &&
		(!(std::cin >> celcius) || celcius < 0))
	{
		std::cout << "Not a positive integer!\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	int fahrenheit = celciusToFahrenheit(celcius);
	cout << celcius << " degrees Celcius is " << fahrenheit << " degrees Fahrenheit." << endl; // End of Celcius to Fahrenheit conversion
	*/
	
	//[5]
	//heightConversion();
	
	//[6]
	//findBMI();

	//[7]
	//latitudeConversion();
	
	//[8]
	//secondsToDays();
	
	//[9]
	//percentOfWorldPopulation();

	//[10]
	//calculateMilesPerGallon();

	//[11]
	//gasConsumptionConvertEUToUS();
    return 0;
}

