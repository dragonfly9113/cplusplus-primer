#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <forward_list>
#include <stack>
#include <queue>
#include <stdexcept>
#include <cassert>
#include "Sales_data.h"

using std::cin; using std::cout; using std::endl; using std::cerr;
using std::string; using std::vector; using std::list; using std::deque; using std::forward_list;
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
int ex_9_22()
{
	vector<int> iv{1, 3, 5, 7, 9};
	int some_val = 7;
	
	auto iter = iv.begin(),
		 mid = iv.begin() + iv.size()/2;
	
	while (iter != mid) {
		if (*iter == some_val) {
			iter = iv.insert(iter, 2 * some_val);
			++iter;		// insert will return a new iter.
			mid = iv.begin() + iv.size()/2;	// re-calculate mid because the old one has been invalidated by insert()
		}
		++iter;
	}
	
	for (auto e : iv)
		cout << e << endl;
	
	return 0;
}

// Exercise 9.23
int ex_9_23()
{
	vector<int> c{7};
	
	if (!c.empty()) {
		auto val = *c.begin(), val2 = c.front();
		auto last = c.end();
		auto val3 = *(--last);
		auto val4 = c.back();
		
		cout << "size of c: " << c.size() << endl;
		cout << val << endl;
		cout << val2 << endl;
		cout << val3 << endl;
		cout << val4 << endl;
	}
	
	return 0;
}

// Exercise 9.24
int ex_9_24()
{
	vector<int> iv{1, 3, 5, 7, 9};
	//vector<int> iv;
	
	cout << "fetch the first element using at():" << endl;
	cout << iv.at(0) << endl;
	
	cout << "fetch the first element using subscript operator:" << endl;
	cout << iv[0] << endl;
	
	cout << "fetch the first element using front():" << endl;
	cout << iv.front() << endl;
	
	cout << "fetch the first element using begin():" << endl;
	cout << *iv.begin() << endl;
	
	return 0;
}

// Exercise 9.25
int ex_9_25()
{
	list<string> slist{"Hello", "world!", "Good", "morning", "America!"};
	
	auto elem1 = slist.begin();
	auto elem2 = slist.end();
	elem1 = elem2;
	elem1 = slist.erase(elem1, elem2);
	
	cout << "size of slist: " << slist.size() << endl;
	for (auto e : slist)
		cout << e << " ";
	cout << endl << "*elem1 is: " << *elem1;
	
	return 0;
}

// Exercise 9.26
int ex_9_26()
{
	vector<int> ivec;
	list<int> ilst;
	int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
	
	// copy ia into a vector and a list:
	for (auto e : ia) {
		ivec.push_back(e);
		ilst.push_back(e);
	}

	// remove odd elements in ilst:
	auto it = ilst.begin();
	while (it != ilst.end())
		if (*it % 2)
			it = ilst.erase(it);
		else
			++it;

	// remove even elements in ivec:
	auto it1 = ivec.begin();
	while (it1 != ivec.end())
		if (*it1 % 2 == 0)
			it1 = ivec.erase(it1);
		else
			++it1;

	cout << "ilst is: ";
	for (auto e : ilst)
		cout << e << " ";
	cout << endl;
		
	cout << "ivec is: ";
	for (auto e : ivec)
		cout << e << " ";
	
	return 0;
}

