#ifndef SALES_DATA_H
#define SALES_DATA_H

// Exercise 7.12: declare these two here in order for constructor Sales_data(std::istream &is) to use non-member function read()
// inside Sales_data class body.
struct Sales_data;
std::istream &read(std::istream &, Sales_data &);

// Exercise 7.2
struct Sales_data {
	// Exercise 7.11
	// new constructors:
	Sales_data() = default;
	Sales_data(const std::string &s) : bookNo(s) {}
	Sales_data(const std::string &s, unsigned u, double p) : bookNo(s), units_sold(u), revenue(u*p) {}
	//Sales_data(std::istream &);	
	// Exercise 7.12: move the definition of this constructor into the class body
	Sales_data(std::istream &is)
	{
		read(is, *this);
	}
	
	// new members:
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const;
	
	// data members are unchanged from sec2.6.1
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

// member function combine()
Sales_data& Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;	// return the object on which this function was called.
}

// member function avg_price()
double Sales_data::avg_price() const
{
	return (units_sold == 0) ? 0 : revenue / units_sold;
}

// Exercise 7.6
// add is non-member function
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

// read is non-member function
std::istream &read(std::istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = item.units_sold * price;
	return is;
}

// print is non-member function
std::ostream &print(std::ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}

// Exercise 7.11
// Constructor Sales_data(std::istream &) is defined out of class body:
//Sales_data::Sales_data(std::istream &is)
//{
//	read(is, *this);
//}

#endif
