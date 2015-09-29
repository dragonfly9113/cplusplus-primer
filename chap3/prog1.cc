#include <iostream>
#include <string>
#include "Sales_data.h"

using std::cin; using std::cout; using std::endl; using std::cerr;

// Exercise 3.1: rewrite programs in exercise section 1.4.1 with appropriate using declarations
int ex3_1_1()
{
	int sum = 0, cnt = 50;
	while(cnt <= 100)	{
		sum += cnt;
		++cnt;
	}
	cout << "The sum from 50 to 100 is " << sum << endl;
	
	cnt = 10;
	while(cnt >= 0) {
		cout << cnt << endl;
		--cnt;
	}
	
	cout << "Enter two numbers:" << endl;
	int v1 = 0, v2 = 0;
	cin >> v1 >> v2;
	
	while(v1 <= v2) {
		cout << v1 << endl;
		++v1;
	}
	
	return 0;
}

// Exercise 3.1: rewrite programs in exercise section 2.6.2 with appropriate using declarations
int main()
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

