/*

Implementation of the stack using two queues.

*/

#include<iostream>
#include<queue>

using namespace std;

template <typename T>
class stack {
	queue<T> q1;

public:

	void push(T data) {
		q1.push(data);
	}

	void pop() {
		if (q1.empty()) {
			// stack is empty
		} else  {
			// transfer n-1 elements from q1 to q1
			int n = q1.size();
			while (n > 1) {
				q1.push(q1.front());
				q1.pop();
				n--;
			}
			// pop stack top i.e. pop the nth element from q1
			q1.pop();
		}
	}

	T top() {
		// transfer n-1 elements from q1 to q1
		int n = q1.size();
		while (n > 1) {
			q1.push(q1.front());
			q1.pop();
			n--;
		}
		// save & pop the nth element from q1 and transfer it to q2
		T ans = q1.front();
		q1.pop();
		q1.push(ans);
		return ans;
	}

	bool empty() {
		return q1.empty();
	}

	int size() {
		return q1.size();
	}
};

int main() {

	stack<int> s;

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);

	cout << "size = " << s.size() << endl;

	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}

	cout << endl;

	s.empty() ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}