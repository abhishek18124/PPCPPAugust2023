#include<iostream>

using namespace std;

int main() {

	int marks;
	cout << "enter your marks : ";
	cin >> marks;

	char grade;

	if (marks >= 91 and marks <= 100) {
		cout << "grade A" << endl;
		grade = 'A';
	} else if (marks >= 81 and marks <= 90) {
		cout << "grade B" << endl;
		grade = 'B';
	} else if (marks >= 71 and marks <= 80) {
		cout << "grade C" << endl;
		grade = 'C';
	} else if (marks >= 61 and marks <= 70) {
		cout << "grade D" << endl;
		grade = 'D';
	} else {
		cout << "grade F" << endl;
		grade = 'F';
	}

	cout << "you are outside the if-else-if block" << endl;

	// if (grade == 'A') {
	// 	cout << "very good" << endl;
	// } else if (grade == 'B') {
	// 	cout << "good" << endl;
	// } else if (grade == 'C') {
	// 	cout << "average" << endl;
	// } else if (grade == 'D') {
	// 	cout << "poor" << endl;
	// } else if (grade == 'F') {
	// 	cout << "very poor" << endl;
	// }

	switch (grade) {

	case 'A' : cout << "very good" << endl; break;
	case 'B' : cout << "good" << endl; break;
	case 'C' : cout << "average" << endl; break;
	case 'D' : cout << "poor" << endl; break;
	case 'F' : cout << "very poor" << endl; break;
	default : cout << "invalid grade" << endl; break;

	}

	return 0;
}