#include "pch.h"
#include "Quote.h"

double Quote::net_price(std::size_t n) const
{
	std::cout << "net_price: Quote version" << std::endl;
	return n * price;
}
