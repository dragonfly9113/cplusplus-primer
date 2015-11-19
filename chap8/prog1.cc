#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cassert>

using std::cin; using std::cout; using std::endl; using std::cerr;
using std::istream; using std::ostream;
using std::string; using std::vector; using std::begin; using std::end;
using std::runtime_error;
using std::initializer_list;

#define NDEBUG

// Exercise 8.1
istream &print_stream(istream &is)
{
	char c;
	
	while (!is.eof()) {
		is >> c;
		cout << c;
	}
	
	is.clear();
	return is;
}

// Exercise 8.2
int ex_8_2()
{
	print_stream(cin);
	
	return 0;
}

// Exercise 8.4
void read_file(string ifile, vector<string> &vec)
{
	decltype(vec.size()) i = 0;
	
	ifstream input(ifile);	// create input and open the file
	if (input) {
		getline(input, vec[i++]);
	}
}

int main()
{
	vector<string> vec;
	string fileName("./sales_data.txt");
	
	read_file(fileName, vec);
	
	for (auto e : vec)
		cout << e << endl;
	
	return 0;
}
