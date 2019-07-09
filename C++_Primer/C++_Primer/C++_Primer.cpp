// C++_Primer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>>

#include "Bulk_quote.h"


int main()
{
	Quote item("978-3-16-148410-0", 9.99);			// object of base type
	Bulk_quote bulk("123-4-56-789012-1", 11.99, 10, 0.2);	// ojbect of derived type
	
	Quote *p = &item;	// p points to a Quote object
	//Bulk_quote *pd = &item;	// Error: cannot convert from Quote* to Bulk_quote*

	p = &bulk;			// p points to the Quote part of bulk
	Quote &r = bulk;	// p bound to the Quote part of bulk

	//Bulk_quote &rd = item;  // Error: cannot convert from Quote to Bulk_quote&

	std::cout << "ISBN: " << item.isbn() << " total due: " << item.net_price(10) << std::endl;
	std::cout << "ISBN: " << bulk.isbn() << " total due: " << bulk.net_price(10) << std::endl;
	std::cout << "ISBN: " << p->isbn() << " total due: " << p->net_price(9) << std::endl;
	std::cout << "ISBN: " << r.isbn() << " total due: " << r.net_price(10) << std::endl;

	//std::cout << "ISBN: " << pd->isbn() << " total due: " << pd->net_price(10) << std::endl;
	//std::cout << "ISBN: " << rd.isbn() << " total due: " << rd.net_price(30) << std::endl;

	// Test sliced down
	Bulk_quote bulk1("123-4-56-789012-1", 10.0, 10, 0.2);	// ojbect of derived type

	//Quote item1(bulk);
	Quote item1 = bulk;

	//std::cout << "ISBN: " << item1.isbn() << " total due: " << item1.net_price(10) << std::endl;


	return 0;
}
