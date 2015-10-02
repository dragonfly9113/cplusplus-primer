#include <iostream>
#include <string>
#include <vector>
#include "Sales_data.h"

using std::cin; using std::cout; using std::endl; using std::cerr;
using std::string; using std::vector; using std::begin; using std::end;

// Exercise 3.1: rewrite programs in exercise section 1.4.1 with appropriate using declarations
int ex3_1_1()
{
	int sum = 0, cnt = 50;
	while(cnt <= 100)	{
		sum += cnt;
		++cnt;
	}
	cout << "The sum from 50 to 100 is " << sum << endl;
	
	cnt = 10;
	while(cnt >= 0) {
		cout << cnt << endl;
		--cnt;
	}
	
	cout << "Enter two numbers:" << endl;
	int v1 = 0, v2 = 0;
	cin >> v1 >> v2;
	
	while(v1 <= v2) {
		cout << v1 << endl;
		++v1;
	}
	
	return 0;
}

// Exercise 3.1: rewrite programs in exercise section 2.6.2 with appropriate using declarations
int ex3_1_2()
{
	Sales_data total;
	double price = 0;
	
	// read in the first record and see if it is valid:
	if(cin >> total.bookNo >> total.units_sold >> price) {
		total.revenue = total.units_sold * price;
		Sales_data trans;
		double avg_price;
		
		// read in other records
		while(cin >> trans.bookNo >> trans.units_sold >> price) {
			trans.revenue = trans.units_sold * price;
			
			if(trans.bookNo == total.bookNo) { // if this isbn is the same, update the total
				total.units_sold += trans.units_sold;
				total.revenue += trans.revenue;
			}
			else { 		// if this isbn is different, print out the last total and reset
				avg_price = (total.units_sold == 0) ? 0.0 : total.revenue / total.units_sold;
				cout << total.bookNo << " " << total.units_sold << " " << total.revenue << " " << avg_price << endl;
				
				total.bookNo = trans.bookNo;
				total.units_sold = trans.units_sold;
				total.revenue = trans.revenue;
			}
		}
		
		// print the last trans:
		avg_price = (total.units_sold == 0) ? 0.0 : total.revenue / total.units_sold;
		cout << total.bookNo << " " << total.units_sold << " " << total.revenue << " " << avg_price << endl;
	}
	else {
		cerr << "No data?!" << endl;
		return -1;
	}
	
	return 0;
}

// Exercise 3.2
int ex3_2()
{
	string line, word;
	
	// read input a line at a time
	//while (getline(cin, line))
	//	cout << line << endl;
	
	// read input a word at a time
	while (cin >> word)
		cout << word << endl;
	
	return 0;
}

// Exercise 3.4
int ex3_4()
{
	string str1, str2;
	
	cout << "Enter the first string:" << endl;
	getline(cin, str1);
	cout << "Enter the second string:" << endl;
	getline(cin, str2);
	
	//if (str1 == str2)
	if (str1.size() == str2.size())
		//cout << "str1 and str2 are equal!" << endl;
		cout << "str1 and str2 have the same length!" << endl;
	//else if (str1 > str2)
	else if (str1.size() > str2.size())
		//cout << "str1 is larger!" << endl;
		cout << "str1 is longer!" << endl;
	else
		//cout << "str2 is larger!" << endl;
		cout << "str2 is longer!" << endl;
	
	return 0;
}

// Exercise 3.5
int ex3_5()
{
	string str, total;
	
	cout << "Enter several strings:" << endl;
	// get the first line:
	getline(cin, total);
	
	// read in other lines:
	while (getline(cin, str))
		total = total + " " + str;
	
	cout << total << endl;
	
	return 0;
}

// Exercise 3.6
int ex3_6()
{
	string str;
	
	cout << "Enter a string:" << endl;
	getline(cin, str);
	
	for (auto &c : str)
		c = 'X';

	cout << str << endl;
	
	return 0;
}

// Exercise 3.7
int ex3_7()
{
	string str;
	
	cout << "Enter a string:" << endl;
	getline(cin, str);
	
	//for (char c : str)
	//	c = 'X';

	cout << str << endl;
	
	return 0;
}

// Exercise 3.8
int ex3_8()
{
	string str;
	//decltype(str.size()) index = 0;
	
	cout << "Enter a string:" << endl;
	getline(cin, str);

	//for (char c : str)
	//	c = 'X';
	
	//while (index != str.size()) {
	//	str[index] = 'X';
	//	++index;
	//}
	
	for (decltype(str.size()) index = 0; index != str.size(); ++index) 
		str[index] = 'X';
	
	cout << str << endl;
	
	return 0;
}

// Exercise 3.9
int ex3_9()
{
	string s;
	
	cout << s[0] << endl;
	
	return 0;
}

