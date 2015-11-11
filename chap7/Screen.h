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
	
private:	
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
	
	friend std::ostream &print(std::ostream &, const Screen &);
};

// non-member function: print
std::ostream &print(std::ostream &os, const Screen &screen)
{
	os << screen.cursor << " " << screen.height << " " << screen.width << " " << screen.contents;
	return os;
}

#endif
