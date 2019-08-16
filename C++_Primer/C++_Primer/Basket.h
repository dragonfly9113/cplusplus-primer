#pragma once
#include <memory>
#include <set>

#include "Quote.h"

class Basket
{
public:
	// Basket uses synthesized default constructor and copy-contorl members.

	void add_item(const std::shared_ptr<Quote> &sale)
	{
		items.insert(sale);
	}

	// Print the total price for each book and the overall total for all items in the basket
	double total_receipt(std::ostream&) const;

private:
	// function to compare shared_ptrs needed by the multiset member
	static bool compare(const std::shared_ptr<Quote> &lhs,
						const std::shared_ptr<Quote> &rhs)
	{
		return lhs->isbn() < rhs->isbn();
	}

	// multiset to hold multiple quotes, ordered by the compare member
	std::multiset<std::shared_ptr<Quote>, decltype(compare)*>
		items{compare};
};

