#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	// computing the size or length of a string

	string str = "coding blocks";

	cout << str.length() << endl;
	cout << str.size() << endl;

	// // appending / concatnating str2 to str1

	// string str1 = "new";
	// string str2 = "delhi";

	// // // 1. using append()

	// // str1.append(str2);
	// // cout << str1 << " " << str2 << endl;

	// // 2. using '+' operator

	// str1 = str1 + " " + str2;
	// cout << str1 << endl;

	// // // comparing two strings

	// string str3 = "abcde";
	// string str4 = "abc";

	// // 1. using compare
	// cout << str3.compare(str4) << endl;

	// // 2. using relational operators
	// if (str3 > str4) {
	// 	cout << str3 << " is greater" << endl;
	// } else {
	// 	cout << str4 << " is greater" << endl;
	// }

	string str6 = "india vs pakistan";

	cout << str6.substr(1, 3) << endl;
	cout << str6.substr(9, 3) << endl;
	cout << str6.substr(6) << endl;

	return 0;
}