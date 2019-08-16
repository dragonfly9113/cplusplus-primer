#pragma once

#include <iostream>

// Chap 15. Object Oriented Programming
class Quote
{
public:
	Quote() {
		//printf("Quote default constructor is called.\n");
	}

	Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) {
		//printf("Quote(book, price) is called.\n");
	}

	Quote(const Quote&) = default;  // memberwise copy
	Quote(Quote&&) = default; // memberwise move
	Quote& operator=(const Quote&) = default;   // copy assign
	Quote& operator=(Quote&&) = default;  // move assign

	std::string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n) const;

	// virtual functions to return a dynamically allocated copy of itself
	// these members use reference qualifier
	virtual Quote* clone() const & { return new Quote(*this); }
	virtual Quote* clone() && { return new Quote(std::move(*this)); }

	static void statmem() {}

	virtual ~Quote() {
		//printf("Quote descructor is called.\n");
	}

private:
	std::string bookNo;   // ISBN number of this item

protected:
	double price = 0.0;   // Normal, undiscounted price
};
