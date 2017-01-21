#include <iostream>
#include <math.h>
using namespace std;

void findBMI()
{
	// Declarations
	int feet, inches, weight, heightInInches;
	double heightInMeters;
	double massInKilograms;
	double bmi;
	const int oneFoot = 12;
	const double meterConversion = 0.0254;
	const double kilogramConversion = 2.2;
	
	cout << "Please Enter your height in feet then inches (must be a positive integer):\nFeet = ";
	cin >> feet;
	cout << "Inches = ";
	cin >> inches;
	cout << "Now, Enter your weight in pounds:\nWeight = ";
	cin >> weight;
	cout << "You entered: " << feet << " Feet " << inches << " Inches\n" << "And...  " << weight << " Pounds\n";

	heightInInches = feet * oneFoot + inches;
	cout << "Your height in inches = " << heightInInches << "\"" << endl;

	heightInMeters = heightInInches * meterConversion;
	massInKilograms = weight / kilogramConversion;
	double sqrootOfHeight = sqrt(heightInMeters);
	bmi = massInKilograms / sqrootOfHeight;

	cout << "Your Body Mass Index is: " << bmi << endl;
}