#include <iostream>

using namespace std;

void percentOfWorldPopulation()
{
	// Declarations
	long double worldPop, currentPop;
	double percentOfPop;

	cout << "Enter the World's current population: " << endl;
	cin >> worldPop;
	cout << "Enter the current population of any country: " << endl;
	cin >> currentPop;

	percentOfPop = (currentPop / worldPop) * 100;
	cout << "The population of your selected country is " << percentOfPop << "\% of the world population." << endl;
}