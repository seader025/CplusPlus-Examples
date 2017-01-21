#include <iostream>

using namespace std;

void secondsToDays()
{
	// Declarations
	long long input_seconds;
	const int secsInMin = 60;
	const int minsInHour = 60;
	const int hoursInDay = 24;
	long days, hours, mins, seconds;

	cout << "Enter a High number of seconds:  " << endl;
	cin >> input_seconds;
	
	days = input_seconds / secsInMin / minsInHour / hoursInDay;
	hours = (input_seconds / secsInMin / minsInHour) % hoursInDay;
	mins = (input_seconds / secsInMin) % minsInHour;
	seconds = input_seconds % secsInMin;

	cout << input_seconds << " seconds = " << days << " days, " << hours << " hours, " << mins << " minutes, " << seconds << " seconds" << endl;
}