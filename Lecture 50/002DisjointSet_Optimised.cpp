/*

	Implementation of the disjoint set union data structure
	by using union by rank and path compression heuristics.

*/

#include<iostream>
#include<unordered_map>

using namespace std;

template <typename T>
class disjointSet {

	unordered_map<T, T> parentMap; // to store a mapping b/w vertices & their parents
	unordered_map<T, int> rankMap;   // to store a mapping b/w vertices & their ranks i.e. sizes

public :

	void createSet(T x) {
		parentMap[x] = x;
		rankMap[x] = 1;
	}

	T findSet(T x) {
		// base case
		if (parentMap[x] == x) {
			// x is the leader of the set that contains x
			return x;
		}

		// recursive case
		T px = parentMap[x];
		return parentMap[x] = findSet(px); // path compression
	}

	void unionSet(T x, T y) {
		T lx = findSet(x);
		T ly = findSet(y);

		if (lx != ly) {
			// perform the union operation

			int rx = rankMap[lx];
			int ry = rankMap[ly];

			if (rx > ry) {

				// make lx as the parent of ly

				parentMap[ly] = lx;
				rankMap[lx] += rankMap[ly];

			} else {

				// make ly as the parent of lx

				parentMap[lx] = ly;
				rankMap[ly] += rankMap[lx];

			}

		}
	}

};

int main() {

	disjointSet<int> ds;

	ds.createSet(1); // {1}
	ds.createSet(2); // {2}
	ds.createSet(3); // {3}
	ds.createSet(4); // {4}

	ds.unionSet(1, 2); // {1, 2}, {3}, {4}
	ds.unionSet(2, 3); // {1, 2, 3}, {4}

	cout << ds.findSet(2) << endl; // 2

	ds.unionSet(3, 4); // {1, 2, 3, 4}

	cout << ds.findSet(4) << endl; // 2

	return 0;
}