// Exercise 3.10
int ex3_10()
{
	string str, newStr;
	
	cout << "Enter a string:" << endl;
	getline(cin, str);
	
	for (auto c : str)
		if (!ispunct(c))
			newStr += c;
	
	cout << newStr << endl;
		
	return 0;
}

// Exercise 3.11
int ex3_11() 
{
	const string s = "Keep out!";
	
	for (auto &c : s)
		cout << c << endl;
	
	return 0;
}

// Exercise 3.12
int ex3_12()
{
	vector<vector<int>> ivec;
	
	//vector<string> svec = ivec;
	
	vector<string> svec(10, "null");
	
	return 0;
}

// Exercise 3.14
int ex3_14()
{
	int i;
	vector<int> ivec;
	
	cout << "Enter a sequence of ints:" << endl;
	while (cin >> i) {
		ivec.push_back(i);
	}

	return 0;
}

// Exercise 3.15
int ex3_15()
{
	string word;
	vector<string> svec;
	
	cout << "Enter a sequence of stringS:" << endl;
	while (cin >> word) {
		svec.push_back(word);
	}

	return 0;
}

// Exercise 3.16
int ex3_16()
{
	vector<int> v1;
	vector<int> v2(10);
	vector<int> v3(10, 42);
	vector<int> v4{10};
	vector<int> v5{10, 42};
	vector<string> v6{10};
	vector<string> v7{10, "hi"};

	cout << "size of v5 is: " << v5.size() << endl;
	for (auto elem : v5)
		cout << elem << endl;

	cout << "size of v6 is: " << v6.size() << endl;
	for (auto elem : v6)
		cout << elem << endl;

	cout << "size of v7 is: " << v7.size() << endl;
	for (auto elem : v7)
		cout << elem << endl;
	
	return 0;
}

// Exercise 3.17
int ex3_17()
{
	string word;
	vector<string> svec;
	
	cout << "Enter a sequence of words:" << endl;
	while (cin >> word) {
		svec.push_back(word);
	}
	
	// process the vector and change each word to uppercase.
	for (auto &s : svec)
		for (auto &c : s)
			c = toupper(c);
	
	// print the transformed elements, eight words to a line.
	unsigned count = 0;
	for (auto s : svec) {
		cout << s << " ";
		if (++count == 8) {
			cout << endl;
			count = 0;
		}
	}	

	return 0;
}

// Exercise 3.18
int ex3_18()
{
	vector<int> ivec;
	
	ivec.push_back(42);
	
	return 0;
}

// Exercise 3.19
int ex3_19()
{
	// Method 1:
	//vector<int> ivec(10, 42);
	// Method 2:
	//vector<int> ivec{42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
	// Method 3:
	vector<int> ivec;
	for (int i = 0; i != 10; ++i)
		ivec.push_back(42);
		
	cout << "size of ivec is: " << ivec.size() << endl;
	for (auto e : ivec)
		cout << e << endl;

	return 0;
}

// Exercise 3.20
int ex3_20()
{
	int i;
	vector<int> ivec;
	
	cout << "Enter a set of integers: " << endl;
	while (cin >> i)
		ivec.push_back(i);

	//for (decltype(ivec.size()) index = 0; index < ivec.size(); index += 2) {
	//	if (index == ivec.size() - 1)
	//		cout << ivec[index] << endl;
	//	else
	//		cout << ivec[index] + ivec[index + 1] << endl;
	//}

	for (decltype(ivec.size()) index = 0; index != ivec.size() / 2; ++index) {
		cout << ivec[index] + ivec[ivec.size() - index - 1] << endl;
		// if there are odd number of elements in ivec, print out the middle element:
		if (index == ivec.size()/2 - 1 && ivec.size() % 2 != 0)
			cout << ivec[index + 1] << endl;
	}
	
	return 0;
}

// Exercise 3.21
int ex3_21()
{
	vector<int> v1;
	vector<int> v2(10);
	vector<int> v3(10, 42);
	vector<int> v4{10};
	vector<int> v5{10, 42};
	vector<string> v6{10};
	vector<string> v7{10, "hi"};

	cout << "size of v5 is: " << v5.size() << endl;
	for (auto it = v5.cbegin(); it != v5.cend(); ++it)
		cout << *it << endl;

	cout << "size of v6 is: " << v6.size() << endl;
	for (auto it = v6.cbegin(); it != v6.cend(); ++it)
		cout << *it << endl;

	cout << "size of v7 is: " << v7.size() << endl;
	for (auto it = v7.cbegin(); it != v7.cend(); ++it)
		cout << *it << endl;
	
	return 0;
}

