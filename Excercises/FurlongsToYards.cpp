#include <iostream>
#include <limits>
using namespace std;

void furlongsToYards()
{
	//Declarations
	int furlongs;
	int yards;

	while (std::cout << "Please Enter a distance in furlongs (must be a positive number): " &&
		(!(std::cin >> furlongs) || furlongs < 0))
	{
		std::cout << "Not a positive integer!\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	yards = furlongs * 220;
	cout << "Your distance (converted to Yards) =  " << yards << " yards" << endl;

}