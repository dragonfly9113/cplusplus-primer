#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout; using std::endl; using std::cerr;
using std::string; using std::vector; using std::begin; using std::end;

// Exercise 5.3
int main()
{
	int sum = 0, val = 1;
	
	while (val <= 10)
		sum += val, ++val;
	
	cout << sum << endl;
	
	return 0;
}


