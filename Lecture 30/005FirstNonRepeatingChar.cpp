#include<iostream>
#include<queue>

using namespace std;

int main() {

	int freq[26] = {};
	// memset(freq, 0, sizeof(freq));

	queue<char> q;

	char ch;

	while (true) {

		cin >> ch;

		if (ch == '.') break;

		freq[ch - 'a']++;
		if (freq[ch - 'a'] == 1) {
			// ch, as of now, is a non-repeating char
			q.push(ch);
		}

		while (!q.empty() and freq[q.front() - 'a'] > 1) {
			// q.front() is now a repeating char
			q.pop();
		}

		if (q.empty()) {
			cout << -1 << " ";
		} else {
			cout << q.front() << " ";
		}

	}

	return 0;
}