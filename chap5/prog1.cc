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
int ex5_7()
{
	int ival1 = 0, ival2 = 0;
	
	if (ival1 != ival2)
		ival1 = ival2;
	else 
		ival1 = ival2 = 0;
	
	return 0;
}

// Exercise 5.9 and 5.10
int ex5_10()
{
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	char ch;
	
	while (cin >> ch) {
		if (ch == 'a' || ch == 'A')
			++aCnt;
		else if (ch == 'e' || ch == 'E')
			++eCnt;
		else if (ch == 'i' || ch == 'I')
			++iCnt;
		else if (ch == 'o' || ch == 'O')
			++oCnt;
		else if (ch == 'u' || ch == 'U')
			++uCnt;
		else
			; // do nothing in else case.
	}
		
	cout << "Number of vowel a: \t" << aCnt << '\n'
		 << "Number of vowel e: \t" << eCnt << '\n'
		 << "Number of vowel i: \t" << iCnt << '\n'
		 << "Number of vowel o: \t" << oCnt << '\n'
		 << "Number of vowel u: \t" << uCnt << endl;
	
	return 0;
}

// isspace example
int example()
{
	char c;
	int i = 0, sCnt = 0, tCnt = 0, nCnt = 0;
	char str[] = "Example sentence to test		isspace\n";
	while (str[i]) {
		c = str[i];
		if (c == ' ')
			++sCnt;			
		else if (c == '\t')
			++tCnt;
		else if (c == '\n')
			++nCnt;
		++i;
	}

	cout << sCnt << " " << tCnt << " " << nCnt << endl;
	
	return 0;
}

// Exercise 5.11
int main()
{
	unsigned sCnt = 0;
	char ch;
	
	while (cin >> ch) {
		if (ch == ' ')
			++sCnt;
		
		cout << ch;
	}
	
	cout << endl;	
	cout << "Number of spaces: \t" << sCnt << endl;
	
	return 0;
}

