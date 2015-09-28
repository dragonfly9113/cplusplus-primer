#include <iostream>
#include <string>

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
int ex2_20()
{
	int i = 42;
	int *p1 = &i;
	*p1 = *p1 * *p1;
	
	std::cout << i << std::endl;
	
	return 0;
}

// Exercise 2.27
int ex2_27()
{
	//int i = -1;
	//int i2 = 0;
	//int i = -1, &r = 0;
	//int *const p2 = &i2;
	//const int i = -1, &r = 0;
	//const int *const p3 = &i2;
	//const int *p1 = &i2;
	//const int &const r2;
	//const int i2 = i, &r = i;
	
	return 0;
}

// Exercise 2.28
int ex2_28()
{
	//int i, *const cp;
	//int *p1, *const p2;
	//const int ic, &r = ic;
	//const int *const p3;
	//const int *p;
		
	return 0;
}

// Exercise 2.29
int ex2_29()
{
	//int i;
	//const int ic = 10;
	//int *p1, *const p2 = &i;
	//const int *const p3 = &i;
	
	//i = ic;
	//p1 = p3;
	//p1 = &ic;
	//p3 = &ic;
	//p2 = p1;
	//ic = *p3;
	
	return 0;
}

// Exercise 2.31
int ex2_31()
{
	//const int v2 = 0; int v1 = v2;
	//int *p1 = &v1, &r1 = v1;
	//const int *p2 = &v2, *const p3 = &v1, &r2 = v2;
	
	//r1 = v2;
	//p1 = p2; p2 = p1;
	//p1 = p3; p2 = p3;
	
	return 0;
}

// Exercise 2.32
int ex2_32()
{
	//int null = 0, *p = null;
	//int *p = 0;
	//int *p = nullptr;
	
	return 0;
}

// Exercise 2.33
int ex2_33()
{
	//int i = 0, &r = i;
	//auto a = r;
	
	//const int ci = i, &cr = ci;
	//auto b = ci;
	//auto c = cr;
	//auto d = &i;
	//auto e = &ci;
	//auto &g = ci;
	
	//a = 42; b = 42; c = 42;
	//d = 42; e = 42; g = 42;
		
	return 0;
}

// Exercise 2.35
int ex2_35()
{
	//const int i = 42;
	//auto j = i; const auto &k = i; auto *p = &i;
	//const auto j2 = i, &k2 = i;
	
	//std::cout << k2 << std::endl;
	//k2 = 32;
	//std::cout << k2 << std::endl;
	
	return 0;
}

// Exercise 2.36
int ex2_36()
{
	int a = 3, b = 4;
	decltype(a) c = a;
	decltype((b)) d = a;
	++c;
	++d;
	
	std::cout << a << std::endl;	// 4
	std::cout << b << std::endl;	// 4
	std::cout << c << std::endl;	// 4
	std::cout << d << std::endl;	// 4
	
	return 0;
}

// Exercise 2.37
int ex2_37()
{
	int a = 3, b = 4;
	decltype(a) c = a;
	decltype(a = b) d = a;
	
	std::cout << a << std::endl;	// 3
	std::cout << b << std::endl;	// 4
	std::cout << c << std::endl;	// 3
	std::cout << d << std::endl;	// 3
	
	return 0;
}

// Exercise 2.38
int ex2_38()
{
	int a = 3, b = 4;
	// auto and decltype deduce the same type for c and d
	auto c = a;
	decltype(a) d = a;
	
	auto e = b;	// e has type int
	decltype((b)) f = b; // f has type int&
	
	++c; ++d; ++e; ++f;
	std::cout << b << std::endl;
		
	return 0;
}

// Exercise 2.39
int ex2_39()
{
	struct Foo {}; // semicolon is necessary for class definition
	
	return 0;
}

// Exercise 2.40
int ex2_40()
{
	struct Sales_data {
		std::string isbn;
		unsigned units_sold;
		double sale_price;
	};
	
	return 0;
}

// Exercise 2.41
struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

