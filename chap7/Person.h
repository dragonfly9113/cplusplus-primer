#ifndef PERSON_H
#define PERSON_H
// Exercise 7.4, 7.5
struct Person {
	std::string getName() const { return name; }
	std::string getAddress() const { return address; }
	
	std::string name;
	std::string address;
};

// non-member function: read
std::istream &readp(std::istream &is, Person &person)
{
	getline(is, person.name);
	getline(is, person.address);
	return is;
}

// non-member function: print
std::ostream &printp(std::ostream &os, const Person &person)
{
	os << person.name << "\n" << person.address;
	return os;
}

#endif
