#include <iostream>

using namespace std;

void gasConsumptionConvertEUToUS()
{
	// Declarations
	double kilometersDriven;
	double litersPerGallon = 3.875;
	double totalLitersPer100Kilometers;
	double milesPer100Kilometers = 62.14;
	double mpgUS;
	double kmPerLiter;
	cout << "Enter the amount of liters per 100 Kilometers driven (EU style): " << endl;
	cin >> totalLitersPer100Kilometers;

	kmPerLiter = totalLitersPer100Kilometers / 100;
	mpgUS = kmPerLiter * (1 / 1.609) * (3.785 / 1);
	cout << "Your mpg conversion from 1/100 Km is: " << mpgUS << "mpg" << endl;
}