// Vector Tests1.cpp : Defines the entry point for the console application.
// The following is an example of usage in the command line
// Example:        C:\Users\DaqScribe\Desktop\Vector Tests1\Release>VectorTests1.exe 1000


#include <vector> // vector library
#include "Timer.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream> // for std::stringstream
#include <mkl_vml_functions.h>
#include <cstdio>
#include <cstdlib>
#include <ipps.h>
#include <ippcore.h>
#include "tbb/tbb.h"

using namespace std;

// function declarations
void func_cpp(int n);
void vectorFunction(int n);
void intelLoopFunc(int n);
void intelVectorFunction(int n);

int main(int argc, char *arg[])
{
	// Convert Args into numeric value
	std::stringstream convert(arg[1]); // set up a stringstream variable named convert, initialized with the input from arg[1]
	
	//Definitions
	int n;
	
	// Convert Args into integers
	if (!(convert >> n)) { // do the conversion
		n = 0; // if conversion fails, set numIterations to a default value
	}

	

	// In[1]:
	//func_cpp(n);

	// In[2]:
	vectorFunction(n);

	// In[3]:
	//intelLoopFunc(n);

	// In[4]:
	//intelVectorFunction(n);

    return 0;
}

// In[1] - regular loop test :
void func_cpp(int n) {
	//Declarations
	Timer timer;
	double totalBytes = n;
	bool loopIsDone = false;
	double a = 3.44;
	double b = 6.34;
	// Allocate proper memory into first location
	long double * buffer = (long double *)malloc(sizeof(double) * totalBytes);

	// start timer
	timer.start();

	while (loopIsDone != true) {
		// code to be tested
		for (int i = 0; i < n; i++) {
			buffer[i] = a * b;
			//cout << "buffer = "<< buffer[i] << endl;
			if (i == n - 1) {
				loopIsDone = true;
			}
		}
		// clear the buffer
		free(buffer);
	}

	// stop timer
	timer.stop();

	// print the elapsed time in millisec
	cout << timer.getElapsedTimeInMilliSec() << " ms.\n";
	cout << timer.getElapsedTimeInSec() << " sec.\n";
	//printf("The result of the function is: %f\n", *buffer);
}

// IN[2] - Vector test :
void vectorFunction(int n) {
	//Declarations
	Timer timer;
	std::vector<double> myVector;
	bool loopIsDone = false;
	double a = 3.44;
	double b = 6.34;

	// start timer
	timer.start();
	
	while (loopIsDone != true) {
		// code to be tested
		for (int i = 0; i < n; i++) {
			myVector.push_back(a * b);
			//cout << " myVector = " << myVector[i] << endl;
			if (i == n - 1) {
				loopIsDone = true;
			}
		}
		// clear the vector
		myVector.clear();
	}

	// stop timer
	timer.stop();
	
	// print statements
	cout << timer.getElapsedTimeInMilliSec() << " ms.\n";
	cout << timer.getElapsedTimeInSec() << " sec.\n";
}

// IN[3] - Intel Vector test :
void intelLoopFunc(int n)
{
	//Declarations
	Timer timer;
	double totalBytes = n;
	bool loopIsDone = false;
	double a = 3.44;
	double b = 6.34;

	// Allocate proper memory into first location
	long double * buffer = (long double *) ippMalloc(totalBytes);

	// start timer
	timer.start();
	
	while(loopIsDone != true) {
		// code to be tested
		for (int i = 0; i < n; i++) {
			buffer[i] = a * b;
			if (i == n - 1) {
				loopIsDone = true;
			}
		}
		// clear the buffer
		ippFree(buffer);
	}
	
	// stop timer
	timer.stop();

	// print statements
	cout << timer.getElapsedTimeInMilliSec() << " ms.\n";
	cout << timer.getElapsedTimeInSec() << " sec.\n";
}

// IN[4] - Intel Vector test :
void intelVectorFunction(int n) {
	//Declarations
	Timer timer;
	tbb::concurrent_vector<int> myVector;
	bool loopIsDone = false;
	double a = 3.44;
	double b = 6.34;

	// start timer
	timer.start();

	while(loopIsDone != true){
		// code to be tested
		for(int i = 0; i < n; i++){
			 myVector.push_back(a * b);
			 //cout << " myVector = " << myVector[i] << endl;
			 if(i == n - 1) {
				 loopIsDone = true;
			 }
		}
		// clear the vector
		myVector.clear();
	}
	// stop timer
	timer.stop();

	// print statements
	cout << timer.getElapsedTimeInMilliSec() << " ms.\n";
	cout << timer.getElapsedTimeInSec() << " sec.\n";
}

