#include <iostream>

// Exercise 2.4
int ex2_4()
{
	unsigned u = 10, u2 = 42;
	std::cout << u2 - u << std::endl;
	std::cout << u - u2 << std::endl;

	int i = 10, i2 = 42;
	std::cout << i2 - i << std::endl;
	std::cout << i - i2 << std::endl;
	
	std::cout << i - u << std::endl;
	std::cout << u - i << std::endl;
		
	return 0;
}

// Exercise 2.8
int ex2_8()
{
	std::cout << "2\115\n";
	std::cout << "2\t\115\n";
	
	return 0;
}

// Exercise 2.9
int ex2_9()
{
	int input_value;
	std::cin >> input_value;
	//int i = {3.14};
	double salary = 9999.99, wage = salary;
	int i = 3.14;
	
	std::cout << "salary = " << salary << " wage = " << wage << std::endl;
	std::cout << "i = " << i << std::endl;
	
	return 0;
}

// Exercise 2.10
std::string global_str;
int global_int;

int ex2_10()
{
	int local_int = 0;
	std::string local_str;
	
	std::cout << global_str << std::endl;
	std::cout << global_int << std::endl;
	std::cout << local_int << std::endl;
	std::cout << local_str << std::endl;
	
	return 0;
}

// Exercise 2.14
int ex2_14()
{
	int i = 100, sum = 0;
	for (int i = 0; i != 10; ++i)
		sum += i;
	
	std::cout << i << " " << sum << std::endl;
	
	return 0;
}

// Exercise 2.16
int ex2_16()
{
	int i = 0, &r1 = i;
	double d = 0, &r2 = d;

	r2 = 3.14159;
	r2 = r1;
	i = r2;
	r1 = d;
	
	return 0;
}

// Exercise 2.17
int ex2_17()
{
	int i, &ri = i;
	i = 5;
	ri = 10;
	
	std::cout << i << " " << ri << std::endl;
	
	return 0;
}

// Exercise 2.18
int ex2_18()
{
	int i1 = 10, i2 = 20;
	int *pi1 = &i1, *pi2 = &i2;
	
	pi1 = &i2;
	std::cout << *pi1 << std::endl;
	
	*pi2 = i1;
	std::cout << *pi2 << std::endl;
	
	return 0;
}

// Exercise 2.20
int main()
{
	int i = 42;
	int *p1 = &i;
	*p1 = *p1 * *p1;
	
	std::cout << i << std::endl;
	
	return 0;
}


