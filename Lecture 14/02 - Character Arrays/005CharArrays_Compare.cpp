#include<iostream>
#include<cstring>

using namespace std;

// time : min(m, n) : here m is the length of the 1st string and n is the lenght of the second string

int myStringCompare(char* s1, char* s2) {

	int i = 0;
	int j = 0;

	while (s1[i] != '\0' and s2[j] != '\0') {

		if (s1[i] < s2[j]) {
			// s1 < s2
			return -1;
		}

		if (s1[i] > s2[j]) {
			// s1 > s2
			return 1;
		}

		i++;
		j++;

	}

	// if (s1[i] == '\0' and s2[j] == '\0') {
	// 	return 0;
	// }

	// if (s1[i] == '\0') { // len(s2) > len(s1) -> s2 > s1
	// 	return -1;
	// }

	// return 1; // len(s1) > len(s2) -> s1 > s2

	if (s1[i] == '\0' and s2[j] == '\0') {
		// len(s1) == len(s2)
		return 0;
	} else if (s1[i] == '\0' and s2[j] != '\0') {
		// len(s2) > len(s1)
		return -1;
	} else { // s1[i] != '\0' and s2[j] == '\0'
		// len(s1) > len(s2)
		return 1;
	}

}

int main() {

	char s1[] = "abd";
	char s2[] = "abd";

	// int output = myStringCompare(s1, s2);

	int output = strcmp(s1, s2);

	if (output == 0) {
		cout << "s1 == s2" << endl;
	} else if (output > 0) {
		cout << "s1 > s2" << endl;
	} else { // output < 0
		cout << "s1 < s2" << endl;
	}

	return 0;
}