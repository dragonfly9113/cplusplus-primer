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
