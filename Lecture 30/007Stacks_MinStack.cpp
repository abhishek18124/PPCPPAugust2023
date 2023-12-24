#include<iostream>
#include<stack>

using namespace std;

class custom_stack {

	stack<int> main_stack;
	stack<int> min_stack;

public :

	void push(int data) {
		main_stack.push(data);
		if (min_stack.empty() || data <= min_stack.top()) {
			min_stack.push(data);
		}
	}

	void pop() {

		if (empty()) {
			return;
		}

		int temp = main_stack.top();
		main_stack.pop();
		if (min_stack.top() == temp) {
			min_stack.pop();
		}
	}

	int size() {
		return main_stack.size();
	}

	bool empty() {
		return main_stack.empty();
	}

	int top() {
		return main_stack.top();
	}

	int getMin() {
		return min_stack.top();
	}

};

int main() {

	custom_stack cs;

	cs.push(5);
	cs.push(0);
	cs.push(0);
	// cs.push(0);
	// cs.push(4);

	cout << cs.getMin() << endl;

	cs.pop();

	cout << cs.getMin() << endl;

	// cs.pop();

	// cout << cs.getMin() << endl;

	// cs.pop();
	// cs.pop();

	// cout << cs.getMin() << endl;

	return 0;
}
