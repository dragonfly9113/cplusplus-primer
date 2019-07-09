#ifndef SCREEN_H
#define SCREEN_H

// Exercise 7.32: define class Window_mgr - this has to come before class Screen because class Screen will declare
// one of its member function as a friend.
class Screen;	// forwared declaration of class Screen
class Window_mgr {
public:
	// Location ID for each screen on the window
	using ScreenIndex = std::vector<Screen>::size_type;
	// reset the Screen at the given position to all blanks
	void clear(ScreenIndex);
	// add a Screen to the window and returns its index
	ScreenIndex addScreen(const Screen &);
	
private:
	// TO-DO: cannot initialize screens with one object of Screen because Screen is still an incomplete type here.
	//std::vector<Screen> screens{Screen(24, 80, ' ')};
	std::vector<Screen> screens;
};

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
	
	pos size() const;
private:	
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
	
	// use private utility functions for common code: since defined in class, will be implicitly inline
	void do_display(std::ostream &os) const { os << contents; }
	
	friend std::ostream &print(std::ostream &, const Screen &);
	friend void Window_mgr::clear(ScreenIndex);
};

// Exercise 7.35
typedef std::string Type;
Type initVal();
class Exercise {
public:
	typedef double Type;
	Type setVal(Type);
	Type initVal();
private:
	int val;
};

Exercise::Type Exercise::setVal(Type parm) {
	val = parm + initVal();
	return val;
}

Exercise::Type Exercise::initVal() {
	val = 0;
	return val;
}

void Window_mgr::clear(ScreenIndex i)
{
	// s is a reference to the Screen we want to clear
	Screen &s = screens[i];
	// reset the contents of the Screen to all blanks
	s.contents = std::string(s.height * s.width, ' ');
}

Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s)
{
	screens.push_back(s);
	return screens.size() - 1;
}

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

// Exercise 7.33
Screen::pos Screen::size() const
{
	return height * width;
}

// non-member function: print
std::ostream &print(std::ostream &os, const Screen &screen)
{
	os << screen.cursor << " " << screen.height << " " << screen.width << " " << screen.contents;
	return os;
}

#endif
