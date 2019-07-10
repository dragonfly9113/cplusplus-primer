#pragma once

// 15.5 Access Control and Inheritance
class Base {
public:
	Base() = default;
	Base(int p) : prot_mem(p) {}

	virtual void print_mem(void) const { std::cout << "prot_mem: " << prot_mem << std::endl; }

	virtual ~Base() = default;

protected:
	int prot_mem;
};

class Sneaky : public Base {
public:
	Sneaky() = default;
	Sneaky(int p, int j) :
		Base(p), j(j) {}

	void print_mem(void) const override { std::cout << "prot_mem: " << prot_mem << " j: " << j << std::endl; }

	~Sneaky() = default;

private:
	friend void clobber(Sneaky&);
	friend void clobber(Base&);
	int j;
};

void clobber(Sneaky &s) { s.j = s.prot_mem = 0; }

//void clobber(Base &b) { b.prot_mem = 0; }