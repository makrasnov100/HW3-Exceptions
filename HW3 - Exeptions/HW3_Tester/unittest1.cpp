#include "stdafx.h"
#include "CppUnitTest.h"
#include "readint.h"
#include <stdexcept>
#include <fstream>
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HW3_Tester
{		
	TEST_CLASS(READINT_TEST) // Test suite for read_int()
	{
		TEST_METHOD(TestCase1) // Test case 1: invalid input
		{
			// Open a file stream to read the file zeroinput.txt
			std::ifstream ss("..\\UnitTester\\zeroinput.txt");

			// Check if we opened the file stream successfully
			if (ss.fail())
				throw int(-1); // throw an integer with value -1

			// Replace the cin read buffer with the read buffer from the file stream 
			std::streambuf *orig_cin = std::cin.rdbuf(ss.rdbuf());

			// Perform the read_int() test.
			Assert::AreEqual(read_int("My prompt: ", -3, 3), 0);

			// Restore cin to the way it was before
			std::cin.rdbuf(orig_cin);

			// Close the file stream
			ss.close();
		}

		TEST_METHOD(TestCase2) // Test case 2: for invalid argument (high bound < low bound)
		{
			// define a C++11 Lambda function to be called by your test
			auto func = []() {
				// call with incorrect arguments (test case 2)
				read_int("My prompt: ", 5, 1);
			};

			// We expect an invalid_argument exception to be thrown when we call func!
			Assert::ExpectException<std::invalid_argument>(func);
		}

		TEST_METHOD(TestCase3) // Test case 3: proper input after 4 invalid inputs
		{
			// Open a file stream to read the file longinput.txt
			std::ifstream ss("..\\UnitTester\\longinput.txt");

			// Check if we opened the file stream successfully
			if (ss.fail())
				throw int(-1); // throw an integer with value -1

			// Replace the cin read buffer with the read buffer from the file stream 
			std::streambuf *orig_cin = std::cin.rdbuf(ss.rdbuf());

			// Perform the read_int() test.
			Assert::AreEqual(read_int("My prompt: ", 0, 4), 3);

			// Restore cin to the way it was before
			std::cin.rdbuf(orig_cin);

			// Close the file stream
			ss.close();
		}

		TEST_METHOD(TestCase4) // Test case 4: for invalid argument (same low & high)
		{
			// define a C++11 Lambda function to be called by your test
			auto func = []() {
				// call with incorrect arguments (test case 2)
				read_int("My prompt: ", 0, 0);
			};

			// We expect an invalid_argument exception to be thrown when we call func!
			Assert::ExpectException<std::invalid_argument>(func);
		}
	};

}