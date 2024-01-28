#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

// time : O(n)
// space: O(n)

int longestPalindrome(string str) {

	unordered_set<char> us;
	int cnt = 0;

	for (char ch : str) {
		if (us.find(ch) == us.end()) {
			us.insert(ch);
		} else {
			cnt += 2;
			us.erase(ch);
		}
	}

	if (us.size() > 0) cnt++;

	return cnt;

}

int main() {

	string str = "aaabbbbbbbccccdd";

	cout << longestPalindrome(str) << endl;

	return 0;
}