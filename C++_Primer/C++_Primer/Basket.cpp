#include "pch.h"
#include "Basket.h"
#include "Utility.h"

double Basket::total_receipt(std::ostream &os) const
{
	double sum = 0.0;

	// iter refers to the first element in a batch of elements with the same ISBN
	// upper_bound returns an iterator to the element just past the end of that batch
	for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter)) {
		// we know there is at least one element with this key in the Basket
		// print the line item for this book
		sum += print_total(os, **iter, items.count(*iter));
	}
	os << "Total Sale: " << sum << std::endl;

	return sum;
}
