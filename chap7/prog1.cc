#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cassert>
#include "Sales_data.h"
#include "Person.h"
#include "Screen.h"

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

// Exercise 7.24
int ex_7_24()
{
	Screen screen1;
	cout << "screen1 is: ";
	print(cout, screen1) << endl;;

	Screen screen2(10, 10);
	cout << "screen2 is: ";
	print(cout, screen2) << endl;;

	Screen screen3(10, 10, 'A');
	cout << "screen3 is: ";
	print(cout, screen3) << endl;;
	
	return 0;
}

// Exercise 7.25
Screen screen_copy(Screen s)
{
	Screen screen = s;
	return screen;
}

int main()
{
	Screen screen1(5, 5, 'B');
	cout << "screen1 is: ";
	print(cout, screen1) << endl;;

	// copy: initializ the variable screen2 by copying screen1:
	Screen screen2{screen1};
	cout << "screen2 is: ";
	print(cout, screen2) << endl;;

	// assignment: assign screen2 to screen3 by =:
	Screen screen3 = screen1;
	cout << "screen3 is: ";
	print(cout, screen3) << endl;;
	
	// copy: pass by value and return by value
	Screen screen4 = screen_copy(screen1);
	cout << "screen4 is: ";
	print(cout, screen4) << endl;;
	
	return 0;
}

