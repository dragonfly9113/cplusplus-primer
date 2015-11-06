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

private:	
	std::string name;
	std::string address;
};

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
