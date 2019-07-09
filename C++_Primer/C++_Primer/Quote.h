#pragma once

#include <iostream>

// Chap 15. Object Oriented Programming
class Quote
{
public:
	Quote() = default;
	Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) {}

	std::string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n) const;

	static void statmem() {}

	virtual ~Quote() = default;

private:
	std::string bookNo;   // ISBN number of this item

protected:
	double price = 0.0;   // Normal, undiscounted price
};
