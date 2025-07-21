#include <iostream>

using namespace std;

int main(int argc, char **argv) {
	int val;

	for(int i = 0; i < 3; i++)
	{
		cout << "Please enter an integer value:";
		cin >> val;
		
		int* dynamicInt = new int;
		*dynamicInt = val;

		cout << "Value provided by user: " << val << endl;
		cout << "Value of dynamically created variable: " << *dynamicInt << endl;

		delete dynamicInt;
	}

	cout << "Done!" << endl;

	return 0;
}