// Exercise 2.41: Redo exercise section 1.5.1 using Sales_data
int ex2_41_1()
{
	Sales_data data;
	
	double price = 0;
	std::cout << "Read in a set of book transactions:" << std::endl;
	while(std::cin >> data.bookNo >> data.units_sold >> price) {
		data.revenue = data.units_sold * price;
		// writing each transaction to the standard output:
		std::cout << data.bookNo << " " << data.units_sold << " " << data.revenue << std::endl;
	}

	return 0;
}

int ex2_41_2()
{
	Sales_data data1, data2;
	
	double price = 0;
	std::cout << "Enter two book sale transactions:" << std::endl;
	// read in the first book transaction
	std::cin >> data1.bookNo >> data1.units_sold >> price;
	data1.revenue = data1.units_sold * price;
	
	// read in the second book transaction
	std::cin >> data2.bookNo >> data2.units_sold >> price;
	data2.revenue = data2.units_sold * price;
		
	if (data1.bookNo == data2.bookNo) {
		unsigned totalCnt = data1.units_sold + data2.units_sold;
		double totalRevenue = data1.revenue + data2.revenue;
		
		std::cout << data1.bookNo << " " << totalCnt << " " << totalRevenue << std::endl;
		
		return 0;
	} else {
		std::cerr << "Data must refer to the same ISBN" << std::endl;
		
		return -1;
	}
}

int ex2_41_3()
{
	Sales_data data;
	Sales_data total;
	
	double price = 0;
	std::cout << "Enter several book sale transactions with the same ISBN:" << std::endl;
	while(std::cin >> data.bookNo >> data.units_sold >> price) {
		data.revenue = data.units_sold * price;
		// sum up and save to total
		total.units_sold += data.units_sold;
		total.revenue += data.revenue;
	}
	
	std::cout << data.bookNo << " " << total.units_sold << " " << total.revenue << std::endl;

	return 0;
}

// Exercise 2.41: Redo exercise section 1.5.2 using Sales_data
int ex2_41_4()
{
	Sales_data data, currData;
	int cnt;
	double price = 0;
	
	std::cout << "Enter several book sale transactions:" << std::endl;
	// read in the first transaction:
	if(std::cin >> currData.bookNo >> currData.units_sold >> price) {
		cnt = 1;
		
		// read in other transactions:
		while(std::cin >> data.bookNo >> data.units_sold >> price) {
			if(data.bookNo == currData.bookNo)	// if this transaction has the same isbn 
				++cnt;
			else {	// if this transaction has a different isbn
				std::cout << "isbn: " << currData.bookNo << " transaction number: " << cnt << std::endl; 
			
				//currBook = book;
				currData.bookNo = data.bookNo;
				currData.units_sold = data.units_sold;
				currData.revenue = data.revenue;
				
				cnt = 1;
			}
		}
		
		// no more transactions
		std::cout << "isbn: " << currData.bookNo << " transaction number: " << cnt << std::endl; 		
	}

	return 0;
}

// Exercise 2.41: Redo exercise section 1.6 using Sales_data
// To do: modify the following function to use Sales_data
int main()
{
	Sales_data total;
	double price = 0;
	
	// read in the first record and see if it is valid:
	if(std::cin >> total.bookNo >> total.units_sold >> price) {
		total.revenue = total.units_sold * price;
		Sales_data trans;
		double avg_price;
		
		// read in other records
		while(std::cin >> trans.bookNo >> trans.units_sold >> price) {
			trans.revenue = trans.units_sold * price;
			
			if(trans.bookNo == total.bookNo) { // if this isbn is the same, update the total
				total.units_sold += trans.units_sold;
				total.revenue += trans.revenue;
			}
			else { 		// if this isbn is different, print out the last total and reset
				avg_price = (total.units_sold == 0) ? 0.0 : total.revenue / total.units_sold;
				std::cout << total.bookNo << " " << total.units_sold << " " << total.revenue << " " << avg_price << std::endl;
				
				total.bookNo = trans.bookNo;
				total.units_sold = trans.units_sold;
				total.revenue = trans.revenue;
			}
		}
		
		// print the last trans:
		avg_price = (total.units_sold == 0) ? 0.0 : total.revenue / total.units_sold;
		std::cout << total.bookNo << " " << total.units_sold << " " << total.revenue << " " << avg_price << std::endl;
	}
	else {
		std::cerr << "No data?!" << std::endl;
		return -1;
	}
	
	return 0;
}
