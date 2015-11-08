#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cassert>
#include "Sales_data.h"
#include "Person.h"

using std::cin; using std::cout; using std::endl; using std::cerr;
using std::string; using std::vector; using std::begin; using std::end;
using std::runtime_error;
using std::initializer_list;

#define NDEBUG

// Exercise 7.21
// Test after adding encapsulation and friend declarations of non-member functions 
int main_friend()
{
	// use the default constructor:
	Sales_data data1;
	cout << "data1 is: ";
	print(cout, data1) << endl;

	// use constructor Sales_data(const std::string &s)
	Sales_data data2("0X-111-1234");
	cout << "data2 is: ";
	print(cout, data2) << endl;
	
	// use constructor Sales_data(const std::string &s, unsigned u, double p)
	Sales_data data3("0X-111-1234", 5, 3.99);
	cout << "data3 is: ";
	print(cout, data3) << endl;

	// use constructor Sales_data(std::istream &)
	Sales_data data4(cin);
	cout << "data4 is: ";
	print(cout, data4) << endl;
	
	return 0;
}
