/*
	https://leetcode.com/problems/longest-consecutive-sequence/
*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:

	// total time : O(n+n) = O(n)

	int longestConsecutive(vector<int>& nums) {

		unordered_map<int, bool> startMap; // to build startMap you spend O(n) time

		for (int num : nums) {

			if (startMap.find(num - 1) == startMap.end()) {
				// for now, num can be a starting point
				startMap[num] = true;
			} else {
				// num cannot be a starting point
				startMap[num] = false;
			}

			if (startMap.find(num + 1) != startMap.end()) {
				startMap[num + 1] = false;
			}

		}

		for (pair<int, bool> p : startMap) {
			cout << p.first << " " << p.second << endl;
		}

		int maxSoFar = 0; // to track the length of the longest consecutive sequence

		// O(n)

		for (pair<int, bool> p : startMap) {

			int key = p.first;
			bool canStart = p.second;

			if (canStart) {

				// you can start building a sequence of conse. element starting from key

				int cnt = 0;

				while (startMap.find(key) != startMap.end()) {
					cnt++;
					key++;
				}

				maxSoFar = max(maxSoFar, cnt);


			}

		}

		return maxSoFar;


	}
};

int main() {

	Solution s;

	vector<int> nums = {0, 1, 4, 5, 6, 11, 12, 13, 14};

	cout << s.longestConsecutive(nums) << endl;

}
