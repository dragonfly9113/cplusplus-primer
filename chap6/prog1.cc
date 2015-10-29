#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cassert>
#include "Chapter6.h"

using std::cin; using std::cout; using std::endl; using std::cerr;
using std::string; using std::vector; using std::begin; using std::end;
using std::runtime_error;
using std::initializer_list;

#define NDEBUG

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

// Exercise 6.25
int ex6_25(int argc, char *argv[])
{
	string arg1, arg2, str;
	
	if (argc == 3) {
		arg1 = argv[1];
		arg2 = argv[2];
		str = arg1 + arg2;
	}
		
	cout << str << endl;
	
	return 0;
}

// Exercise 6.26
int ex6_26(int argc, char *argv[])
{
	cout << "Arguments passed in are: " << endl;
	for (int i = 1; i != argc; ++i)
		cout << argv[i] << " ";
	
	return 0;
}

// Exercise 6.27
int sum_up_arguments(initializer_list<int> il)
{
	int ret = 0;
	
	for (auto e : il)
		ret += e;
	
	return ret;
}

int main_6_27()
{
	cout << sum_up_arguments({10, 20, 25}) << endl;
	
	return 0;
}

// Exercise 6.30
bool str_subrange(const string &str1, const string &str2)
{
	if (str1.size() == str2.size())
		return str1 == str2;
	
	auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();
	for (decltype(size) i = 0; i != size; ++i)
		if (str1[i] != str2[i])
			//return; 	// error #1: no return type
			return false;
	
	// error #2: control might flow off the end of the function without a return.
	// compiler might not detect this error
	return true;
}

// Exercise 6.32
int &get(int *arry, int index) { return arry[index]; }

int main_6_32()
{
	int ia[10];

	for (auto e : ia)
		cout << e << " ";
	cout << endl;
	
	for (int i = 0; i != 10; ++i)
		get(ia, i) = i;

	for (auto e : ia)
		cout << e << " ";
	cout << endl;
	
	return 0;
}

// Exercise 6.33
void print_vec(vector<int> vec)
{
	if (vec.size() > 0) {
		cout << *vec.cbegin() << endl;
		vec.erase(vec.cbegin());
		print_vec(vec);
	}
	else
		return;
}

int main_6_33()
{
	vector<int> ivec{0, 1, 2, 3, 4, 5};
	
	print_vec(ivec);
	
	cout << "After print_vec(), ivec becomes: " << endl;
	for (auto e : ivec)
		cout << e << " ";

	return 0;
}

// Exercise 6.34
int factorial(int val)
{
	if (val != 0)
		return factorial(val -1) * val;
	return 1;
}

int main_6_34()
{
	cout << factorial(-1) << endl;
	
	return 0;
}

// Exercise 6.35
int factorial_v2(int val)
{
	if (val > 1)
		//return factorial_v2(--val) * val;
		return factorial_v2(val - 1) * val;
	return 1;
}

int main_6_35()
{
	cout << factorial_v2(5) << endl;
	
	return 0;
}

// Exercise 6.36
string (&arrRef(int i1, int i2))[10];

// Exercise 6.37
// usig a type alias
//using arrT = string[10];	// arrT is an alias for the type array of ten strings
//arrT &arrRef(int i);

// using a trailing return type
//auto arrRef(int i) -> string(&)[10];

// using decltype
//string strArr[10];
//decltype(strArr) &arrRef(int i);

// Exercise 6.38
int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};
decltype(odd) &arrRef(int i)
{
	return (i % 2) ? odd : even; // return a reference to the array of 5 integers
}

int main_6_38()
{
	for ( auto &e : arrRef(0))
		e *= 2;
		
	for (auto e : odd)
		cout << e << " ";
	cout << endl;
	
	for (auto e :even)
		cout << e << " ";
		
	return 0;
}

// Exercise 6.39
int calc(int, int);
int calc(const int, const int);

//int get();
//double get();

//int *reset(int *);
//double *reset(double *);

