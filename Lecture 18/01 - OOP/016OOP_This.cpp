#include<iostream>

using namespace std;

class customer {

public :

	string name;
	int age;
	char gender;
	double credits;

	customer() {
		cout << "\ninside default constructor of \'customer\' class\n";
	}

	customer(string name, int age, char gender, double credits) {
		cout << "\ninside parameterised constructor of \'customer\' class\n";
		this->name = name;
		this->age = age;
		this->gender = gender;
		this->credits = credits;
	}

	void printCustomerInfo() {
		cout << "\nCustomer Information\n";
		cout << "Name : " << name << endl;
		cout << "Age : " << age << endl;
		cout << "Gender : " << gender << endl;
		cout << "Credits : " << credits << endl;
	}

};


int main() {

	customer c("reiner", 21, 'M', 300);

	c.printCustomerInfo();

	return 0;
}