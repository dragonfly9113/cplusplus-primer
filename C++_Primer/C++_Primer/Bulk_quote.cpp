#include "pch.h"
#include "Bulk_quote.h"

double Bulk_quote::net_price(std::size_t n) const
{
	//std::cout << "net_price: Bulk_quote version" << std::endl;
	if (n >= quantity)
		return n * (1 - discount) * price;
	else
		return n * price;
}

void Bulk_quote::f(const Bulk_quote &bulk)
{
	Quote::statmem();			//ok: base class defines statmem
	Bulk_quote::statmem();		//ok: derived class inherits statmem
	bulk.statmem();				//ok: derived objects can be used to access static from base
	statmem();					//ok: accessed through this object
}