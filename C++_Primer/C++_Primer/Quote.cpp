#include "pch.h"
#include "Quote.h"


Quote::Quote()
{
}

std::string Quote::isbn() const
{
	return std::string();
}

double Quote::net_price(std::size_t n) const
{
	return 0.0;
}


Quote::~Quote()
{
}

Bulk_quote::Bulk_quote()
{
}

double Bulk_quote::net_price(std::size_t n) const
{
	return 0.0;
}

Bulk_quote::~Bulk_quote()
{
}
