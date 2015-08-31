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
	int local_int;
	std::string local_str;
	
	std::cout << global_str << std::endl;
	std::cout << global_int << std::endl;
	std::cout << local_int << std::endl;
	std::cout << local_str << std::endl;
	
	return 0;
}

// Exercise 2.14
int main()
{
	int i = 100, sum = 0;
	for (int i = 0; i != 10; ++i)
		sum += i;
	
	std::cout << i << " " << sum << std::endl;
}


