//read_int function implementation file
//Author: Kostiantyn Makrasnov
//COMPLETED from problem guide base

#include "readint.h"
#include <stdexcept>
#include <iostream>
using namespace std;

int read_int(const string &prompt, int low, int high)
{
	//ADAPTED from Example 2.8 in Chapter 2.2 
	//"Objects, Abstraction, Data Structures and Design Using C++"
	/** Asks user to enter an integer in a specified range
		@param prompt | Message to user
		@param lowest | Lowest accepted int
		@param highest | Highest accepted int
		@return | The first valid int within range
	*/
	cin.exceptions(ios_base::failbit);
	int num = 0;
	while (true){	// Loop until valid input
		try {
			cout << prompt;
			cin >> num;
			if (num > high || num < low || low == high) 
			{
				std::string error = "Integer outside of valid range!";
				throw range_error(error);
			}

			return num;
		}
		catch (ios_base::failure& ex) {
			// Print error message
			cout << "ERROR: Bad Numeric String" << endl;
			cout << "Please Try Again..." << endl;
			// Reset the error flag
			cin.clear();
			// Skip current input line
			cin.ignore(numeric_limits<int>::max(), '\n');
		}
		catch (range_error &msg) {
			// Print error message
			cout << "ERROR: Integer Outside of Valid Range" << endl;
			cout << "Please Try Again..." << endl;
		}
		catch (...) {
			// Print error message
			cout << "ERROR: Unrecognized" << endl;
			cout << "Please Try Again..." << endl;
		}
	}
}