// Exercise 3.22
int ex3_22()
{
	string str;
	vector<string> text;
	
	// read into text:
	cout << "Enter a text:" << endl;
	while (getline(cin, str))
		text.push_back(str);
	
	// change the elements in text that correspond to the first paragraph to all uppercase:
	for (auto its = text.begin(); its != text.end() && !its->empty(); ++its)
		for (auto itc = its->begin(); itc != its->end(); ++itc)
			*itc = toupper(*itc);
			
	// print the contents of text:
	for (auto it = text.cbegin(); it != text.cend(); ++it)
		cout << *it << endl;
	
	return 0;
}

// Exercise 3.23
int ex3_23()
{
	vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	for (auto it = ivec.begin(); it != ivec.end(); ++it)
		*it = *it * 2;
	
	cout << "The size of ivec is: " << ivec.size() << endl;
	for (auto it = ivec.cbegin(); it != ivec.cend(); ++it)
		cout << *it << endl;
	
	return 0;
}

// Exercise 3.24
int ex3_24()
{
	int i;
	vector<int> ivec;
	
	cout << "Enter a set of integers: " << endl;
	while (cin >> i)
		ivec.push_back(i);

	//for (auto it = ivec.cbegin(); it < ivec.cend(); it += 2) {
	//	if (it == (ivec.cend() - 1))
	//		cout << *it << endl;
	//	else
	//		cout << *it + *(it + 1) << endl;
	//}
	
	//for (decltype(ivec.size()) index = 0; index != ivec.size() / 2; ++index) {
	//	cout << ivec[index] + ivec[ivec.size() - index - 1] << endl;
	//	// if there are odd number of elements in ivec, print out the middle element:
	//	if (index == ivec.size()/2 - 1 && ivec.size() % 2 != 0)
	//		cout << ivec[index + 1] << endl;
	//}
	
	auto beg = ivec.cbegin(), end = ivec.cend();
	auto mid = beg + (end - beg)/2;
	for (auto it = beg; it != mid; ++it) {
		auto ite = end - (it -beg) - 1;
		cout << *it + *ite << endl;
		if (2 == ite - it)	
			cout << *(it + 1) << endl;
	}
	
	return 0;
}

// Exercise 3.25: count the number of grades by clusters of ten: 0--9, 10--19, ..., 90--99, 100
int ex3_25()
{
	vector<unsigned> scores(11, 0);	// 11 buckets, all initially 0
	unsigned grade;
	
	cout << "Enter a set of scores (0 -- 100): " << endl;
	while (cin >> grade) {
		if (grade <= 100)
			++(*(scores.begin() + grade/10));
	}
	
	for (auto it = scores.cbegin(); it != scores.cend(); ++it)
		cout << *it << " ";
	
	cout << endl;
	
	return 0;
}

// Exercise 3.26
int ex3_26()
{
	vector<int> ivec{1, 2 ,3, 4, 5, 6, 7, 8, 9, 10};
	
	auto beg = ivec.begin(), end = ivec.end();
	auto mid = beg + (end - beg)/2;
	//auto mid = (beg + end)/2;
	
	cout << *mid << endl;
	
	return 0;
}

// Exercise 3.27
int ex3_27()
{
	//unsigned buf_size = 1024;
	//int ia[txt_size()];
	//char st[11] = "fundamental";
		
	return 0;
}

// Exercise 3.31
int ex3_31()
{
	int arr[10] = {};
	
	for (int i = 0; i < 10; ++i)
		arr[i] = i;
	
	for (auto i : arr)
		cout << i << endl;
	
	return 0;
}

// Exercise 3.32
int ex3_32()
{
	int ar1[10] = {};
	int ar2[10] = {};
	
	for (int i = 0; i < 10; ++i)
		ar1[i] = i;

	// copy ar1 to ar2:
	//ar2 = ar1;
	for (int i = 0; i < 10; ++i)
		ar2[i] = ar1[i];
	
	for (auto e : ar2)
		cout << e << " ";
	
	return 0;
}

// Exercise 3.32: vector version
int ex3_32v()
{
	vector<int> ivec1;
	vector<int> ivec2;
	
	for (int i = 0; i < 10; ++i)
		ivec1.push_back(i);
	
	ivec2 = ivec1;
	
	for (auto e : ivec2)
		cout << e << " ";
	
	return 0;
}

// Exercise 3.33
int ex3_33()
{
	unsigned scores[11];
	unsigned grade;
	
	while (cin >> grade) {
		if (grade <= 100)
			++scores[grade/10];
	}
	
	for (auto e : scores)
		cout << e << " ";
	
	return 0;
}

// Section 3.5.3 examples
int sec3_5_3()
{
	constexpr size_t sz = 5;
	int ia[sz] = {1, 2, 3, 4, 5};
	
	int *pbeg = begin(ia);
	int *pend = end(ia); 
	
	cout << *(pbeg + 2) << endl;
	cout << *(pend - 1) << endl;
	
	return 0;
}

