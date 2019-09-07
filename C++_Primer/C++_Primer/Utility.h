#pragma once
#include <iostream>
#include <string>

#include "Quote.h"
#include "QueryResult.h"

// Calculate and print the price for the given number of copies, applying any discounts
double print_total(std::ostream &os, const Quote &item, size_t n)
{
	// depending on the type of object bound to the item parameter
	// calls either Quote::net_price or Bulk_quote::net_price
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;

	return ret;
}

std::ostream& print(std::ostream& os, const QueryResult& qr)
{
	// if the word was found, print the count and all occurences
	os << qr.sought << " occurs " << qr.lines->size() << " "
		<< make_plural(qr.lines->size(), "time", "s") << std::endl;

	// print each line in which the word appeared
	for (auto num : *qr.lines) // for every element in the set
		os << "\t(line " << num + 1 << ") "
		<< *(qr.file->begin() + num) << std::endl;

	return os;
}

std::string make_plural(size_t ctr, const std::string& word, const std::string& ending)
{
	return (ctr > 1) ? word + ending : word;
}
