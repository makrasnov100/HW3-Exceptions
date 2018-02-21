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
			// crate a string stream object with the desired input
			std::istringstream ss1("Hello\n0");

			// Replace the cin read buffer with the read buffer from the string stream 
			std::streambuf *orig_cin = std::cin.rdbuf(ss1.rdbuf());

			// Perform the read_int() test.
			// cin will now read contents from your stringstream and not from the keyboard.
			// We expect the correct value returned is 0, ignoring the Hello string.
			Assert::AreEqual(read_int("My prompt: ", -3, 3), 0);

			// Restore cin to the way it was before
			std::cin.rdbuf(orig_cin);
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

		TEST_METHOD(TestCase3) // Test case 3: invalid input
		{
			// crate a string stream object with the desired input
			std::istringstream ss3("9\n5\n10\n10\n3");

			// Replace the cin read buffer with the read buffer from the string stream 
			std::streambuf *orig_cin2 = std::cin.rdbuf(ss3.rdbuf());

			// Perform the read_int() test.
			// cin will now read contents from your stringstream and not from the keyboard.
			// We expect the correct value returned is 3.
			Assert::AreEqual(read_int("My prompt: ", 0, 4), 3);

			// Restore cin to the way it was before
			std::cin.rdbuf(orig_cin2);
		}

		TEST_METHOD(TestCase4) // Test case 4: for invalid argument (same low & high)
		{
			// define a C++11 Lambda function to be called by your test
			auto func = []() {
				read_int("My prompt: ", 0, 0);
			};

			// We expect an invalid_argument exception to be thrown when we call func!
			Assert::ExpectException<std::invalid_argument>(func);
		}
	};

}