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

// Exercise 9.14
int ex_9_14()
{
	list<const char*> lst{"hello", "world", "good", "morning!"};
	vector<string> vec;
	
	// assignment operator requires left-hand and right-hand container have same type
	//vec = lst;

	// swap() also requires left-hand and right-hand container have same type
	//swap(vec, lst);
	
	vec.assign(lst.begin(), lst.end());

	for (auto e : vec)
		cout << e << " ";
	
	return 0;
}

// Exercise 9.15
int ex_9_15()
{
	vector<int> vec1{1, 3, 5, 7, 9};
	vector<int> vec2{1, 3, 5, 8, 9};
	
	if (vec1 == vec2)
		cout << "equal!" << endl;
	else if (vec1 < vec2)
		cout << "vec1 < vec2" << endl;
	else
		cout << "vec2 > vec1" << endl;
	
	return 0;
}

// Exercise 9.16
int ex_9_16()
{
	list<int> lst1{1, 3};
	list<int> lst2{1, 3, 4};
	vector<int> vec{1, 3, 5};
	
	// Operator == requires both operands must be the same kind of container and must hold the same type of elements.
	//if (lst == vec)
	//	cout << "equal!" << endl;
	
	if (lst1 < lst2)
		cout << "lst1 < lst2" << endl;
	
	return 0;
}

// Exercise 9.18
int ex_9_18()
{
	string word;
	deque<string> sdeq;
	
	cout << "Enter a sequence of stringS: " << endl;
	while (cin >> word)
		sdeq.push_back(word);
	
	for (auto it = sdeq.begin(); it != sdeq.end(); ++it)
		cout << *it << endl;
	
	return 0;
}

// Exercise 9.19
int ex_9_19()
{
	string word;
	list<string> slst;
	
	cout << "Enter a sequence of stringS: " << endl;
	while (cin >> word)
		slst.push_back(word);
	
	for (auto it = slst.begin(); it != slst.end(); ++it)
		cout << *it << endl;
	
	return 0;	
}

// Exercise 9.20
int ex_9_20()
{
	list<int> ilst{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	deque<int> even_deq, odd_deq;
	
	for (auto it = ilst.begin(); it != ilst.end(); ++it)
	{
		if (*it % 2 == 0)
			even_deq.push_back(*it);
		else
			odd_deq.push_back(*it);
	}

	cout << "even_deq: ";
	for (auto e : even_deq)
		cout << e << " ";
	cout << endl;
	cout << "odd_deq: ";
	for (auto e : odd_deq)
		cout << e << " ";
	
	return 0;
}

// Exercise 9.21
int ex_9_21()
{
	string word;
	vector<string> vec;
	
	auto iter = vec.begin();
	while (cin >> word)
		iter = vec.insert(iter, word);

	for (auto e : vec)
		cout << e << endl;
		
	return 0;
}

// Exercise 9.22
int main()
{
	vector<int> iv{1, 3, 5, 7, 9};
	int some_val = 1;
	
	auto iter = iv.begin(),
		 mid = iv.begin() + iv.size()/2;
	
	while (iter != mid) {
		if (*iter == some_val) {
			iter = iv.insert(iter, 2 * some_val);
			++iter;
		}
		++iter;
	}
	
	for (auto e : iv)
		cout << e << endl;
	
	return 0;
}

