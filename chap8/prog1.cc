#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cassert>
#include "Sales_data.h"

using std::cin; using std::cout; using std::endl; using std::cerr;
using std::string; using std::vector; using std::begin; using std::end;
using std::runtime_error;
using std::initializer_list;
using std::istream; using std::ostream; using std::ifstream; using std::ofstream; 
using std::istringstream; using std::ostringstream;

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
	string str;
	
	ifstream input(ifile);	// create input and open the file
	if (input.fail()) {
		cerr << "couldn't open: " + ifile;
		return;
	}
	
	while (input) {
		getline(input, str);
		vec.push_back(str);
	}
}

int ex_8_4()
{
	vector<string> vec;
	string fileName("./book_sales");
	
	read_file(fileName, vec);
	
	cout << vec.size() << " lines are read:" << endl;
	for (auto e : vec)
		cout << e << endl;
	
	return 0;
}

// Exercise 8.5
void read_file_words(string ifile, vector<string> &vec)
{
	string word;
	
	ifstream input(ifile);	// create input and open the file
	if (input.fail()) {
		cerr << "couldn't open: " + ifile;
		return;
	}
	
	while (input >> word) {
		vec.push_back(word);
	}
}
 
int ex_8_5()
{
	vector<string> vec;
	string fileName("./book_sales");
	
	read_file_words(fileName, vec);
	
	cout << vec.size() << " words are read:" << endl;
	for (auto e : vec)
		cout << e << endl;
	
	return 0;
}

// Exercise 8.6
int ex_8_6(int argc, char *argv[])
{
	Sales_data total;
	
	if (argc == 1) {
		cout << "Usage: prog1 filename" << endl;
		return -1;
	}
	
	ifstream input(argv[1]);
	if (input.fail()) {
		cout << "couldn't open: " << argv[1] << endl;
		return -1;
	}
	
	// read in the first record and see if it is valid:
	if(read(input, total)) {
		Sales_data trans;
		
		// read in other records
		while(read(input, trans)) {
			if(trans.isbn() == total.isbn()) { // if this isbn is the same, update the total
				total.combine(trans);
			}
			else { 		// if this isbn is different, print out the last total and reset
				print(cout, total) << endl;
				total = trans;
			}
		}
		
		// print the last trans:
		print(cout, total) << endl;
	}
	else {
		cerr << "No data?!" << endl;
		return -1;
	}
	
	return 0;
}

// Exercise 8.7
int ex_8_7(int argc, char *argv[])
{
	Sales_data total;
	
	if (argc <= 2) {
		cout << "Usage: prog1 in_file out_file" << endl;
		return -1;
	}
	
	ifstream input(argv[1]);
	ofstream output(argv[2], ofstream::app);
	if (input.fail()) {
		cout << "couldn't open: " << argv[1] << endl;
		return -1;
	} else if (output.fail()) {
		cout << "couldn't open: " << argv[2] << endl;
		return -1;
	}
	
	// read in the first record and see if it is valid:
	if(read(input, total)) {
		Sales_data trans;
		
		// read in other records
		while(read(input, trans)) {
			if(trans.isbn() == total.isbn()) { // if this isbn is the same, update the total
				total.combine(trans);
			}
			else { 		// if this isbn is different, print out the last total and reset
				print(output, total) << endl;
				total = trans;
			}
		}
		
		// print the last trans:
		print(output, total) << endl;
	}
	else {
		cerr << "No data?!" << endl;
		return -1;
	}
	
	return 0;
}

// Exercise 8.9
// istream &print_stream(istream &);
int ex_8_9()
{
	string str("Hello World!");
	istringstream iss(str);
	
	print_stream(iss);
	
	return 0;
}

// Exercise 8.10
int ex_8_10()
{
	vector<string> vec;
	string fileName("./book_sales");
		
	read_file(fileName, vec);	// store each line from a file in a vector<string>
	
	//cout << vec.size() << " lines are read:" << endl;
	//for (auto e : vec)
	//	cout << e << endl;
	
	// Now use an istringstream to read each element from the vector a word at a time
	for (auto e : vec) {
		string word;
		istringstream iss(e);
		
		while (iss >> word) {
			cout << word << endl;
		}
	}
	
	return 0;
}

// Exercise 8.11
struct PersonInfo {
	string name;
	vector<string> phones;
};

ostream &print(ostream &os, PersonInfo &person)
{
	os << "name: " << person.name << endl;
	os << "phones: ";
	for (auto e : person.phones)
		os << e << " ";
	
	return os;
}

int ex_8_11()
{
	string line, word;
	vector<PersonInfo> people;
	istringstream record;
		
	while (getline(cin, line)) {
		PersonInfo info;
		record.clear();		// this action is necessary for record to be re-used.
		record.str(line);
		record >> info.name;
		while (record >> word)
			info.phones.push_back(word);
		people.push_back(info);
	}
	
	for (auto e : people)
		print(cout, e) << endl;
	
	return 0;
}

// Exercise 8.12
int main(int argc, char *argv[])
{
	string line, word;
	vector<PersonInfo> people;
	istringstream record;

	if (argc == 1) {
		cout << "Usage: prog1 input_file" << endl;
		return -1;
	}
	
	ifstream input(argv[1]);
	if (input.fail()) {
		cout << "couldn't open: " << argv[1] << endl;
		return -1;
	}
	
	while (getline(input, line)) {
		PersonInfo info;
		record.clear();		// this statement is necessary for record to be re-used.
		record.str(line);
		record >> info.name;
		while (record >> word)
			info.phones.push_back(word);
		people.push_back(info);
	}
	
	for (auto e : people)
		print(cout, e) << endl;
	
	return 0;
}

