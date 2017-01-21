#include <iostream>
#include <string>

using namespace std;

void candyBarArrayStruct()
{
	struct CandyBar
	{
		string brandName;
		double weight;
		int totalCalories;
	};

	CandyBar arrayCandy[3];
	arrayCandy[0] = { "Hersheys", .34, 239 };
	arrayCandy[1] = { "ButterFinger", 1.3, 248 };
	arrayCandy[2] = { "MilkdDuds", .23, 78 };

	cout << arrayCandy[0].brandName << ", " << arrayCandy[0].weight << ", " << arrayCandy[0].totalCalories << endl;
	cout << arrayCandy[1].brandName << ", " << arrayCandy[1].weight << ", " << arrayCandy[1].totalCalories << endl;
	cout << arrayCandy[2].brandName << ", " << arrayCandy[2].weight << ", " << arrayCandy[2].totalCalories << endl;
}

void candyBarStruct()
{
	struct CandyBar
	{
		string brandName;
		double weight;
		int totalCalories;
	};

	CandyBar snack = {"Mocha Munch", 2.3, 350};

	cout << "Snack Brand: " << snack.brandName << endl;
	cout << "Weight: " << snack.weight << endl;
	cout << "Total Calories: " << snack.totalCalories << endl;
}

void printLastFirstNameString()
{
	// Declarations
	string firstName;
	string lastName;

	cout << "Enter your first name: ";
	getline(cin, firstName);
	cout << endl;
	cin.clear();

	cout << "Enter your last name: ";
	cin >> lastName;
	cout << endl;

	cout << "Here's the info in a single string: " << lastName << ", " << firstName << endl;
}

void printLastFirstNameCharArray()
{
	// Declarations
	char firstName[20];
	char lastName[20];

	cout << "Enter your first name: ";
	cin >> firstName;
	cout << endl;

	cout << "Enter your last name: ";
	cin >> lastName;
	cout << endl;

	cout << "Here's the info in a single string: " << lastName << ", " << firstName << endl;
}

void inString()
{
	string name;
	string dessert;

	cout << "Enter your name: \n";
	getline(cin, name);
	cout << "Enter your favorite dessert: \n";
	cin.clear();
	getline(cin, dessert);
	cout << "I have some delicious " << dessert;
	cout << " for you, " << name << ".\n";
}


void letterGradeDecrement()
{
	// Declarations
	string firstName = "null";
	string lastName = "null";
	char letterG = 'A';
	const char * pt = &letterG;
	int age;

	cout << "What is your first name? ";
	getline(cin, firstName);
	cin.clear();
	cout << endl;

	cout << "What is your last name? ";
	cin >> lastName;
	cout << endl;

	cout << "What letter grade do you deserve? ";
	cin >> letterG;
	cout << endl;

	cout << "What is your age? ";
	cin >> age;
	cout << endl;


	cout << "Name: " << lastName << ", " << firstName << endl;
	cout << "Grade: " << static_cast<char>(letterG + 1) << endl;
	cout << "Age: " << age << endl;
}