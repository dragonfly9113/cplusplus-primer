#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout; using std::endl; using std::cerr;
using std::string; using std::vector; using std::begin; using std::end;

// Exercise 4.1
int ex4_1()
{
	cout << 5 + 10 * 20/2 << endl;
	
	return 0;
}

// Exercise 4.4
int ex4_4()
{
	cout << 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2 << endl;

	return 0;
}

// Exercise 4.5
int ex4_5()
{
	cout << -30 * 3 + 21 / 5 << endl;
	cout << -30 + 3 * 21 / 5 << endl;
	cout << 30 / 3 * 21 % 5 << endl;
	cout << -30 / 3 * 21 % 4 << endl;
	
	return 0;
}

// Exercise 4.9
int ex4_9()
{
	const char *cp = "Hello World";
	
	if (cp && *cp) {
		cout << cp << endl;
		cout << *cp << endl;
	}
	
	return 0;
}

// Exercise 4.10
int ex4_10()
{
	int i;
	
	while (cin >> i && i != 42)
		cout << i << endl;
	
	return 0;
}

// Exercise 4.11
int ex4_11()
{
	int a, b, c, d;
	cout << "Enter 4 integers: " << endl;
	cin >> a >> b >> c >> d;
	
	if (a > b && b > c && c > d)
		cout << "True!" << endl;
	else
		cout << "False!" << endl;
	
	return 0;
}

// Exercise 4.12
int ex4_12()
{
	int i, j, k;
	cout << "Enter 3 integers i, j, k:" << endl;
	cin >> i >> j >> k;
	
	if (i != (j < k))
		cout << "if j < k, i != 1 OR if j >=k, i != 0" << endl;
	
	return 0;
}

// Exercise 4.13
int ex4_13()
{
	int i; double d;
	
	//d = i = 3.5;
	i = d = 3.5;
	cout << "d = " << d << " i = " << i << endl;
	
	return 0;
}

// Exercise 4.15
int ex4_15()
{
	//double dval; int ival; int *pi;
	
	//dval = ival = 0; pi = 0;

	return 0;
}

// Exercise 4.20
int ex4_20()
{
	vector<string> svec{"Hello world!", "Good morning America!", "Hi there."};
	
	auto iter = svec.begin();
	
	//cout << *iter++ << endl;
	//cout << (*iter)++ << endl;
	//if (iter->empty())
	//	cout << "empty!" << endl;
	
	//cout << ++*iter << endl;
	if (iter++->empty())
		cout << "empty!" << endl;
	cout << *iter << endl;
	
	return 0;
}

// Exercise 4.21
int ex4_21()
{
	vector<int> ivec{1, 2 ,3 ,4 ,5 ,6};

	for (auto e : ivec)
		cout << e << " ";
	cout << endl;
	
	for (auto it = ivec.begin(); it != ivec.end(); ++it)
		if (*it % 2 == 1)
			*it = *it * 2;
	
	for (auto e : ivec)
		cout << e << " ";
	cout << endl;
	
	return 0;
}

// Exercise 4.22
int ex4_22()
{
	int grade;
	string finalgrade;
	
	cout << "Enter an integer as grade: " << endl;
	cin >> grade;
	
	// Method 1: only use conditional operators
	//finalgrade = (grade > 90) ? "high pass" : (grade > 75) ? "pass" : (grade >= 60) ? "low pass" : "fail";
	
	// Method 2: only use if statements
	if (grade > 90)
		finalgrade = "high pass";
	else if (grade > 75)
		finalgrade = "pass";
	else if (grade >=60)
		finalgrade = "low pass";
	else
		finalgrade = "fail";
	
	cout << finalgrade << endl;
	
	return 0;
}

// Exercise 4.23
int ex4_23()
{
	string s = "word";
	string p1 = (s + s[s.size() -1] == "s") ? "" : "s";

	cout << p1 << endl;
	
	return 0;
}

// Exercise 4.24
int ex4_24()
{
	//int grade = 60;
	
	//string finalgrade = (grade > 90) ? "high pass" : (grade < 60);
		
	return 0;
}

// Exercise 4.25
int ex4_25()
{
	//cout << sizeof(int) << " " << sizeof(char) << endl;
	int i = 0xFFFFE380;
	
	cout << (~'q' << 6) << endl;
	
	cout << i << endl;
	
	return 0;
}

// Exercise	4.27
int main()
{
	unsigned long ul1 = 3, ul2 = 7;
	
	cout << (ul1 & ul2) << endl;	// 3
	cout << (ul1 | ul2) << endl;	// 7
	cout << (ul1 && ul2) << endl;	// 1	
	cout << (ul1 || ul2) << endl;	// 1 
	
	return 0;
}


