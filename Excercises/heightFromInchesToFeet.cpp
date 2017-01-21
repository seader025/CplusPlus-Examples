#include <iostream>

using namespace std;
void convert(int inch);

void heightConversion()
{
	// Declarations
	int heightInInches;

	//Store input and Confirm if input is a positive integer
	while (std::cout << "Please Enter your height in inches: (must be a positive number):_____\b\b\b\b\b " &&
		(!(std::cin >> heightInInches) || heightInInches < 0))
	{
		std::cout << "Not a positive integer!\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	convert(heightInInches);
}

void convert(int inch)
{
	int feet, inches;
	inches = inch % 12;
	feet = inch / 12;
	cout << "Your height in feet is " << feet << "\'-feet" << " and " << inches << "\"-inches" << endl;
}

