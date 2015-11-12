#ifndef SCREEN_H
#define SCREEN_H
// Exercise 7.23
class Screen {
public:	
	//typedef std::string::size_type pos;
	using pos = std::string::size_type;
	
	// constructors
	Screen() = default;
	Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}
	
	// Exercise 7.27: add move, set and display functions, etc.
	char get() const { return contents[cursor]; }		// implicitly inline
	inline char get(pos row, pos col) const;			// explicityly inline 
	
	Screen &move(pos row, pos col);
	Screen &set(char c);
	Screen &set(pos row, pos col, char c);
	
	// display overloaded on whether the object is const or not
	Screen &display(std::ostream &os) { os << "non-const version: "; do_display(os); return *this; }
	const Screen &display(std::ostream &os) const { os << "const version: "; do_display(os); return *this; }
	
private:	
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
	
	// use private utility functions for common code: since defined in class, will be implicitly inline
	void do_display(std::ostream &os) const { os << contents; }
	
	friend std::ostream &print(std::ostream &, const Screen &);
};

// already declared as inline in the class.
char Screen::get(pos row, pos col) const
{
	return contents[row * width + col];
}

inline Screen &Screen::move(pos row, pos col)
{
	cursor = row * width + col;
	return *this;
}

inline Screen &Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}

inline Screen &Screen::set(pos row, pos col, char c)
{
	contents[row * width + col] = c;
	return *this;
}

// non-member function: print
std::ostream &print(std::ostream &os, const Screen &screen)
{
	os << screen.cursor << " " << screen.height << " " << screen.width << " " << screen.contents;
	return os;
}

#endif
