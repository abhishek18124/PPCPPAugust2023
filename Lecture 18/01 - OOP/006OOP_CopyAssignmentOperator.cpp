#include<iostream>

using namespace std;

class customer {
public :
	char name[100];
	int age;
	char gender;
	double credits;

	customer() {
		cout << "I am inside the default constructor of the customer class" << endl;
	}

	customer(customer& c) {
		cout << "I am inside the copy constructor of the customer class" << endl;
		strcpy(name, c.name);
		age = c.age;
		gender = c.gender;
		credits = c.credits;
	}

	customer(char* n, int a, char g, double c) {
		cout << "I am inside the parameterised constructor of the customer class" << endl;
		strcpy(name, n);
		age = a;
		gender = g;
		credits = c;
	}

	void operator=(const customer& c) {
		cout << "I am inside the copy assignment operator of the customer class" << endl;
		strcpy(name, c.name);
		age = c.age;
		gender = c.gender;
		credits = c.credits;
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

	customer c1("naruto", 32, 'M', 5000);

	customer c3;
	c3 = c1; // default copy assignment operator function is invoked

	return 0;
}