/*
* Program Name: csc450-module-03
* Author: 		Kyle Parrish
* Description:
* 	This program prompts the user three times for two strings.  These strings
* 	are then concatenated into a new variable and printed out to the terminal.
*/
#include <iostream>

// import the std namespace to make the program a little less wordy (no std:: statements)
using namespace std;

int main(int argc, char **argv) {
	int val;

	// loop through 3 times
	for(int i = 0; i < 3; i++)
	{
		// prompt the user for input and store it in val
		cout << "Please enter an integer value:";
		cin >> val;

		// create a new dynamic variable and assign the value from val to it
		int* dynamicInt = new int;
		*dynamicInt = val;

		// display the original val, the value of the dynamic value and the memory address of the dynamic variable
		cout << "Value provided by user: " << val << endl;
		cout << "Value of dynamically created variable: " << *dynamicInt << endl;
		cout << "Memory Address of dynamically created variable: " << dynamicInt << endl;

		// delete the dynamic variable
		delete dynamicInt;
	}

	cout << "Done!" << endl;

	// exit program
	return 0;
}
