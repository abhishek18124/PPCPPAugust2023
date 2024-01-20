/*

	STL implementation of the min_heap data structure with custom comparator.


*/

#include<iostream>
#include<queue>

using namespace std;

class customer {
public:
	string name;
	int age;

	customer(string name, int age) {
		this->name = name;
		this->age = age;
	}
};

class customerAgeFunctor {
public:
	bool operator()(customer a, customer b) {
		if (b.age < a.age) {
			// you need a swap to build a minHeap based on age
			return true;
		}

		// you don't need a swap
		return false;
	}
};


class customerNameFunctor {
public:
	bool operator()(customer a, customer b) {
		if (b.name > a.name) {
			// you need a swap to build a maxHeap based on name
			return true;
		}

		// you don't need a swap
		return false;
	}
};



int main() {

	// customerNameFunctor obj;

	// obj(c1, c2); // obj.operator()(c1, c2)

	// c1 > c2 =? c1.operator>(c2)

	priority_queue<customer, vector<customer>, customerAgeFunctor> minHeap;

	minHeap.push(customer("krishna", 19));
	minHeap.push(customer("neil", 18));
	minHeap.push(customer("ritika", 20));
	minHeap.push(customer("varsha", 21));

	cout << minHeap.size() << endl;

	while (!minHeap.empty()) {
		customer minCustomer = minHeap.top();
		cout << minCustomer.name << " " << minCustomer.age << endl;
		minHeap.pop();
	}

	cout << minHeap.size() << endl;

	priority_queue<customer, vector<customer>, customerNameFunctor> maxHeap;

	maxHeap.push(customer("krishna", 19));
	maxHeap.push(customer("neil", 18));
	maxHeap.push(customer("ritika", 20));
	maxHeap.push(customer("varsha", 21));

	cout << maxHeap.size() << endl;

	while (!maxHeap.empty()) {
		customer maxCustomer = maxHeap.top();
		cout << maxCustomer.name << " " << maxCustomer.age << endl;
		maxHeap.pop();
	}

	cout << maxHeap.size() << endl;
	return 0;
}