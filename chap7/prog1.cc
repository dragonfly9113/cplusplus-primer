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

// Exercise 7.1
int Ex_7_1()
{
	Sales_data total;
	double price = 0;
	
	// read in the first record and see if it is valid:
	if(cin >> total.bookNo >> total.units_sold >> price) {
		total.revenue = total.units_sold * price;
		Sales_data trans;
		double avg_price;
		
		// read in other records
		while(cin >> trans.bookNo >> trans.units_sold >> price) {
			trans.revenue = trans.units_sold * price;
			
			if(trans.bookNo == total.bookNo) { // if this isbn is the same, update the total
				total.units_sold += trans.units_sold;
				total.revenue += trans.revenue;
			}
			else { 		// if this isbn is different, print out the last total and reset
				avg_price = (total.units_sold == 0) ? 0.0 : total.revenue / total.units_sold;
				cout << total.bookNo << " " << total.units_sold << " " << total.revenue << " " << avg_price << endl;
				
				total.bookNo = trans.bookNo;
				total.units_sold = trans.units_sold;
				total.revenue = trans.revenue;
			}
		}
		
		// print the last trans:
		avg_price = (total.units_sold == 0) ? 0.0 : total.revenue / total.units_sold;
		cout << total.bookNo << " " << total.units_sold << " " << total.revenue << " " << avg_price << endl;
	}
	else {
		cerr << "No data?!" << endl;
		return -1;
	}
	
	return 0;
}

// Exercise 7.3
int ex_7_3()
{
	Sales_data total;
	double price = 0;
	
	// read in the first record and see if it is valid:
	if(cin >> total.bookNo >> total.units_sold >> price) {
		total.revenue = total.units_sold * price;
		Sales_data trans;
		double avg_price;
		
		// read in other records
		while(cin >> trans.bookNo >> trans.units_sold >> price) {
			trans.revenue = trans.units_sold * price;
			
			if(trans.isbn() == total.isbn()) { // if this isbn is the same, update the total
				total.combine(trans);
			}
			else { 		// if this isbn is different, print out the last total and reset
				avg_price = (total.units_sold == 0) ? 0.0 : total.revenue / total.units_sold;
				cout << total.isbn() << " " << total.units_sold << " " << total.revenue << " " << avg_price << endl;
				
				total.bookNo = trans.bookNo;
				total.units_sold = trans.units_sold;
				total.revenue = trans.revenue;
			}
		}
		
		// print the last trans:
		avg_price = (total.units_sold == 0) ? 0.0 : total.revenue / total.units_sold;
		cout << total.isbn() << " " << total.units_sold << " " << total.revenue << " " << avg_price << endl;
	}
	else {
		cerr << "No data?!" << endl;
		return -1;
	}
	
	return 0;
}

// Exercise 7.7
int ex_7_7()
{
	Sales_data total;
	
	// read in the first record and see if it is valid:
	if(read(cin, total)) {
		Sales_data trans;
		
		// read in other records
		while(read(cin, trans)) {
			if(trans.isbn() == total.isbn()) { // if this isbn is the same, update the total
				total.combine(trans);
			}
			else { 		// if this isbn is different, print out the last total and reset
				print(cout, total) << endl;
				total = trans;
			}
		}
		
		// print the last trans:
		print(cout, total) << endl;
	}
	else {
		cerr << "No data?!" << endl;
		return -1;
	}
	
	return 0;
}

// Exercise 7.9
int ex_7_9()
{
	Person p;
	cout << "Enter a person's name and address on two lines: " << endl;
	
	while (read(cin, p))
		print(cout, p) << endl;
	
	return 0;
}

// Exercise 7.10
int ex_7_10()
{
	Sales_data data1, data2;
	
	if (read(read(cin, data1), data2)) {
		print(cout, data1);
		cout << endl;
		print(cout, data2);
	}

	return 0;
}

// Exercise 7.11, 7.12
int ex_7_12()
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

// Exercise 7.13: use the istream constructor
int ex_7_13()
{
	// create total object and read in first record
	Sales_data total(cin);	// read(cin, total)
	
	// check the first record read in
	if(cin) {
		// create trans object and read in the next record
		Sales_data trans(cin);
		while(cin) {
			if(trans.isbn() == total.isbn()) { // if this isbn is the same, update the total
				total.combine(trans);
			}
			else { 		// if this isbn is different, print out the last total and reset
				print(cout, total) << endl;
				total = trans;
			}
			read(cin, trans);
		}
		
		// print the last trans:
		print(cout, total) << endl;
	}
	else {
		cerr << "No data?!" << endl;
		return -1;
	}
	
	return 0;
}

// Exercise 7.14
int ex_7_14()
{
	// use the default constructor:
	Sales_data data1;
	cout << "data1 is: ";
	print(cout, data1) << endl;
	
	return 0;
}

// Exercise 7.15
int main()
{
	// use the default constructor
	Person person1;
	cout << "person1 is: ";
	print(cout, person1) << endl;
	
	// use another constructor
	Person person2("William Luo", "10243 Main St, CA, 92111");
	cout << "person2 is: ";
	print(cout, person2) << endl;
	
	return 0;
}


