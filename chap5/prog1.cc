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

