#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cassert>
#include "Sales_data.h"

using std::cin; using std::cout; using std::endl; using std::cerr;
using std::string; using std::vector; using std::begin; using std::end;
using std::runtime_error;
using std::initializer_list;

#define NDEBUG

// Exercise 2.41: Redo exercise section 1.6 using Sales_data
// Exercise 2.42: use my own version of Sales_data.h
// Exercise 7.1
int main()
{
	Sales_data total;
	double price = 0;
	
	// read in the first record and see if it is valid:
	if(std::cin >> total.bookNo >> total.units_sold >> price) {
		total.revenue = total.units_sold * price;
		Sales_data trans;
		double avg_price;
		
		// read in other records
		while(std::cin >> trans.bookNo >> trans.units_sold >> price) {
			trans.revenue = trans.units_sold * price;
			
			if(trans.bookNo == total.bookNo) { // if this isbn is the same, update the total
				total.units_sold += trans.units_sold;
				total.revenue += trans.revenue;
			}
			else { 		// if this isbn is different, print out the last total and reset
				avg_price = (total.units_sold == 0) ? 0.0 : total.revenue / total.units_sold;
				std::cout << total.bookNo << " " << total.units_sold << " " << total.revenue << " " << avg_price << std::endl;
				
				total.bookNo = trans.bookNo;
				total.units_sold = trans.units_sold;
				total.revenue = trans.revenue;
			}
		}
		
		// print the last trans:
		avg_price = (total.units_sold == 0) ? 0.0 : total.revenue / total.units_sold;
		std::cout << total.bookNo << " " << total.units_sold << " " << total.revenue << " " << avg_price << std::endl;
	}
	else {
		std::cerr << "No data?!" << std::endl;
		return -1;
	}
	
	return 0;
}


