// MemMove_SpeedReader.cpp : Defines the entry point for the console application.
// This console application recieves input from a file and copies it to a temporary buffer
// while reading the speed of that transfer (in MBytes/second).  (Max bytes before program crashes: 100000000 bytes)

// Example command: C:\Users\DaqScribe\Desktop\MemMove_SpeedReader\Release>MemMove_SpeedReader.exe <Number of iterations> <Number of bytes>

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <chrono>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <sstream> // for std::stringstream
#include <cstdlib> // for exit()
#include <Windows.h> // Windows Platform SDK

using namespace std;
using namespace std::chrono;

double PCFreq = 0.0;
__int64 CounterStart = 0;

void StartCounter()
{
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
		cout << "QueryPerformanceFrequency failed!\n";

	PCFreq = double(li.QuadPart);

	QueryPerformanceCounter(&li);
	CounterStart = li.QuadPart;
}
double GetCounter()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	return double(li.QuadPart - CounterStart) / PCFreq;
}

int main(int argc, char *arg[])
{
	// Convert Args into numeric value
	std::stringstream convert(arg[1]); // set up a stringstream variable named convert, initialized with the input from arg[1]
	std::stringstream convertTwo(arg[2]); // set up a stringstream variable named convert, initialized with the input from arg[2]
	int numIterations;
	long bytes_in_data_file;
	long long accumulated_data_size = 0;
	double bps = 0.0, mbps = 0.0, ellapsed_time = 0.0, duration_in_seconds = 0.0;
	
	// Convert Args into integers
	if (!(convert >> numIterations)) { // do the conversion
		numIterations = 0; // if conversion fails, set numIterations to a default value
	}
	if (!(convertTwo >> bytes_in_data_file)) { // do the conversion
		bytes_in_data_file = 0; // if conversion fails, set bytes_in_data_file to a default value
	}

	// Allocate proper memory into first location
	char * buffer = (char *)malloc(bytes_in_data_file);

	// Allocate proper memory into another location
	char * bufferCopy = (char *)malloc(sizeof(char) * bytes_in_data_file);

	// Take timestamp #1
	StartCounter();
	
	// Run the program for user defined number of iterations
	for (int j = 0; j < numIterations; j++) 
	{
		// Copy buffer to bufferCopy
		memcpy(bufferCopy, buffer, bytes_in_data_file);
		accumulated_data_size = accumulated_data_size + bytes_in_data_file;
	}

	// Take timestamp #2
	ellapsed_time = GetCounter();
	
	// Convert duration into bytes per second
	bps = accumulated_data_size / ellapsed_time;
	
	// Convert bps into megaBytesPerSecond
	mbps = bps / 1048576.0;

	//Print the information
	printf("The total duration is: %f\n", ellapsed_time);
	printf("accumulated_data_size: %d Bytes \n", accumulated_data_size);
	printf("The speed of your data transfer is: %f Mega Bytes Per Second\n", mbps);
	printf("Amount of Data processed per iteration = %d\n\n", bytes_in_data_file);

	//Clean out the memory buffers
	free(buffer);
	free(bufferCopy);
	
    return 0;
}

