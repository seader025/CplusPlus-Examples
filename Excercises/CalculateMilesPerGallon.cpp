#include <iostream>

using namespace std;

void calculateMilesPerGallon()
{
	// Declarations
	double milesDriven;
	double gallonsUsed;
	double totalMilesPerGallon;

	cout << "Enter the amount of miles driven: " << endl;
	cin >> milesDriven;
	cout << "Enter the amount of gas you used in gallons: " << endl;
	cin >> gallonsUsed;

	totalMilesPerGallon = milesDriven / gallonsUsed;
	cout << "Your total miles pergallon for the trip was: " << totalMilesPerGallon << " miles/gallon." << endl;
}