// Exercise 6.40
//int ff(int a, int b, int c = 0);
//char *init(int ht = 24, int wd, char bckgrnd);

// Exercise 6.41
int init_1(int ht, int wd = 80, char bckgrnd = ' ')
{
	cout << ht << endl;
	cout << wd << endl;
	cout << bckgrnd << endl;
	
	return 0;
}

int main_6_41()
{
	init_1(40);
	init_1(24, 10);
	init_1(14, '*');
	
	return 0;
}

// Exercise 6.42
string make_plural(size_t ctr, const string &word, const string &ending = "s")
{
	return (ctr > 1) ? word + ending : word;
}

int main_6_42()
{
	size_t ctr = 2;
	string word = "Success";
	string ending = "es";
	
	//cout << make_plural(ctr, word, ending) << endl;
	cout << make_plural(ctr, word) << endl;

	word = "Failure";
	ending = "s";
	
	//cout << make_plural(ctr, word, ending) << endl;
	cout << make_plural(ctr, word) << endl;
	
	return 0;
}

// Exercise 6.44
inline bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

int main_6_44()
{
	string str1 = "Hello world!";
	string str2 = "Good morning America!";
	
	cout << isShorter(str1, str2) << endl;
	
	return 0;
}

// Exercise 6.46
//constexpr bool isShorter_1(const string &s1, const string &s2)
//{
//	return s1.size() < s2.size();
//}

// Exercise 6.47
void print_vec_dbg(vector<int> vec)
{
	if (vec.size() > 0) {
		cout << *vec.cbegin() << endl;
#ifndef NDEBUG		
		cout << "vec size: " << vec.size() << endl;
#endif
		vec.erase(vec.cbegin());
		print_vec_dbg(vec);
	}
	else
		return;
}

int main_6_47()
{
	vector<int> ivec{0, 1, 2, 3, 4, 5};

	print_vec_dbg(ivec);
	cout << "After print_vec(), ivec becomes: " << endl;
	for (auto e : ivec)
		cout << e << " ";

	return 0;
}

// Exercise 6.48
int main_6_48()
{
	string s, sought = "Hello";
	
	while (cin >> s && s != sought) {} // empty body
	assert(cin);
	
	return 0;
}

// Exercise 6.50, 6.51
void f()
{
	cout << "f()" << endl;
}

void f(int)
{
	cout << "f(int)" << endl;
}

void f(int, int)
{
	cout << "f(int, int)";
}	

void f(double, double = 3.14)
{
	cout << "f(double, double)" << endl;
}

int main_6_51()
{
	//f(2.56, 42);
	//f(42);
	//f(42, 0);
	f(2.56, 3.14);
	
	return 0;
}

// Exercise 6.52
void manip(int, int)
{
	cout << "manip(int, int)" << endl;
}

int main_6_52()
{
	double dobj = 3.14;
	
	manip('a', 'z');
	manip(55.4, dobj);
	
	return 0;
}

// Exercise 6.53
int calc_1(int&, int&)
{
	cout << "int calc_1(int&, int&)" << endl;
	return 0;
}

int calc_1(const int&, const int&)
{
	cout << "int calc_1(const int&, const int&)" << endl;
	return 0;
}

int calc_2(char*, char*)
{
	cout << "int calc_2(char*, char*)" << endl;
	return 0;
}

int calc_2(const char*, const char*)
{
	cout << "int calc_2(const char*, const char*)" << endl;
	return 0;
}

int calc_3(char*, char*)
{
	cout << "int calc_3(char*, char*)" << endl;
	return 0;
}

int calc_3(char* const, char* const)
{
	cout << "int calc_3(char* const, char* const)" << endl;
	return 0;
}

int main()
{
	//const int i1 = 0, i2 = 0;
	char c1 = 'a', c2 = 'b';
	
	//calc_1(i1, i2);
	//calc_2(&c1, &c2);
	calc_3(&c1, &c2);
	
	return 0;
}
