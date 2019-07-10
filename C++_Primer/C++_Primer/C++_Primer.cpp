// C++_Primer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>>

#include "Bulk_quote.h"
#include "Header.h"

int main_quote();

int main_quote()
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

int main()
{
	Base base(10);
	Sneaky sneaky(20, 30);

	Base *pb = &base;
	Sneaky *ps = &sneaky;

	Base &rb = base;
	Sneaky &rs = sneaky;

	//pb->print_mem();
	//ps->print_mem();
	rb.print_mem();
	rs.print_mem();
	std::cout << "Try to change objects:" << std::endl;

	//base.set_mem(15);
	//base.print_mem();
	//pb->set_mem(15);
	//pb->print_mem();
	rb.set_mem(15);
	rb.print_mem();

	//sneaky.set_mem(25, 35);
	//sneaky.print_mem();
	//ps->set_mem(25, 35);
	//ps->print_mem();
	rs.set_mem(25, 35);
	rs.print_mem();

	std::cout << "Try to change Sneaky object by using clobber()" << std::endl;
	clobber(sneaky);
	sneaky.print_mem();


	return 0;
}