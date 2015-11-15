#ifndef SALES_DATA_H
#define SALES_DATA_H

// Exercise 7.12: declare these two here in order for constructor Sales_data(std::istream &is) to use non-member function read()
// inside Sales_data class body.
//struct Sales_data;
//std::istream &read(std::istream &, Sales_data &);

// Exercise 7.2
class Sales_data {
	// Exercise 7.11
	// new constructors:
	// Exercise 7.14: write a default constructor that explicitly initialize the members to the values we have provided as in-class initializers
	//Sales_data() : units_sold(0), revenue(0) {}	
public:	
	Sales_data() = default;
	Sales_data(const std::string &s) : bookNo(s) {}
	Sales_data(const std::string &s, unsigned u, double p) : bookNo(s), units_sold(u), revenue(u*p) {}
	Sales_data(std::istream &);	
	// Exercise 7.12: move the definition of this constructor into the class body
	//Sales_data(std::istream &is)
	//{
	//	read(is, *this);
	//}
	
	// new members:
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	
	// Exercise 7.21: hide implementation
private:	
	double avg_price() const;
	// data members are unchanged from sec2.6.1
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	
	// friend declarations
	friend Sales_data add(const Sales_data &, const Sales_data &);
	friend std::istream &read(std::istream &, Sales_data &);
	friend std::ostream &print(std::ostream &, const Sales_data &);
};

// Exercise 7.38
class Sales_data_738 {
public:	
	// defines the default constructor as well as one that takes a string argument
	Sales_data_738(std::string s = "") : bookNo(s) {}
	// use cin as a default argument 
	Sales_data_738(std::istream &is = std::cin);
	// this constructor is as before
	Sales_data_738(const std::string &s, unsigned u, double p) : bookNo(s), units_sold(u), revenue(u*p) {}

private:	
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
}; 

// Exercise 7.41
// some necessary forwared declarations
class Sales_data_741;
std::istream &read(std::istream &, Sales_data_741 &);
class Sales_data_741 {
public:	
	Sales_data_741(const std::string &s, unsigned u, double p) : bookNo(s), units_sold(u), revenue(u*p) 
		{ std::cout << "body of 3-argument constructor" << std::endl; }
	// delegating constructors
	Sales_data_741() : Sales_data_741("", 0, 0) 
		{ std::cout << "body of default constructor" << std::endl; }
	Sales_data_741(std::string s) : Sales_data_741(s, 0, 0) 
		{ std::cout << "body of string-argument constructor" << std::endl; }
	Sales_data_741(std::istream &is) : Sales_data_741() {
		std::cout << "body of istream-argument constructor" << std::endl;
		read(is, *this); }

	std::string isbn() const { return bookNo; }
	
private:	
	double avg_price() const;
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;

	// friend declarations
	friend std::istream &read(std::istream &, Sales_data_741 &);
	friend std::ostream &print(std::ostream &, const Sales_data_741 &);	
}; 

// Exercise 7.49
class Sales_data_749 {
public:	
	Sales_data_749() = default;
	Sales_data_749(const std::string &s) : bookNo(s) {}
	Sales_data_749(const std::string &s, unsigned u, double p) : bookNo(s), units_sold(u), revenue(u*p) {}
	Sales_data_749(std::istream &);	
	
	Sales_data_749 &combine(const Sales_data_749&);
	
private:	
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	
	friend std::ostream &print(std::ostream &, const Sales_data_749 &);	
};

Sales_data_749& Sales_data_749::combine(const Sales_data_749 &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;	// return the object on which this function was called.
}

std::ostream &print(std::ostream &os, const Sales_data_749 &item)
{
	os << item.bookNo << " " << item.units_sold << " " << item.revenue;
	return os;
}

// Exercise 7.40
class Employee {
public:	
	// This constructor takes nothing or one string argument, it can also serve as default constructor
	//Employee(std::string n = "") : name(n) {}
	// A constructor to take name, workNo and title
	//Employee(const std::string &n, const std::string &w, const std::string &t) : name(n), workNo(w), title(t) {}
	// A constructor to ininitalize all members
	Employee(const std::string &n, const std::string &w, const std::string &t, unsigned l, double s)
		: name(n), workNo(w), title(t), level(l), salary(s) 
		{ std::cout << "body of 5-argument constructor" << std::endl; }
	
	// Exercise 7.42 : use delegating constructors
	Employee() : Employee("", "", "", 0, 0.0) 
		{ std::cout << "body of default constructor" << std::endl; }
		
	Employee(const std::string &n, const std::string &w, const std::string &t) : Employee(n, w, t, 0, 0.0)
		{ std::cout << "body of 3-argument constructor" << std::endl; }
	
private:
	std::string name;	// employee's full name
	std::string workNo; // employee's unique ID in company
	std::string title;	// formal title
	unsigned level;		// job level
	double 	 salary;	// annual salary
};

// member function combine()
Sales_data& Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;	// return the object on which this function was called.
}

// member function avg_price()
inline double Sales_data::avg_price() const
{
	return (units_sold == 0) ? 0 : revenue / units_sold;
}

inline double Sales_data_741::avg_price() const
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

std::istream &read(std::istream &is, Sales_data_741 &item)
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

std::ostream &print(std::ostream &os, const Sales_data_741 &item)
{
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}

// Exercise 7.11
// Constructor Sales_data(std::istream &) is defined out of class body:
Sales_data::Sales_data(std::istream &is)
{
	read(is, *this);
}

#endif
