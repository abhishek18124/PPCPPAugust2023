#include<iostream>

using namespace std;

// 1st approach - sort and compare

// 2nlogn + n

// 2.8log8 + 8 = 56 steps

// steps = n + n + 26
// space = 26 + 26

bool isAnagrams(char* s1, char* s2) {

	// 1. build a freq[] for s1
	int f1[26] = {};
	for (int i = 0; s1[i] != '\0'; i++) {
		char ch = s1[i];
		int idx = ch - 'a';
		f1[idx]++;
	}

	for (int i = 0; i < 26; i++) {
		cout << f1[i] << " ";
	}

	cout << endl;

	// 2. build a freq[] for s2
	int f2[26] = {};
	for (int i = 0; s2[i] != '\0'; i++) {
		// char ch = s2[i];
		// int idx = ch - 'a';
		// f2[idx]++;

		f2[s2[i] - 'a']++;

	}


	for (int i = 0; i < 26; i++) {
		cout << f2[i] << " ";
	}

	cout << endl;

	// 3. compare the freq[]s

	for (int i = 0; i < 26; i++) {
		if (f1[i] != f2[i]) {
			return false;
		}
	}

	return true;

}

int main() {

	char s1[] = "aabbccc";
	char s2[] = "aaabccc";

	isAnagrams(s1, s2) ? cout << "anagrams" << endl : cout << "not anagrams" << endl;

	return 0;
}