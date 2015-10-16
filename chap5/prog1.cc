#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using std::cin; using std::cout; using std::endl; using std::cerr;
using std::string; using std::vector; using std::begin; using std::end;
using std::runtime_error;

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

// Exercise 5.11
int ex5_11()
{
	unsigned sCnt = 0;
	string str;
	
	while (getline(cin, str)) {
		for (auto ch : str)
			if (isspace(ch))
				++sCnt;
	}
	
	cout << "Number of blank spaces: \t" << sCnt << endl;
	
	return 0;
}

// Exercise 5.12: version 1
int ex5_12_v1()
{
	unsigned ffCnt = 0, flCnt = 0, fiCnt = 0;
	string str;
	bool first_f_Found = false;
	
	while (getline(cin, str)) {
		for (auto ch : str) {
			if (!first_f_Found && ch == 'f') {
				first_f_Found = true;
				continue;
			}
				
			if (first_f_Found) {
				if (ch == 'f')
					++ffCnt;
				else if (ch == 'l')
					++flCnt;
				else if (ch == 'i')
					++fiCnt;
				else
					;	// do nothing here.
				
				first_f_Found = false;
			}
		}
	}
	
	cout << "Number of sequence ff: \t" << ffCnt << '\n'
		 << "Number of sequence fl: \t" << flCnt << '\n'
		 << "Number of sequence fi: \t" << fiCnt << endl;
	
	return 0;
}

// Exercise 5.12: version 2
int ex5_12_v2()
{
	unsigned ffCnt = 0, flCnt = 0, fiCnt = 0;
	string str;
	
	while (getline(cin, str)) {
		for (auto it = str.cbegin(); it != str.cend(); ++it) {
			if (*it == 'f' && (it + 1 != str.cend())) {
				if (*(it + 1) == 'f')
					++ffCnt;
				else if (*(it + 1) == 'l')
					++flCnt;
				else if (*(it + 1) == 'i')
					++fiCnt;
				else
					continue;
				
				++it;
			}
		}
	}
	
	cout << "Number of sequence ff: \t" << ffCnt << '\n'
		 << "Number of sequence fl: \t" << flCnt << '\n'
		 << "Number of sequence fi: \t" << fiCnt << endl;
	
	return 0;
}

// Exercise 5.13
int ex5_13()
{
	// (a)
	//unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
	//char ch = next_text();
	//switch (ch) {
	//	case 'a': 
	//		aCnt++;
	//		break;
	//	case 'e':
	//		eCnt++;
	//		break;
	//	default:
	//		iouCnt++;
	//		break;
	//}
	
	// (b)
	//unsigned index = 2;
	//vector<unsigned> ivec{0, 0, 0, 0, 0}; 
	
	//switch (index) {
	//	case 1:
	//	{
	//		int ix = 0;
	//		ivec[ix] = index;
	//		break;
	//	}
	//	default:
	//	{
	//		int ix = ivec.size() - 1;
	//		ivec[ix] = index;
	//	}
	//}

	// (c)
	//unsigned evenCnt = 0, oddCnt = 0;
	//int digit = 12 % 10;
	//switch (digit) {
	//	case 1: case 3: case 5: case 7: case 9:
	//		oddCnt++;
	//		break;
	//	case 2: case 4: case 6: case 8: case 10:
	//		evenCnt++;
	//		break;
	//}
	//cout << "evenCnt = " << evenCnt << "	oddCnt = " << oddCnt << endl;
	
	// (d)
	constexpr unsigned ival = 512, jval = 1024, kval = 4096;
	unsigned bufsize;
	unsigned swt = 1024;
	switch (swt) {
		case ival:
			bufsize = ival * sizeof(int);
			break;
		case jval:
			bufsize = jval * sizeof(int);
			break;
		case kval:
			bufsize = kval * sizeof(int);
			break;
		default:
			bufsize = 0;
			break;
	}
	
	cout << bufsize << endl;
	
	return 0;
}

// Exercise 5.14
int ex5_14()
{
	string word, currWord, maxWord;
	unsigned dupCnt = 1;
	unsigned maxDupCnt = 1;
	
	cout << "Enter a sequence of words: " << endl;
	// read in the first word:
	cin >> currWord; maxWord = currWord;
	if (currWord.empty())
		return 0;

	// keep reading in other words:
	while (cin >> word) {
		if (word == currWord) {
			++dupCnt;
			if (dupCnt > maxDupCnt) {
				maxDupCnt = dupCnt;
				maxWord = currWord;
			}
		}
		else {
			dupCnt = 1;
			currWord = word;
		}
	}

	cout << "The word: " << maxWord << " occured " << maxDupCnt << " times." << endl;
	
	return 0;
}

