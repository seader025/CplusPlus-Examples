// ClassPractice1.cpp creates and demonstrates a class that holds information
// about a college course.

#include "stdafx.h"
#include<iostream>
#include<string>
#include<conio.h>
using namespace std;

// Place class declarations and implementations here
class CollegeCourse
{
private:
	string department;
	int courseNum;
	int seats;
public:
	void setDepartmentAndCourse(string, int);
	void setSeats(int);
	void displayCourseData();
};
void CollegeCourse::setDepartmentAndCourse(string dept, int num)
{
	department = dept;
	courseNum = num;
}
void CollegeCourse::setSeats(int seats)
{
	if (seats < 0)
	{
		seats = 0;
	}
	this->seats = seats;
}
void CollegeCourse::displayCourseData()
{
	cout << department << courseNum << " accommodates " <<
		seats << " students " << endl;
}

int _tmain(int argc, _TCHAR* argv[]) // This is the same as main() in the book
{
	// Place main code here
	CollegeCourse myMondayClass;
	string dept;
	int num;
	int students;

	// Prompt user for values
	cout << "Enter the department that hosts the class," << endl;
	cout << "for example 'CIS' >> ";
	cin >> dept;
	cout << "Enter the course number, for example, for " << dept << "101, enter 101 >> ";
	cin >> num;
	cout << "Enter the number of students that are allowed" << endl;
	cout << "to enroll in " << dept << num << " >> ";
	cin >> students;

	// Set Object Values and Display
	myMondayClass.setDepartmentAndCourse(dept, num);
	myMondayClass.setSeats(students);
	myMondayClass.displayCourseData();

	// Force the console to stay open until a key is pressed
	cout << endl;
	system("pause");
	return 0;
}

