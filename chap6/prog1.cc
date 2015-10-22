#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Chapter6.h"

using std::cin; using std::cout; using std::endl; using std::cerr;
using std::string; using std::vector; using std::begin; using std::end;
using std::runtime_error;

// Exercise 6.2
int f2(int i) 
{
	return i;
}

double square(double x) 
{
	return x * x;
}

// Exercise 6.3, 6.4
int fact()
{
	int val;
	int ret = 1;

	cout << "Enter an integer: " << endl;
	cin >> val;
	
	while (val >= 1)
		ret *= val--;

	return ret;
}

// Exercise 6.5
int abs_value(int val)
{
	int ret;
	
	if (val >= 0)
		ret = val;
	else
		ret = -val;
	
	return ret;
}

// Exercise 6.7
int seq_num()
{
	// seq will not be reinitialized to 0 everytime seq_num() gets called. seq is a local static variable and is
	// initialized before the first time execution passes through the object's definition.
	// it is not destroyed when the function ends; it is destroyed when the program terminates.
	static size_t seq = 0;
	return seq++;
}

// Exercise 6.10
void swap_value(int *p1, int *p2)
{
	int temp;
	
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

// Exercise 6.11
void reset(int &ival)
{
	ival = 0;
}

// Exercise 6.12
void swap_value_v2(int &i1, int &i2)
{
	int temp;

	temp = i1;
	i1 = i2;
	i2 = temp;
}

// Exercise 6.17
bool has_capital_letters(const string &s)
{
	bool ret = false;
	
	for (auto c : s)
		if (isupper(c)) {
			ret = true;
			break;
		}

	return ret;
}

void to_lowercase(string &s)
{
	for (auto &c : s)
		c = tolower(c);
}

// Exercise 6.21
int larger_int(int i1, const int *pi2)
{
	return (i1 > *pi2) ? i1 : *pi2;
}

// Exercise 6.22: pointer to pointer version
void swap_pointers(int **p1, int **p2)
{
	int *tmp;
	
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

int main_swap_pointers()
{
	int ival1 = 11, ival2 = 22;
	int *ip1 = &ival1, *ip2 = &ival2;
	
	cout << *ip1 << "\t" << *ip2 << endl;
	swap_pointers(&ip1, &ip2);
	cout << *ip1 << "\t" << *ip2 << endl;
		
	return 0;
}

// Exercise 6.22: reference to pointer version - easier to understand
void swap_pointers_v2(int *&p1, int *&p2)
{
	int *tmp;
	
	tmp = p1;
	p1 = p2;
	p2 = tmp;
}

int main_swap_pointers_v2()
{
	int ival1 = 11, ival2 = 22;
	int *ip1 = &ival1, *ip2 = &ival2;
	
	cout << *ip1 << "\t" << *ip2 << endl;
	swap_pointers_v2(ip1, ip2);
	cout << *ip1 << "\t" << *ip2 << endl;
		
	return 0;
}

// Exercise 6.23
// Using a marker to specify the extent of an array: for an array of intS, there is no obvious end-marker value.
// Here I just use -1 as end marker which is NOT a good idea.
void print_1(int i, const int *j)
{
	cout << "i = " << i << endl;
	
	if (j)
		while (*j != -9999)
			cout << *j++ << " ";
}

// Using the standard library conventions
void print_2(int i, const int *beg, const int *end)
{
	cout << "i = " << i << endl;

	while (beg != end)
		cout << *beg++ << " ";
}

// Explicitly passing a size parameter
void print_3(const int iarr[], size_t sz)
{
	for (size_t i = 0; i != sz; ++i)
		cout << iarr[i] << " ";
}

// Parameter is a reference to an array
void print_4(int (&ia)[10])
{
	for (auto e : ia)
		cout << e << " ";
}

// Exercise 6.24
void print_6_24(const int ia[10])
{
	for (size_t i = 0; i != 10; ++i)
		cout << ia[i] << endl;
}

int main()
{
	int k[] = {0, 1, 2, 3, 4, 5, 6};
	
	print(k);
	
	return 0;
}



