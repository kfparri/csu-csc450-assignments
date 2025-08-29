/*
* Program Name: csc450-module-05
* Author: 		Kyle Parrish
* Description:
* 	This program prompts the user for a string.  The program takes that string and appends it
* 	 to a file.  After the file has been appended to, the file is opened and all the text is
* 	 reversed and put into a new file.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

// Validate use input.  For this program it only takes letters, numbers and spaces and a max length
bool validInput(const string& input, size_t maxInputLength)
{
	if(input.size() > maxInputLength)
	{
		return false;
	}

	for (char ch : input)
	{
		if(!isalnum(static_cast<unsigned char>(ch)) && ch != ' ')
		{
			// only allow letters, numbers and spaces
			return false;
		}
	}

	return true;
}

// Append the content to the provided file, returns true if there are no errors
//  false otherwise.
bool appendToFile(string filename, string content)
{
	// open the file in append mode
	ofstream outfile(filename, std::ios::app);

	if(!outfile)
	{
		cerr << "Error opening output file!" << endl;
		return false;
	}

	outfile << content << endl;

	outfile.close();

	return true;
}

// reverses the content of a file into a new file.  Returns true if there are no errors,
//  false otherwise
bool reverseFile(string inputFile, string outputFile)
{
	ifstream inFile (inputFile, std::ios::in);

	if(!inFile)
	{
		cerr << "Error opening input file" << endl;
		return false;
	}

	// read the entire file into a stream
	stringstream buffer;
	buffer << inFile.rdbuf();
	string content = buffer.str();

	inFile.close();

	std::reverse(content.begin(), content.end());

	ofstream outFile(outputFile, std::ios::out);

	if(!outFile)
	{
		cerr << "Error opening output file" << endl;
		return false;
	}

	outFile << content;
	outFile.close();

	return true;
}

int main() {
	// define the default file names and input max length
	string filename = "CSC450_CT5_mod5.txt";
	string reverseFileName = "CSC450-mod5-reverse.txt";
	const size_t MAX_INPUT_LENGTH = 250;
	string userInput;

	// loop until the user provides valid input
	while(true)
	{
		cout << "Enter a string to append (max size: " << MAX_INPUT_LENGTH << " letters/numbers/spaces): ";

		getline(cin, userInput);

		if(validInput(userInput, MAX_INPUT_LENGTH))
		{
			// valid input, exit the input loop
			break;
		} else {
			cout << "Invalid input! Please try again." << endl;
		}
	}

	// if there is a problem writing to the files, return error code (1)
	if(!appendToFile(filename, userInput))
	{
		return 1;
	}

	if(!reverseFile(filename, reverseFileName))
	{
		return 1;
	}

	cout << "Added the content to: " << filename << " and reversed the content of the file to " << reverseFileName << endl;

	return 0;
}
