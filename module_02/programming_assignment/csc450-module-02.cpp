/*
* Program Name: csc450-module-02
* Author: 		Kyle Parrish
* Description:	
* 	This program prompts the user three times for two strings.  These strings
* 	are then concatenated into a new variable and printed out to the terminal.
*/
#include <iostream>

// import the std namespace to make the program a little less wordy (no std:: statements)
using namespace std;

int main(int argc, char **argv) {
	// define the three strings we will user for this program
	string str1, str2, strResults;;
	
	// prompt a header message before starting to take input
	cout << "This program will take two strings and concatenate them together and output the results" << endl;
	cout << "It will prompt you for 3 sets of two strings" << endl;

	// loop through the prompts for input 3 times, each time strings will be 
	// concatenated and displayed before restarting the loop.
	for(int i = 0; i < 3; i++)
	{
		cout << "Please enter the first string:";
		getline(cin, str1);

		cout << "Please enter the second string: ";
		getline(cin, str2);

		strResults = str1 + str2;
	
		cout << "The combined stirng is: " << strResults << endl;
	}

	return 0;
}
