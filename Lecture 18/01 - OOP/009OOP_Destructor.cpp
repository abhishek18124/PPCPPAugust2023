#include<iostream>

using namespace std;

class customer {
public :
	char* name; // it is allocated memory on the heap
	int age;
	char gender;
	double credits;

	customer(char* n, int a, char g, double c) {
		cout << "I am inside the parameterised constructor of the customer class" << endl;
		name = new char[100];
		strcpy(name, n);
		cout << "constructing " << name << endl;
		age = a;
		gender = g;
		credits = c;
	}

	void printCustomerInfo() {
		cout << "\nCustomer Information\n";
		cout << "Name : " << name << endl;
		cout << "Age : " << age << endl;
		cout << "Gender : " << gender << endl;
		cout << "Credits : " << credits << endl;
	}

	~customer() {
		// cout << "I am inside the destructor" << endl;
		cout << "destructing " << name << endl;
		delete [] name;
	}

};

int main() {

	customer c1("keshav", 19, 'M', 1000);

	customer c2("neil", 18, 'M', 100000);

	return 0;
}