#pragma once
#include "Quote.h"


class Disc_quote : public Quote
{
public:
	Disc_quote() {
		printf("Disc_quote default constructor is called.\n");
	}

	Disc_quote(const std::string& book, double price, std::size_t qty, double disc) :
		Quote(book, price), quantity(qty), discount(disc) {}

	double net_price(std::size_t) const = 0;   // pure virtual function

	std::pair<size_t, double> discount_policy() const
	{
		return { quantity, discount };
	}

	~Disc_quote() {
		printf("Disc_quote destructor is called.\n");
	}

protected:
	std::size_t quantity = 0;
	double discount = 0.0;
};

