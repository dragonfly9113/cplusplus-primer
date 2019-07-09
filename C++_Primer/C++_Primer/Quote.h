#pragma once

#include <iostream>

class Quote
{
public:
	Quote();

	std::string isbn() const;
	virtual double net_price(std::size_t n) const;

	virtual ~Quote();
};

class Bulk_quote : public Quote
{
public:
	Bulk_quote();

	double net_price(std::size_t n) const override;


	~Bulk_quote();
};