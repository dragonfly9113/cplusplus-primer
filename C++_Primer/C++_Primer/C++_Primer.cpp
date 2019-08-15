// C++_Primer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "Bulk_quote.h"
#include "Header.h"

#if 0
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
#endif

#if 0
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
#endif

#if 0
int main()
{
	Pub_Derv d1;
	Priv_Derv d2;
	d1.f();
	d1.pub_mem();

	d2.f1();
	//d2.pub_mem();  // Error: pub_mem is private in the derived class.

	return 0;
}
#endif

#if 0
int main()
{
	Bulk_quote bulk;
	Bulk_quote *bulkP = &bulk;
	Quote *itemP = &bulk;
	bulkP->discount_policy();
	//itemP->discount_policy(); // Error: there is no member discount_policy() in Quote class.

	Base bobj; D1 d1obj; D2 d2obj;
	Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
	bp1->fcn();  // virtual call, Base::fcn() is called.
	bp2->fcn();  // virtual call, Base::fcn() is called.
	bp3->fcn();  // virtual call, D2::fcn() is called.

	D1 *d1p = &d1obj; D2 *d2p = &d2obj;
	//bp2->f2(); // Error: Base has no member named f2.
	d1p->f2();   // Virtual call, D1::f2() is called.
	d2p->f2();   // Virtual Call, D2::f2() is called.

	Base *p1 = &d2obj; D1 *p2 = &d2obj; D2 *p3 = &d2obj;
	//p1->fcn(42);  // Error: Base has no version of fcn that takes an int.
	p2->fcn(42);  // statically bound, calls D1::fcn(int)
	p3->fcn(42);  // statically bound, calls D2::fcn(int)

	return 0;
}
#endif

// 15.7 Constructors and Copy Control
#if 0
int main()
{
	Quote *itemP = new Quote;  // same static and dynamic type
	delete itemP;   // destructor for Quote called

	//itemP = new Bulk_quote;  // static and dynamic type differ
	itemP = new Bulk_quote("01-1234", 10.99, 10, 0.1);
	delete itemP;   // destructor for Bulk_quote called

	return 0;
}
#endif
#if 0
int main()
{
	D d;
	//D d2(d);
	//D d3(std::move(d));
	return 0;
}
#endif

#if 0
int main()
{
	Quote q1("1234-56", 9.99);
	std::cout << "Before move, q1.isbn = " << q1.isbn() << std::endl;
	//std::cout << "Before move, q2.isbn = " << q2.isbn() << std::endl;
	//q2 = std::move(q1);
	Quote q2(std::move(q1));
	std::cout << "After move, q1.isbn = " << q1.isbn() << std::endl;
	std::cout << "After move, q2.isbn = " << q2.isbn() << std::endl;

	Bulk_quote b1("3245-1234", 7.99, 10, 0.2);
	std::cout << "Before move, b1." << b1.isbn() << std::endl;
	//Bulk_quote b2(std::move(b1));
	Bulk_quote b2 = std::move(b1);
	std::cout << "After move, b1." << b1.isbn() << std::endl;
	std::cout << "After move, b2." << b2.isbn() << std::endl;

	return 0;
}
#endif

// 15.7.3 Derived-class copy-control members
#if 0
int main()
{
	Base b1 = Base();
	Base b2(100);
	std::cout << "b1.base_mem = " << b1.base_mem << " b2.base_mem = " << b2.base_mem << std::endl;

	//D d1 = D();
	D d2(100, 200);
	D d1(d2);

	std::cout << "d1.base_mem = " << d1.base_mem << " d1.d_mem = " << d1.d_mem << std::endl;
	std::cout << "d2.base_mem = " << d2.base_mem << " d2.d_mem = " << d2.d_mem << std::endl;

	D d3;
	d3 = d2;
	std::cout << "d3.base_mem = " << d3.base_mem << " d3.d_mem = " << d3.d_mem << std::endl;

	return 0;
}
#endif

// 15.8 Containers and Inheritance
int main()
{
	//Quote item("978-3-16-148410-0", 9.99);			// object of base type
	//Bulk_quote bulk("123-4-56-789012-1", 11.99, 10, 0.2);	// ojbect of derived type

	/*
	std::vector<Quote> basket;
	basket.push_back(Quote("0-201-82470-1", 50));
	basket.push_back(Bulk_quote("0-201-54848-8", 50, 10, .25));
	std::cout << basket.back().net_price(15) << std::endl;
	*/

	/*
	std::vector<Quote*> basket;
	//Quote* quote = new Quote("0-201-82470-1", 50);
	//Bulk_quote* bulk = new Bulk_quote("0-201-54848-8", 50, 10, .25);
	Quote quote = Quote("0-201-82470-1", 50);
	Bulk_quote bulk = Bulk_quote("0-201-54848-8", 50, 10, .25);
	basket.push_back(&quote);
	basket.push_back(&bulk);
	std::cout << basket.back()->isbn() << std::endl;
	std::cout << basket.back()->net_price(15) << std::endl;
	*/

	std::vector<std::shared_ptr<Quote>> basket;
	basket.push_back(std::make_shared<Quote>("0-201-82470-1", 50));
	basket.push_back(std::make_shared<Bulk_quote>("0-201-54848-8", 50, 10, .25));
	std::cout << basket.back()->isbn() << std::endl;
	std::cout << basket.back()->net_price(15) << std::endl;

	return 0;
}