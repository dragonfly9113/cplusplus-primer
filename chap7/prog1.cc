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

int ex_7_25()
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

// Exercise 7.27
int ex_7_27()
{
	Screen myScreen(5, 5, 'X');
	myScreen.move(4,0).set('#').display(cout);
	cout << endl;
	myScreen.display(cout);
	cout << endl;
	
	const Screen conScreen(5, 5, 'O');
	conScreen.display(cout);
	cout << endl;
	
	return 0;
}

// Exercise 7.31
class class_y;	// forward declaration in order for name class_y to be used in class_x

struct class_x {
	class_y *ptrY = nullptr;
};

struct class_y {
	class_x objX;
};

int ex_7_31()
{
	class_x x1;
	class_y y1;
	
	x1.ptrY = &y1;
	y1.objX = x1;
	
	return 0;
}

// Exercise 7.39
int ex_7_39()
{
	// The following call is ambiguous because the compiler would not know which constructor to call, the one takes a string
	// or the one takes an istream&
	//Sales_data_738 trans1;
	Sales_data_738 trans2("9-999-9999-9");
	
	return 0;
}

// Exercise 7.40
int ex_7_40()
{
	//Employee employee1;
	//Employee employee2("John Doe");
	//Employee employee3("Johe Doe", "W00111222", "Software Engineer");
	//Employee employee4("Johe Doe", "W00111222", "Software Engineer", 16, 90000.0);
	
	return 0;
}

// Exercise 7.41
int ex_7_41()
{
	Sales_data_741 item1("0X-111-1234", 10, 3.99);
	print(cout, item1) << endl;
	Sales_data_741 item2;
	print(cout, item2) << endl;
	Sales_data_741 item3("0Y-222-3212");
	print(cout, item3) << endl;
	Sales_data_741 item4(cin);
	print(cout, item4) << endl;
	
	return 0;
}

// Exercise 7.42
int ex_7_42()
{
	Employee employee1("Johe Doe", "W00111222", "Software Engineer", 16, 90000.0);
	Employee employee2;
	Employee employee3("Johe Doe", "W00111222", "Software Engineer");
	
	return 0;
}

// Exercise 7.44
int ex_7_44()
{
	//vector<NoDefault> vec(10);
	//vector<Class_C> vec(10);
	
	return 0;
}

// Exercise 7.48
int ex_7_48()
{
	string null_isbn("9-999-9999-9");
	Sales_data item1(null_isbn);
	Sales_data item2("9-999-9999-9");
	
	print(cout, item1) << endl;
	print(cout, item2) << endl;
	
	return 0;
}

// Exercise 7.49
int ex_7_49()
{
	string s("0X-111-1234");
	Sales_data_749 i("0X-111-1234", 10, 3.99);
	
	i.combine(s);
	print(cout, i) << endl;
	
	return 0;
}

// Exercise 7.52
int ex_7_52()
{
	Sales_data_752 item = {"978-0590353403", 25, 15.99};
	
	cout << item.bookNo << " " << item.units_sold << " " << item.revenue << endl;
	
	return 0;
}

// Exercise 7.53
int ex_7_53()
{
	constexpr Debug io_sub(false, true, false);
	if (io_sub.any())
		cerr << "print appropriate error messages" << endl;
	
	constexpr Debug prod(false);
	if (prod.any())
		cerr << "print an error message." << endl;
	
	return 0;
}

// Exercise 7.57
int ex_7_57()
{
	double r;
	Account ac1;
	Account *ac2 = &ac1;

	// access static member through class name
	r = Account::rate();
	cout << "The current interest rate is: " << r << endl;
	
	// the static member can also be accessed through object, reference and pointer
	r = ac1.rate();
	cout << "The current interest rate is: " << r << endl;
	r = ac2->rate();
	cout << "The current interest rate is: " << r << endl;
	
	// change the value of static member
	Account::rate(2.0);
	r = Account::rate();
	cout << "The current interest rate is: " << r << endl;
	
	return 0;
}

// Exercise 7.58
class Example {
public:
	static double rate;
	static const int vecSize = 20;
	// error: but I don't know why?
	//static vector<double> vec(vecSize);
	static vector<double> vec;
};

double Example::rate;
// but here is OK:
vector<double> Example::vec(vecSize);

int main()
{
	for (auto e : Example::vec)
		cout << e << " ";
	
	return 0;
}
