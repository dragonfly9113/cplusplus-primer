// Exercise 6.9
#include "Chapter6.h"

int fact()
{
	int val;
	int ret = 1;

	cout << "Enter an integer: " << endl;
	cin >> val;
	
	while (val >= 1)
		ret *= val--;

	return ret;
}