#include <iostream>

using namespace std;

void latitudeConversion()
{
	// Declarations
	double degrees, min, sec;
	const double minArc = 60.0;
	const double degArc = 60.0;
	double totalDegrees;
	double totalMin;
	long double totalSec;

	cout << "Enter a latitude in degrees, minutes, and seconds:\n";
	cout << "First, enter the degrees: ";
	cin >> degrees;
	cout << "Next, enter minutes of arc: ";
	cin >> min;
	cout << "Finally, enter the seconds of arc: ";
	cin >> sec;
	totalMin = (min / degArc);
	totalSec = (sec / minArc) / degArc;
	totalDegrees = degrees + totalMin + totalSec;
	cout << degrees << " degrees, " << min << " minutes, " << sec << " seconds = " << totalDegrees << " degrees" << endl;
}