// Exercise 5.15
int ex5_15()
{
	// (a)
	int sz = 10;
	//int ix = 0;
	//for ( ; ix != sz; ++ix)
	//	;
	
	//if (ix != sz)
	//	;
	
	// (b)
	//int ix;
	//for (ix = 0; ix != sz; ++ix)
	//	;
	
	// (c)
	for (int ix = 0; ix != sz; ++ix /*, ++sz*/)
		;
	
	
	//cout << ix << endl;
	
	return 0;
}

// Exercise 5.16
int ex5_16()
{
	// idiomatic use of while loop
	//char ch;
	//while (cin >> ch)
	//	cout << ch;
	//cout << endl;
	
	// idiomatic use of for loop
	//string str = "Hello world!";
	//for (decltype(str.size()) i = 0; i != str.size(); ++i)
	//	cout << str[i];
	//cout << endl;
	
	// rewrite the first loop using for loop:
	//char ch;
	//for (; cin >> ch; )
	//	cout << ch;
	//cout << endl;

	// rewrite the second loop using while loop:
	string str = "Hello world!";
	decltype(str.size()) i = 0;
	while (i != str.size()) {
		cout << str[i];
		++i;
	}
	cout << endl;
	
	return 0;
}

// Exercise 5.17
int ex5_17()
{
	vector<int> ivec1{0, 1, 1, 2};
	vector<int> ivec2{0, 1, 1, 2, 4, 7, 8};
	auto sz1 = ivec1.size(); auto sz2 = ivec2.size();
	auto cmpLen = (sz1 <= sz2) ? sz1 : sz2;
	
	decltype(sz1) ix = 0;
	while (ix != cmpLen && ivec1[ix] == ivec2[ix])
		++ix;
	
	if (ix == cmpLen)
		cout << "True!" << endl;
	else
		cout << "False!" << endl;
	
	return 0;
}

// Exercise 5.18
int ex5_18()
{
	int ival = 0;
	
	do {
		cout << ival << endl;
	} while (++ival != 10);
	
	return 0;
}

// Exercise 5.19
int ex5_19()
{
	string str1, str2;
	
	do {
		cout << "Enter two strings: " << endl;
		cin >> str1 >> str2;
		
		if (str1.size() < str2.size())
			cout << "str1 is less than str2!" << endl;
		else
			cout << "str2 is less than str1!" << endl;
		
	} while(cin);
	
	return 0;
}

// Exercise 5.20
int ex5_20()
{
	string word, currWord;

	cout << "Enter a sequence of words: " << endl;
	// read in the first word:
	cin >> currWord;
	
	// keep reading the other words:
	while (cin >> word) {
		if (word == currWord) {
			cout << word << endl;
			break;
		}
		else {
			cout << "No word was repeated!" << endl;
			currWord = word;
		}
	}
	
	return 0;
}

// Exercise 5.21
int ex5_21()
{
	string word, currWord;

	cout << "Enter a sequence of words: " << endl;
	// read in the first word:
	cin >> currWord;
	
	// keep reading the other words:
	while (cin >> word) {
		// if the word doesn't start with an uppercase letter, don't compare, move on to the next word:
		if (!isupper(word[0])) {
			currWord = word;
			continue;
		}
		
		if (word == currWord) {
			cout << word << endl;
			break;
		}
		else {
			cout << "No word was repeated!" << endl;
			currWord = word;
		}
	}
	
	return 0;
}

// Exercise 5.22
int ex5_22()
{
	int sz;
	
	while (cin >> sz) {
		if (sz > 0)
			break;
	}
	
	return 0;
}

// Exercise 5.23, 5.24
int ex5_24()
{
	int ival1, ival2;
	
	cout << "Enter two integers: " << endl;
	cin >> ival1 >> ival2;
	
	// first check if the second integer is 0 or not
	if (ival2 == 0)
		throw runtime_error("ival2 must not be zero!");
		
	// if we are still here, ival2 is not zero
	cout << ival1 / ival2 << endl;
	
	return 0;
}

// Exercise 5.25
int main()
{
	int ival1, ival2;
	
	cout << "Enter two integers: " << endl;
	while (cin >> ival1 >> ival2) {
		try {
			// first check if the second integer is 0 or not
			if (ival2 == 0)
				throw runtime_error("ival2 must not be zero!");
				
			// if we are still here, ival2 is not zero
			cout << ival1 / ival2 << endl;
		} catch (runtime_error err) {
			// remind the user that the second integer must not be zero and prompt for another pair of input_iterator
			cout << err.what() << "\nTry again? Enter y or n" << endl;
			
			char c;
			cin >> c;
			if (!cin || c == 'n')
				break;
		}
	}
	
	return 0;
}


