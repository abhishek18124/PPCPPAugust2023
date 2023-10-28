#include<iostream>

using namespace std;

class customer {
public :
	char* name;
	int age;
	char gender;
	double credits;

	customer(char* n, int a, char g, double c) {
		cout << "I am inside the parameterised constructor of the customer class" << endl;
		name = new char[100];
		strcpy(name, n);
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

	customer(customer& c) {
		cout << "I am inside the copy constructor of the customer class" << endl;
		name = new char[100];
		strcpy(name, c.name);
		age = c.age;
		gender = c.gender;
		credits = c.credits;
	}



};

int main() {

	customer c1("neil", 18, 'M', 100000);

	customer c2 = c1;

	c2.printCustomerInfo();

	c2.age = 20;
	c2.gender = 'F';
	c2.credits = 1000;

	c2.printCustomerInfo();

	c1.printCustomerInfo();

	strcpy(c2.name, "Joyeta");

	c2.printCustomerInfo();

	c1.printCustomerInfo();

	return 0;
}