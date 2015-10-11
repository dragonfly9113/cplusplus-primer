#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout; using std::endl; using std::cerr;
using std::string; using std::vector; using std::begin; using std::end;

// Exercise 5.3
int ex5_3()
{
	int sum = 0, val = 1;
	
	while (val <= 10)
		sum += val, ++val;
	
	cout << sum << endl;
	
	return 0;
}

// Exercise 5.5
int ex5_5()
{
	int grade;
	string letterGrade;
	vector<string> letterScale{"F", "D", "C", "B", "A", "A++"};
	
	cout << "Enter a grade (integer): " << endl;
	cin >> grade;
	
	if (grade < 60)
		letterGrade = letterScale[0];
	else
		letterGrade = letterScale[(grade - 50) / 10];
	
	cout << letterGrade << endl;
	
	return 0;
}

// Exercise 5.6
int ex5_6()
{
	int grade;
	string letterGrade;
	vector<string> letterScale{"F", "D", "C", "B", "A", "A++"};
	
	cout << "Enter a grade (integer): " << endl;
	cin >> grade;
	
	letterGrade = (grade < 60) ? letterScale[0] : letterScale[(grade - 50) / 10];
	
	cout << letterGrade << endl;
	
	return 0;
}

// Exercise 5.7
int main()
{
	int ival1 = 0, ival2 = 0;
	
	if (ival1 != ival2)
		ival1 = ival2;
	else 
		ival1 = ival2 = 0;
	
	return 0;
}


