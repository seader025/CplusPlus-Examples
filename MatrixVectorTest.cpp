// MatrixVectorTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
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
void regMatrixVector();
//void intelMatrixVector();

int main()
{
	// In[5]
	regMatrixVector();

	// In[6]
	//intelMatrixVector(n);
    return 0;
}

void regMatrixVector()
{
	// Declarations
	Timer timer;
	bool loopIsDone = false;
	const int j = 100000000;
	double * a = new double [j];     // allocate a dynamic array
	double * b = new double [j];	 // allocate a dynamic array
	double * c = new double [j];
	// initialize arrays
	a[0] = 1.0;
	b[0] = 534.0;
	c[0] = 334.0;

	// start timer
	timer.start();
	
	// Main loop
	while(loopIsDone != true) {
		// code to be tested
		for(int i = 0; i < j; i++) {
			a[i] = b[i] * c[i];
			if(i == j - 1) {
				loopIsDone = true;
			}
		}
		// delete dynamic arrays (clear memory)
		delete [] a;
		delete [] b;
		delete [] c;
	}
	
	// stop timer
	timer.stop();

	// print statements
	cout << "The elapsed time of the function is: " << timer.getElapsedTimeInMilliSec() << " ms.\n";
}