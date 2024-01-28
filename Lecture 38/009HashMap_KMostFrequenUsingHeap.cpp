#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

int main() {

	// time : O(n + klogn) using maxHeap space : O(n+n)
	// time : O(n + klogk) using minHeap space : O(n+k)

	int arr[] = {10, 10, 10, 20, 20, 30, 40, 50, 50, 60, 60, 60};
	int n = sizeof(arr) / sizeof(int);

	unordered_map<int, int> freqMap; // time : O(n)

	for (int i = 0; i < n; i++) {
		freqMap[arr[i]]++;
	}

	// for (pair<int, int> p : freqMap) {
	// 	cout << p.first << " " << p.second << endl;
	// }

	// time to build maxHeap = nlogn

	priority_queue<pair<int, int>> maxHeap; // <freq, value> // max heap size = n

	for (pair<int, int> p : freqMap) {
		maxHeap.push({p.second, p.first}); // (freq, value) // logn
	}

	int i = 0;
	int k = 3;

	// time to extract top k = klogn

	while (i < k) {
		cout << maxHeap.top().second << " ";
		maxHeap.pop();
		i++;
	}

	cout << endl;

	// total = n + nlogn + klogn

	return 0;

}