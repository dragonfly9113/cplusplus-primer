#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using std::cin; using std::cout; using std::endl; using std::cerr;
using std::string; using std::vector; using std::begin; using std::end;
using std::runtime_error;

// Exercise 6.2
int f2(int i) 
{
	return i;
}

double square(double x) 
{
	return x * x;
}

// Exercise 6.3, 6.4
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

// Exercise 6.5
int abs_value(int val)
{
	int ret;
	
	if (val >= 0)
		ret = val;
	else
		ret = -val;
	
	return ret;
}




