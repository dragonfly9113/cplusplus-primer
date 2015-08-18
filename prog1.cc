#include <iostream>

int main()
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

