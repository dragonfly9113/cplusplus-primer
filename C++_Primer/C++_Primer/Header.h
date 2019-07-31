#pragma once

// 15.5 Access Control and Inheritance: protected members
#if 0
class Base {
public:
	Base() = default;
	Base(int p) : prot_mem(p) {}

	virtual void print_mem(void) const { std::cout << "prot_mem: " << prot_mem << std::endl; }

	void set_mem(int mem) { prot_mem = mem; }

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

	void set_mem(int mem1, int mem2) { prot_mem = mem1; j = mem2; }

	//void set_base_mem(Base &b, int mem) { b.prot_mem = mem; }  // Error: cannot access protected member declared in class Base

	~Sneaky() = default;

private:
	friend void clobber(Sneaky&);
	//friend void clobber(Base&);
	int j;
};

void clobber(Sneaky &s) { s.j = s.prot_mem = 0; }

//void clobber(Base &b) { b.prot_mem = 0; }  // Error: cannot access protected member declared in class Base
#endif


// 15.5 Access Control and Inheritance: public, private, and protected inheritance
#if 0
class Base {
public:
	void pub_mem() {}
protected:
	int prot_mem;
private:
	char priv_mem;
};

struct Pub_Derv : public Base {
	int f() { return prot_mem; }     // OK: derived classes can access protected members inherited from base class.
	//char g() { return priv_mem; }    // Error: derived classes have no access to private members from base class.
};

struct Priv_Derv : private Base {
	int f1() const { return prot_mem; }   // OK: private derivation doesn't affect access in the derived class
};
#endif

// 15.6 Class Scope under Inheritance
#if 0
class Base {
public:
	virtual int fcn() {
		printf("Base::fcn() is called.\n");
		return 0;
	}
};

class D1 : public Base {
public:
	int fcn(int i) {
		printf("D1::fcn(int) is called: i = %d\n", i);
		return 0;
	}

	virtual void f2() {
		printf("D1::f2() is called.\n");
	}
};

class D2 : public D1 {
public:
	int fcn(int i) {
		printf("D2::fcn(int) is called: i = %d\n", i);
		return 0;
	}

	int fcn() {
		printf("D2::fcn() is called.\n");
		return 0;
	}

	void f2() {
		printf("D2::f2() is called.\n");
	}
};
#endif

// 15.7 Constructors and Copy Control
class B {
public:
	B() {
		printf("B::B() is called.\n");
	}

	B(const B&) = delete;
};

class D : public B {
	// no constructors
};
