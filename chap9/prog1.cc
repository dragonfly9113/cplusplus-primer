#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <stdexcept>
#include <cassert>
#include "Sales_data.h"

using std::cin; using std::cout; using std::endl; using std::cerr;
using std::string; using std::vector; using std::list; using std::deque;
using std::begin; using std::end;
using std::runtime_error;
using std::initializer_list;
using std::istream; using std::ostream; using std::ifstream; using std::ofstream; 
using std::istringstream; using std::ostringstream;

#define NDEBUG
class Person {
public:
	Person(string n, string p): name(n), phones(p) {}
	
private:
	string name;
	string phones;
};

// Exercise 9.2
int ex_9_2()
{
	// define a list that holds elements that are dequeS that holds intS.
	list<deque<int>> li;
	
	// the following statement will not compile because initializing a vector of Person by a size requires 
	// default constructor of Person. In this class Person, a default constructor is not available.
	//vector<Person> people(5);
	
	return 0;
}

// Exercise 9.4
bool isValueInRange(vector<int>::const_iterator begin, vector<int>::const_iterator end, int value)
{
	bool result = false;
	
	while (begin != end)
	{
		if (*begin == value) {
			result = true;
			break;
		}
		++begin;
	}
	
	return result;
}

int ex_9_4()
{
	int i;
	vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	auto iter1 = vec.cbegin(),
		 iter2 = vec.cend();

	iter1 += 3;		// range: [4, 8)
	iter2 -= 3;
						  
	cout << "Enter an integer: ";
	while (cin >> i) {
		cout << (isValueInRange(iter1, iter2, i) ? "true" : "false") << endl;
		cout << "Enter an integer: ";
	}
	
	return 0;
}

// Exercise 9.5: rewrite the previous function to return an iterator
vector<int>::const_iterator isValueInRange_1(vector<int>::const_iterator begin, vector<int>::const_iterator end, int value)
{
	while (begin != end)
	{
		if (*begin == value)
			break;

		++begin;
	}
	
	return begin;
}

int ex_9_5()
{
	int i;
	vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	auto iter1 = vec.cbegin(),
		 iter2 = vec.cend();

	iter1 += 3;		// range: [4, 8)
	iter2 -= 3;
						  
	cout << "Enter an integer: ";
	while (cin >> i) {
		auto iter = isValueInRange_1(iter1, iter2, i);
		if ( iter != iter2)
			cout << "match found at range position: " << (iter - iter1) << endl;
		else
			cout << "no match found!" << endl;
		
		cout << "Enter an integer: ";
	}
	
	return 0;
}

// Exercise 9.6
int ex_9_6()
{
	list<int> lst1;
	list<int>::iterator iter1 = lst1.begin(),
						iter2 = lst1.end();
		
	//while (iter1 < iter2)
	while (iter1 != iter2) {
		// do something;
	}
	
	return 0;
}

// Exercise 9.11
void print_vec(vector<int> v)
{
	for (const auto e : v)
		cout << e << " ";
	cout << endl;
}

int ex_9_11()
{
	vector<int> vec{1, 2, 3};	// list initialized. vec has 3 integer elements with value 1, 2 and 3.	
	vector<int> vec1(vec);		// copy initialized. vec1 holds the same elements as vec.
	vector<int> vec2(vec.begin(), vec.end());	// range initialized. vec2 holds the same elements as vec.
	vector<int> vec3(3);		// size initialized. vec3 has 3 elements, each of which is value initialized to 0.
	vector<int> vec4(3, -1);	// size initialized. vec4 has 3 elements, each of which has value -1.
	vector<int> vec5;			// default constructor. vec5 is empty.

	cout << "vec: ";
	print_vec(vec);
	cout << "vec1: ";
	print_vec(vec1);
	cout << "vec2: ";
	print_vec(vec2);
	cout << "vec3: ";
	print_vec(vec3);
	cout << "vec4: ";
	print_vec(vec4);
	cout << "vec5: ";
	print_vec(vec5);
	
	return 0;
}

// Exercise 9.13
int ex_9_13()
{
	list<int> lst{11, 22, 33, 44, 55};
	vector<int> vec{12, 23, 34, 45, 56};

	// cannot copy initialize like below because either container type or element type doesn't match.
	//vector<double> vecd(lst);
	//vector<double> vecd(vec);
	
	// copy initialing using a range is OK
	//vector<double> vecd(lst.begin(), lst.end());
	vector<double> vecd(vec.begin(), vec.end());
	
	for (auto e : vecd)
		cout << e << " ";
	
	return 0;
}