// Exercise 9.27
int ex_9_27()
{
	forward_list<int> flst{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	auto prev = flst.before_begin();
	auto curr = flst.begin();
	while (curr != flst.end())
		if (*curr % 2) {
			curr = flst.erase_after(prev);
		} else {
			prev = curr;
			++curr;
		}
	
	for (auto e : flst)
		cout << e << " ";
		
	return 0;
}

// Exercise 9.28
void find_and_insert(forward_list<string> &flst, string str1, string str2)
{
	auto prev = flst.before_begin();
	auto curr = flst.begin();
	bool match_found = false;
	
	while (curr != flst.end())
	{
		prev = curr;
		if (*curr == str1) {
			curr = flst.insert_after(curr, str2);
			match_found = true;
		} else {
			++curr;
		}
	}
	
	if (!match_found)
		flst.insert_after(prev, str2);
}

int ex_9_28()
{
	forward_list<string> fslst{"Hello", "world!", "good", "morning", "How", "are", "you", "doing?"};
	
	find_and_insert(fslst, "how", "good");
	
	for (auto e : fslst)
		cout << e << " ";
	
	return 0;
}

// Exercise 9.31
int ex_9_31_list()
{
	//vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	list<int> ilst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	auto iter = ilst.begin();
	while (iter != ilst.end()) {
		if (*iter % 2) {
			iter = ilst.insert(iter, *iter);	// duplicate the current element
			++iter;	++iter;		// advance past this element and the one inserted before it
		} else
			iter = ilst.erase(iter);	// remove even element
	}
	
	for (auto e : ilst)
		cout << e << " ";
	
	return 0;
}

int ex_9_31_flist()
{
	//vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	forward_list<int> iflst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	auto prev = iflst.before_begin();
	auto iter = iflst.begin();
	while (iter != iflst.end()) {
		if (*iter % 2) {
			iter = iflst.insert_after(iter, *iter);	// duplicate the current element
			prev = iter;	// move prev to the one just inserted
			++iter;			// advance iter to the next element
		} else
			iter = iflst.erase_after(prev);	// use prev to remove current even element
											// prev does not need to be updated since it is already updated in erase_after()
	}
	
	for (auto e : iflst)
		cout << e << " ";
	
	return 0;
}

// Exercise 9.32
int ex_9_32()
{
	vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	auto iter = vi.begin();
	while (iter != vi.end()) {
		if (*iter % 2) {
			iter = vi.insert(iter, *iter++);	// duplicate the current element
			//iter += 2;		// advance past this element and the one inserted before it
			++iter;
		} else
			iter = vi.erase(iter);	// remove even element
	}
	
	for (auto e : vi)
		cout << e << " ";
	
	return 0;
}

// Exercise 9.33
int ex_9_33()
{
	vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	auto begin = vi.begin();
	while (begin != vi.end()) {
		// do some process
		*begin = *begin * 2;
		++begin;
		//begin = vi.insert(begin, 42);
		vi.insert(begin, 42);
		++begin;
	}

	for (auto e : vi)
		cout << e << " ";
	
	return 0;
}

// Exercise 9.34
int ex_9_34()
{
	vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	auto iter = vi.begin();
	while (iter != vi.end()) {
		if (*iter % 2) {
			iter = vi.insert(iter, *iter);
			++iter;
		}
		++iter;
	}

	for (auto e : vi)
		cout << e << " ";
	
	return 0;
}

// Exercise 9.38
int ex_9_38()
{
	vector<int> ivec;
	cout << "ivec: size: " << ivec.size()
		 << " capacity: " << ivec.capacity() << endl;
		 
	// give ivec 24 elements
	for (vector<int>::size_type ix = 0; ix != 24; ++ix)
		ivec.push_back(ix);
	
	// size should be 24; capacity will be >= 24 and is implementation defined
	cout << "ivec: size: " << ivec.size()
		 << " capacity: " << ivec.capacity() << endl;
	
	// we now reserve some additional space
	ivec.reserve(50);	// set capacity to at least 50; might be more
	cout << "ivec: size: " << ivec.size()
		 << " capacity: " << ivec.capacity() << endl;
	
	// add elements to use up all capacity
	while (ivec.size() != ivec.capacity())
		ivec.push_back(0);
	// size and capacity are now equal; capacity should be unchanged since there is still no need to allocate more memory
	cout << "ivec: size: " << ivec.size()
		 << " capacity: " << ivec.capacity() << endl;
	
	// add one more element: the vector now has to reallocate itself
	ivec.push_back(42);
	// size should be 51; capacity will be >=51 and is implementation defined
	cout << "ivec: size: " << ivec.size()
		 << " capacity: " << ivec.capacity() << endl;

	// ask for the memory to be returned
	ivec.shrink_to_fit();
	// size should be unchanged; capacity is implementation defined.
	// calling shrink_to_fit is only a request, there is no gurantee that the library will return the memory.
	cout << "ivec: size: " << ivec.size()
		 << " capacity: " << ivec.capacity() << endl;
	
	return 0;
}

// Exercise 9.39
int ex_9_39()
{
	vector<string> svec;
	// size should be 0; capacity should be >= 1024.
	svec.reserve(1024);
	string word;
	// add certain number of stringS
	while (cin >> word)
		svec.push_back(word);
	// add size/2 more stringS into svec.
	svec.resize(svec.size() + svec.size()/2);
	
	for (auto e : svec)
		cout << e << endl;

	//size should be size + size/2; capacity should be unchanged is the new size <= capacity.
	cout << "svec: size: " << svec.size()
		 << " capacity: " << svec.capacity() << endl;
	
	return 0;
}

// Exercise 9.41
int ex_9_41()
{
	vector<char> vc = {'H', 'e', 'l', 'l', 'o'};
	
	string s(vc.begin(), vc.end());
	
	cout << "s is: " << s << endl;
	
	return 0;
}

// Exercise 9.42
int ex_9_42()
{
	string s;
	char c;
	
	s.reserve(200);
	while (cin >> c)
		s.push_back(c);

	cout << "s is: " << s << endl;
	// size of s should be at least 100; capacity should be >=200
	cout << "s: size: " << s.size()
		 << " capacity: " << s.capacity() << endl;
	
	return 0;
}

// Exercise 9.43
void replace_old_with_new(string &s, string oldVal, string newVal)
{
	auto iter = s.begin();
	
	while (iter != s.end()) {
		string temp(iter, iter + oldVal.size());
		if (temp == oldVal) {
			auto idx = iter - s.begin();
			s.erase(idx, oldVal.size());
			s.insert(idx, newVal);
			// update iter to denote the last character of newVal
			iter = s.begin() + idx + newVal.size() - 1;
		}

		++iter;
	}
}

int ex_9_43()
{
	string str("Hello world, tho you know this. Pls take tho lead tho");

	cout << str << endl;	
	replace_old_with_new(str, "tho", "though");
	cout << str << endl;
	
	return 0;
}

// Exercise 9.44
void replace_old_with_new_idx(string &s, string oldVal, string newVal)
{
	string::size_type idx = 0;
	
	while (idx != s.size()) {
		string temp(s, idx, oldVal.size());
		if (temp == oldVal) {
			s.replace(idx, oldVal.size(), newVal);
			// update idx to denote the last character of newVal
			idx = idx + newVal.size() - 1;
		}
		++idx;
	}
}

int ex_9_44()
{
	string str("Hello world, tho you know this. Pls take tho lead tho");

	cout << str << endl;	
	replace_old_with_new_idx(str, "tho", "though");
	cout << str << endl;
	
	return 0;
}

// Exercise 9.45
string add_prefix_suffix(string name, string prefix, string suffix)
{
	string newStr(name);	// create a new string newStr, copy name to it.
	auto iter = newStr.begin();
	
	// add prefix
	iter = newStr.insert(iter, ' ');	// iter now denote the first inserted character ' '
	newStr.insert(iter, prefix.begin(), prefix.end());
	
	// add suffix
	newStr.append(" " + suffix);
	
	return newStr;
}

int ex_9_45()
{
	string result;
	
	result = add_prefix_suffix("John Doe", "Mr.", "Jr.");
	cout << result << endl;
	
	return 0;
}

// Exercise 9.46
string add_prefix_suffix_pos(string name, string prefix, string suffix)
{
	string newStr(name);	// create a new string newStr, copy name to it.

	cout << "A new version: add_prefix_suffix_pos()" << endl;
	
	// add prefix
	newStr.insert(0, prefix + " ");
	
	// add suffix
	newStr.insert(newStr.size(), " " + suffix);
	
	return newStr;
}

int ex_9_46()
{
	string result;
	
	result = add_prefix_suffix_pos("John Doe", "Mr.", "III");
	cout << result << endl;
	
	return 0;
}

// Exercise 9.47: use find_first_of
int ex_9_47_1()
{
	string str("ab2c3d7R4E6");
	string numbers("0123456789");
	string alphabets("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
	string::size_type pos = 0;
	string numerica_chars, alphabetic_chars;
	
	while ((pos = str.find_first_of(numbers, pos)) != string::npos) {
		numerica_chars.push_back(str[pos]);
		++pos;
	}

	pos = 0;
	while ((pos = str.find_first_of(alphabets, pos)) != string::npos) {
		alphabetic_chars.push_back(str[pos]);
		++pos;
	}

	cout << str << endl;
	cout << "all numbers are: " << numerica_chars << endl;
	cout << "all alphabets are: " << alphabetic_chars << endl;
	
	return 0;
}

// Exercise 9.47: use find_first_not_of
int ex_9_47_2()
{
	string str("ab2c3d7R4E6");
	string numbers("0123456789");
	string alphabets("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
	string::size_type pos = 0;
	string numerica_chars, alphabetic_chars;
	
	while ((pos = str.find_first_not_of(alphabets, pos)) != string::npos) {
		numerica_chars.push_back(str[pos]);
		++pos;
	}

	pos = 0;
	while ((pos = str.find_first_not_of(numbers, pos)) != string::npos) {
		alphabetic_chars.push_back(str[pos]);
		++pos;
	}

	cout << str << endl;
	cout << "all numbers are: " << numerica_chars << endl;
	cout << "all alphabets are: " << alphabetic_chars << endl;
	
	return 0;
}

// Exercise 9.48
int ex_9_48()
{
	string numbers("0123456789"), name("r2d2");
	
	auto pos = numbers.find(name);
	
	cout << pos << endl;
	
	return 0;
}

// Exercise 9.49
int ex_9_49(int argc, char *argv[])
{
	string ascenders("bdfhijklt");
	string decenders("gjpqy");
	string word, candidate;
	
	if (argc < 2) {
		cout << "Usage: prog1 filename" << endl;
		return -1;
	}
	
	ifstream input(argv[1]);
	if (!input)
		cerr << "couldn't open: " + string(argv[1]) << endl;
	
	while (input >> word) {
		if ((word.find_first_of(ascenders) == string::npos) && (word.find_first_of(decenders) == string::npos)) {
			if (word.size() > candidate.size())
				candidate = word;
		}
	}
	
	cout << "The longest word that contains neither ascenders nor decenders is: " << candidate << endl;
	
	return 0;
}

// Exercise 9.50
// TO-DO: couldn't verify this program because GCC 4.9.3 for Cygwin doesn't support std::stoi
int ex_9_50()
{
	vector<string> svec{"1", "2", "3", "4", "5"};
	int sum = 0;
	
	//for (auto e : svec) {
	//	sum += std::stoi(e, nullptr, 10);
	//}

	cout << sum << endl;
	
	return 0;
}

// Exercise 9.51
// TO-DO: didn't do this exercise because my current GCC 4.9.3 for Cygwin deoesn't support C++11 numeric converstion functions.

// Example: Stack Adaptor
int stack_adapter()
{
	std::stack<int> intStack;
	
	for (size_t ix = 0; ix != 10; ++ix)
		intStack.push(ix);
	
	while (!intStack.empty()) {
		int value = intStack.top();
		cout << value << endl;
		intStack.pop();
	}
	
	return 0;
}

// Example: Queue Adaptor
int queue_adaptor()
{
	std::queue<int> intQueue;
	
	for (size_t ix = 0; ix != 10; ++ix)
		intQueue.push(ix);
	
	while (!intQueue.empty()) {
		int value = intQueue.front();
		cout << value << endl;
		intQueue.pop();
	}
	
	return 0;
}

// Exercise 9.52
int main()
{
	// after processing, the expression should be: "value1 && P-EXP || P-EXP && value2"
	string orig_exp("value1 && ( a == 0 ) || ( b == 1) && value2");
	std::stack<char> cstk;
	bool open_p_found = false;

	for (auto e : orig_exp) {
		cstk.push(e);
		if ( e == '(') {
			open_p_found = true;
		}
		else if ( e == ')' && open_p_found) {
			open_p_found = false;
			// pop out the parenthesized expression and push a special value in place
			while (cstk.top() != '(')
				cstk.pop();
			// pop out the openning parenthesis	and push a special value in place
			cstk.pop();
			cstk.push('{'); cstk.push('}');
		}
	}
	
	deque<char> cdeq;
	while (!cstk.empty()) {
		char value = cstk.top();
		cdeq.push_front(value);
		cstk.pop();
	}
	
	string new_exp(cdeq.begin(), cdeq.end());
	cout << new_exp << endl;
	
	return 0;
}


