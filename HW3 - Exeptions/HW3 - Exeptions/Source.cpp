//Main driver of the program
//Author: Kostiantyn Makrasnov
//COMPLETED from problem guide base

#include <iostream>
#include <stdexcept>
#include "readint.h"
using namespace std;

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
		// Throw exeption if bounds do not constitute a valid range
		if (high <= low || high == NULL || low == NULL)
			throw std::invalid_argument("Incorrect bounds entered");
		
		// Format the prompt so low and high int values are seen in prompt
		std::string prompt = std::string("Please enter a number within the range (") 
						   + std::to_string(low) + '-' 
						   + std::to_string(high) + std::string("): ");

		// Prompt the user for an int inside the range
		int number = read_int(prompt, low, high);
		cout << "You entered " << number << endl;
	}
	catch (invalid_argument &e) { // Notifies user of improper bounds
		cerr << "Exception: You supplied an invalid argument(s) for read_int!\n";
	}
	catch (...) { // Notifies user about any other exeption
		cerr << "Exception: Some unexpected error occured!\n";
	}
}
