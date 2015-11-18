#ifndef PERSON_H
#define PERSON_H
// Exercise 7.4, 7.5
class Person {
	// Exercise 7.19: add access specifiers
public:	
	// new constructors
	Person() = default;
	Person(const std::string &n, const std::string &a) : name(n), address(a) {}
	
	// member functions
	std::string getName() const { return name; }
	std::string getAddress() const { return address; }

	// Exercise 7.22: hide implementation
private:	
	std::string name;
	std::string address;
	
	// friend declarations so that these non-member functions can access private members
	friend std::istream &read(std::istream &, Person &);
	friend std::ostream &print(std::ostream &, const Person &);
};

// Exercise 7.43
class NoDefault {
public:
	NoDefault(int);
};

struct Class_C {
	// default constructor
	Class_C() {}
	
	//NoDefault c_mem;
};

// Exercise 7.53: define your own version of Debug
class Debug {
public:
	constexpr Debug(bool b = true): hw(b), io(b), other(b) {}
	constexpr Debug(bool h, bool i, bool o): 
									 hw(h), io(i), other(o) {}
	constexpr bool any() { return hw || io || other; }
	void set_io(bool b) { io = b; }
	void set_hw(bool b) { hw = b; }
	void set_other(bool b) { other = b; }

private:
	bool hw;
	bool io;
	bool other;
};

// Exercise 7.57: define your own Account class
class Account {
public:
	void calculate() { amount += amount * interestRate; }
	static double rate() { return interestRate; }
	static void rate(double);
private:
	std::string owner;
	double amount;
	static double interestRate;
	static double initRate();
};

// This definition of static data member interestRate is necessary:
double Account::interestRate = initRate();

void Account::rate(double newRate)
{
	interestRate = newRate;
}

double Account::initRate()
{
	double rate = 1.0;
	return rate;
}

// non-member function: read
std::istream &read(std::istream &is, Person &person)
{
	getline(is, person.name);
	getline(is, person.address);
	return is;
}

// non-member function: print
std::ostream &print(std::ostream &os, const Person &person)
{
	os << person.name << "\t" << person.address;
	return os;
}

#endif
