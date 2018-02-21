#include <iostream>
#include <stdexcept>
#include <cstdio>
#include "readint.h"
using namespace std;


//Main driver of the program
//Author: Kostiantyn Makrasnov
//COMPLETED from problem guide base

int main()
{
	// Ask user for integer input bounds
	int low, high;
	cout << "Enter the range of values to read.\n";
	cout << "high: ";
	cin >> high;
	cout << "low: ";
	cin >> low;
	// Get user input within specified range 
	try
	{
		// Format the prompt so low and high int values are seen in prompt
		std::string prompt = std::string("Please enter a number within the range (") 
						   + std::to_string(low) + '-' 
						   + std::to_string(high) + std::string("): ");

		// Prompt the user for an int inside the range
		int number = read_int(prompt, low, high);
		cout << "You entered: " << number << endl;
	}
	catch (std::invalid_argument &e) { // Notifies user of improper bounds
		cerr << "Exception: You supplied an invalid RANGE argument(s) for read_int!\n";
	}
	catch (...) {
		cerr << "Exception: Something Unexpected Occured!\n";
	}

	//Pause Execution (to see results)
	cin.ignore();
	cin.get();

	return 0;
}
