/*

	Implementation of the disjoint set union data structure.

*/

#include<iostream>
#include<unordered_map>

using namespace std;

template <typename T>
class disjointSet {

	unordered_map<T, T> parentMap; // to store a mapping b/w vertices & their parents

public :

	void createSet(T x) { // O(1)
		parentMap[x] = x;
	}

	T findSet(T x) {
		// base case
		if (parentMap[x] == x) {
			// x is the leader of the set in which x is present
			return x;
		}

		// recursive case

		T px = parentMap[x];
		return findSet(px);
	}

	void unionSet(T x, T y) {
		T lx = findSet(x);
		T ly = findSet(y);
		if (lx != ly) {
			// perform the union operation
			// parentMap[lx] = ly;
			parentMap[ly] = lx;
		}
	}

};

int main() {

	disjointSet<int> ds;

	ds.createSet(1);
	ds.createSet(2);
	ds.createSet(3);
	ds.createSet(4);

	ds.unionSet(2, 3);

	cout << ds.findSet(3) << endl;

	ds.unionSet(1, 4);

	cout << ds.findSet(4) << endl;

	ds.unionSet(3, 4);

	cout << ds.findSet(2) << endl;

	return 0;
}