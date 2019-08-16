#pragma once
#include <iostream>
#include <string>

#include "Quote.h"

// Calculate and print the price for the given number of copies, applying any discounts
double print_total(std::ostream &os, const Quote &item, size_t n)
{
	// depending on the type of object bound to the item parameter
	// calls either Quote::net_price or Bulk_quote::net_price
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;

	return ret;
}
