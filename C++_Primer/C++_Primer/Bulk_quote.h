#pragma once

#include "Quote.h"

// Chap 15. Object Oriented Programming
class Bulk_quote : public Quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string& book, double sales_price, std::size_t min_qty, double discount) :
 		Quote(book, sales_price), min_qty(min_qty), discount(discount) {}

	double net_price(std::size_t n) const override;

	void f(const Bulk_quote&);

	~Bulk_quote() = default;

private:
	std::size_t min_qty = 0;   // minimum purchase for the discount to apply
	double discount = 0.0;     // fractional discount to apply
};

