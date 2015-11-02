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
	
	while (readp(cin, p))
		printp(cout, p) << endl;
	
	return 0;
}

// Exercise 7.10
int main()
{
	Sales_data data1, data2;
	
	if (read(read(cin, data1), data2)) {
		print(cout, data1);
		cout << endl;
		print(cout, data2);
	}

	return 0;
}
