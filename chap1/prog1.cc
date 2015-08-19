#include <iostream>
#include "Sales_item.h"

int ex1_4_1()
{
//	std::cout << "Enter two numbers:" << std::endl;
//	int v1 = 0, v2 = 0;
//	std::cin >> v1 >> v2;
	
//	std::cout << "The sum of " << v1 << " and " << v2
//		 << " is " << v1 + v2 << std::endl;

//	std::cout << "The product of " << v1;
//	std::cout << " and " << v2;
//	std::cout << " is " << v1 * v2 << std::endl;

// Exercises section 1.3 
//	std::cout << "/*";
//	std::cout << "*/";
//	std::cout << /* "*/" */ ";
//	std::cout << /* "*/" /* "/*" */; 

// Exercises section 1.4.1
	int sum = 0, cnt = 50;
	while(cnt <= 100)	{
		sum += cnt;
		++cnt;
	}
	std::cout << "The sum from 50 to 100 is " << sum << std::endl;
	
	cnt = 10;
	while(cnt >= 0) {
		std::cout << cnt << std::endl;
		--cnt;
	}
	
	std::cout << "Enter two numbers:" << std::endl;
	int v1 = 0, v2 = 0;
	std::cin >> v1 >> v2;
	
	while(v1 <= v2) {
		std::cout << v1 << std::endl;
		++v1;
	}
	
	return 0;
}

int ex1_4_2()
{
	// Exercises section 1.4.2
	int sum = 0;
	for(int i = -100; i <= 100; ++i)
		sum += i;
	
	std::cout << sum << std::endl;

	std::cout << "Enter two numbers:" << std::endl;
	int v1 = 0, v2 = 0;
	std::cin >> v1 >> v2;
	for(int i = v1; i <= v2; ++i)
		std::cout << i << std::endl;
	
	return 0;
}

int example1_4()
{
	int sum = 0, value = 0;
	std::cout << "Enter integers to add up. Ctrl-D to stop." << std::endl;
	while(std::cin >> value)
		sum += value;
	std::cout << "Sum is: " << sum << std::endl;
	
	return 0;
}

// Count how many consecutive times each distinct value appears in the input:
int ex1_4_4()
{
	int currVal = 0, val = 0;
	if (std::cin >> currVal) {
		int cnt = 1;
		while(std::cin >> val) {
			if (val == currVal)
				++cnt;
			else {
				std::cout << currVal << " occurs "
						<< cnt << " times" << std::endl;
				currVal = val;
				cnt = 1;
			}
		}
		
		std::cout << currVal << " occurs "
				<< cnt << " times" << std::endl;
	}
	
	return 0;
}

int ex1_19()
{
	std::cout << "Enter two numbers:" << std::endl;
	int v1 = 0, v2 = 0;
	std::cin >> v1 >> v2;
	
	if(v1 < v2) {
		while(v1 < v2) {
			std::cout << v1 << std::endl;
			++v1;
		}
	}
	else
		std::cout << "The first number should be smaller than the second one." << std::endl;
	
	return 0;
}

// Exercise 1.20
int ex1_20()
{
	Sales_item book;

	std::cout << "Read in a set of book transactions:" << std::endl;
	while(std::cin >> book) {
		// writing each transaction to the standard output:
		std::cout << book << std::endl;
	}

	return 0;
}

// Exercise 1.21
int ex1_21()
{
	Sales_item book1, book2;
	
	std::cout << "Enter two book sale transactions:" << std::endl;
	std::cin >> book1 >> book2;
	std::cout << book1 + book2 << std::endl;
	
	return 0;
}

// Exercise 1.22
int ex1_22()
{
	Sales_item book;
	Sales_item total;
	
	std::cout << "Enter several book sale transactions with the same ISBN:" << std::endl;
	while(std::cin >> book) {
		total += book;
	}

	std::cout << total << std::endl;
	
	return 0;
}

// Exercise 1.23: reads several transactions and counts how many transactions occur for each ISBN
int ex1_23()
{
	Sales_item book, currBook;
	int cnt;
	
	std::cout << "Enter several book sale transactions:" << std::endl;
	// read in the first transaction:
	if(std::cin >> book) {
		currBook = book;
		cnt = 1;
		
		// read in other transactions:
		while(std::cin >> book) {
			if(book.isbn() == currBook.isbn())	// if this transaction has the same isbn 
				++cnt;
			else {	// if this transaction has a different isbn
				std::cout << "isbn: " << currBook.isbn() << " transaction number: " << cnt << std::endl; 
			
				currBook = book;
				cnt = 1;
			}
		}
		
		// no more transactions
		std::cout << "isbn: " << currBook.isbn() << " transaction number: " << cnt << std::endl; 		
	}

	return 0;
}

// Exercise 1.25: The bookstore program
int main()
{
	Sales_item total;
	
	
	return 0;
}