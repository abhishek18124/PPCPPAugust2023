#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class customer {

public:

	string name;
	int age;
	char gender;
	double credits;

	customer(string name, int age, char gender, double credits) {
		this->name = name;
		this->age = age;
		this->gender = gender;
		this->credits = credits;
	}
};

/*
	return 'true' when a swap isn't required.

*/

bool myCreditsComparator(customer c1, customer c2) {
	if (c1.credits > c2.credits) {
		// you don't need a swap to sort v[] in decreasing order based on credits
		return true;
	}
	// you need a swap to sort v[] in decreasing order based on credits
	return false;

}

bool myAgeComparator(customer c1, customer c2) {
	if (c1.age < c2.age) {
		// you don't need a swap to sort v[] in increasing order based on age
		return true;
	}
	// you need a swap to sort v[] in increasing order based on age
	return false;

}

int main() {

	vector<customer> v;

	v.push_back(customer("neil", 18, 'M', 100000));
	v.push_back(customer("keshav", 20, 'M', 20000));
	v.push_back(customer("joyeta", 19, 'F', 10000000));
	v.push_back(customer("abhishek", 28, 'M', 100));
	v.push_back(customer("ridhi", 17, 'F', 50000000));

	// sort(v.begin(), v.end(), myCreditsComparator);

	sort(v.begin(), v.end(), myAgeComparator);

	for (customer c : v) {
		cout << c.name << " " << c.age << " " << c.gender << " " << c.credits << endl;
	}



	return 0;
}