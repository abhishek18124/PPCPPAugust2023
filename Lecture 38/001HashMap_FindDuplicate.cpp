#include<iostream>
#include<vector>

using namespace std;

int main() {

	vector<int> v = {1, 3, 4, 2, 2};

	int slow = v[0];
	int fast = v[0];

	while (true) {
		// slow = slow->next;
		slow = v[slow];
		// fast = fast->next->next;
		fast = v[v[fast]];
		if (slow == fast) {
			break;
		}
	}

	slow = v[0];

	while (slow != fast) {
		slow = v[slow];
		fast = v[fast];
	}

	cout << slow << endl;
	cout << fast << endl;

	return 0;
}