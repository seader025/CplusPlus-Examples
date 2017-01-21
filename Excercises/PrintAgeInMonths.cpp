#include <iostream>
#include <limits>

using namespace std;

void printAgeInMonths()
{
	// Declarations
	int age;
	int ageInMonths;

	//Store input and Confirm if input is a positive integer
	while (std::cout << "Please Enter your age: (must be a positive number): " &&
		(!(std::cin >> age) || age < 0))
	{
		std::cout << "Not a positive integer!\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	//Convert age to months
	ageInMonths = age * 12;

	cout << "Your age in months is: " << ageInMonths << "months old" << endl;
}