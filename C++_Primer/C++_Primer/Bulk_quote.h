#pragma once

#include "Disc_quote.h"

// Chap 15. Object Oriented Programming
class Bulk_quote : public Disc_quote
{
public:
	Bulk_quote() {
		printf("Bulk_quote default constructor is called.\n");
	}

	Bulk_quote(const std::string& book, double sales_price, std::size_t min_qty, double discount) :
		Disc_quote(book, sales_price, min_qty, discount) {}

	double net_price(std::size_t n) const override;

	void f(const Bulk_quote&);

	~Bulk_quote() {
		printf("Bulk_quote destructor is called.\n");
	}
};

