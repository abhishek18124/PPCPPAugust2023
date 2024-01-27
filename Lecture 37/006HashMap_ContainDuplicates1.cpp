#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

// bool containsDuplicate(const vector<int>& v) {

// 	unordered_map<int, int> freqMap;

// 	for (int i = 0; i < v.size(); i++) {

// 		freqMap[v[i]]++;

// 	}

// 	// for (pair<int, int> p : freqMap) {
// 	// 	cout << "freq(" << p.first << ") = " << p.second << endl;
// 	// }

// 	for (pair<int, int> p : freqMap) {
// 		if (p.second > 1) {
// 			// you've found a duplicate
// 			return true;
// 		}
// 	}

// 	// no duplicates found
// 	return false;

// }

// time : O(n)
// space: O(n)

bool containsDuplicate2(const vector<int>& v) {

	unordered_set<int> us;

	for (int i = 0; i < v.size(); i++) {

		if (us.find(v[i]) == us.end()) {
			// you are seeing v[i] for the 1st time
			us.insert(v[i]);
		} else {
			// you've seen v[i] previously therefore you've found a duplicate
			return true;
		}

	}

	// no duplicates found
	return false;

}

int main() {

	vector<int> v = {1, 2, 3};

	// containsDuplicate(v) ? cout << "duplicates found" << endl : cout << "duplicates not found!" << endl;

	containsDuplicate2(v) ? cout << "duplicates found" << endl : cout << "duplicates not found!" << endl;


	return 0;
}