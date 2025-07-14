#include<iostream>
#include<conio.h>
#include <iomanip>

//Standard namespace declaration
using namespace std;

//Main Function
int main()
{
	double myMoney = 1000.50;  //this should be printed out

	//Standard Ouput Statement
	cout << "Please be sure to correct all syntax errors in this program" << endl;

	cout << "I have corrected all errors for this program." << endl;

	cout << " The total amount of money available is = $" << fixed << setprecision(2) << myMoney << endl;

	// Wait For Output Screen
	cout << "\nPress Enter to exit...";
	
	// clear any previous newline from input buffer
    cin.ignore();

	// wait for the user to hit Enter 
    cin.get();

	//Main Function return Statement
	return 0;
}
