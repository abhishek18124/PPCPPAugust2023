#include<iostream>
#include<cstring>

using namespace std;

void myCopy(char* s1, char* s2) {

	int i = 0;
	int j = 0;

	// time ~ length of s2

	while (s2[j] != '\0') {
		s1[i] = s2[j];
		i++;
		j++;
	}

	s1[i] = '\0';


}

int main() {

	char s1[100] = "abcde";
	char s2[] = "de";

	cout << "Before copy : " << s1 << endl;

	// myCopy(s1, s2);

	strcpy(s1, s2);

	cout << "After copy : " << s1 << endl;

	return 0;
}