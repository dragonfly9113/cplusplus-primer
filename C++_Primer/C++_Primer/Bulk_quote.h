#pragma once

#include "Disc_quote.h"

// Chap 15. Object Oriented Programming
class Bulk_quote : public Disc_quote
{
public:
	Bulk_quote() {
		printf("Bulk_quote default constructor is called.\n");
	}

	using Disc_quote::Disc_quote;  // Do the same thing as below, but in a much simpler way.
/*
	Bulk_quote(const std::string& book, double sales_price, std::size_t min_qty, double discount) :
		Disc_quote(book, sales_price, min_qty, discount) {
		printf("Bulk_quote(book, price, qty, discount) is called.\n");
	}
*/

	Bulk_quote(const Bulk_quote&) = default;
	Bulk_quote(Bulk_quote&&) = default;
	Bulk_quote& operator=(const Bulk_quote&) = default; // copy assign
	Bulk_quote& operator=(Bulk_quote&&) = default; // move assign

	double net_price(std::size_t n) const override;

	void f(const Bulk_quote&);

	~Bulk_quote() {
		printf("Bulk_quote destructor is called.\n");
	}
};

