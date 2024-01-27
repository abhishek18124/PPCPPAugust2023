/*

	Implement a phonebook storing mapping between person's name and
	their phone numbers using an unordered_map.

*/

#include<iostream>
#include<unordered_map>

using namespace std;

int main() {

	unordered_map<string, vector<string>> phoneMap;

	phoneMap["Aayush"].push_back("1234");
	phoneMap["Aayush"].push_back("4567");
	phoneMap["Aayush"].push_back("0000");

	phoneMap["Babbar"].push_back("6901");
	phoneMap["Babbar"].push_back("1230");

	phoneMap["Ridhi"].push_back("1256");


	for (pair<string, vector<string>> contact : phoneMap) {
		string contactName = contact.first;
		vector<string> phoneNums = contact.second;
		cout << contactName << " ";
		for (string num : phoneNums) {
			cout << num <<  " ";
		}
		cout << endl;

	}

	return 0;
}