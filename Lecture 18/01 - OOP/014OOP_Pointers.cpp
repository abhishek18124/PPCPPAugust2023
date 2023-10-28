#include<iostream>

using namespace std;

class customer {

public :

	string name;
	int age;
	char gender;
	double credits;

	customer(string n, int a, char g, double c) {
		cout << "\ninside parameterised constructor of \'customer\' class\n";
		name = n;
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

};

int main() {

	customer c("misaka", 19, 'F', 500);

	cout << &c << endl;

	customer* cptr = &c;

	cout << "name = " << (*cptr).name << " " << cptr->name << endl;
	cout << "name = " << (*cptr).age << " " << cptr->age << endl;
	cout << "name = " << (*cptr).gender << " " << cptr->gender << endl;
	cout << "name = " << (*cptr).credits << " " << cptr->credits << endl;

	(*cptr).printCustomerInfo();

	cptr->printCustomerInfo();

	return 0;
}