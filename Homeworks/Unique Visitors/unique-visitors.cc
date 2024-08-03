/**
 *   @file: unique-visitors.cc
 * @author: Parker Riggs
 *   @date: 03 / 21 / 23
 *  @brief: This program reads a log file of website names and removes all duplicate IP addresses. 
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <vector>
using namespace std;

//Constants and function prototypes
void output(ofstream &outStream);
vector<string> addresses(ifstream &inStream);

int main(int argc, char const *argv[]) {

	// Variables
	ifstream inStream;
	ofstream outStream;

	// Checks that 3 command lines were entered
	if(argc != 3){	
		cout << "Not enough arguments";
		exit(0);
	}

	// Makes sure each file opens correctly
	inStream.open(argv[1]);
	if(inStream.fail()){
		cout << "Input file failed to open." << endl;
		exit(0);
	}
	outStream.open(argv[2]);
	if(outStream.fail()){
		cout << "Output file failed to open." << endl;
		exit(0);
	}

	output(outStream);

	inStream.close();
	outStream.close();
	return 0;
} //main

// Output Function
void output(ofstream &outStream){	
	outStream << "ohio.edu | Number of Visitors: " << " | " << "Unique Visitors: " << endl;
	outStream << endl;
	outStream << "yahoo.com | Number of Visitors: " << " | " << "Unique Visitors: " << endl;
	outStream << endl;
	outStream << "google.com | Number of Visitors: " << " | " << "Unique Visitors: " << endl;
	outStream << endl;
	outStream << "notinteresting.org | Number of Visitors: " << " | " << "Unique Visitors: " << endl;
}

// Function to put the IP addresses into a vector
vector<string> addresses(ifstream &inStream){
	string str;
	vector<string> ipAdd;
	while(str != "-----"){
		getline(inStream, str);
		ipAdd.push_back(str);
	}
	return ipAdd;
}


