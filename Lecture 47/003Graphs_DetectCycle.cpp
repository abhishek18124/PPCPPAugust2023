/*

Given an undirected graph, check if there exists a cycle or not.

*/

#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<list>

using namespace std;

template <typename T>
class graph {

	unordered_map<T, list<T>> neighbourMap; // to store the graph representation

public :

	void addEdge(T u, T v) {

		// adds an edge b/w vertex u and v

		neighbourMap[u].push_back(v);
		neighbourMap[v].push_back(u);

	}

	// bool dfsHelper(T source, unordered_set<T>& visited, T parent) {

	// 	// mark 'source' as visited
	// 	visited.insert(source);

	// 	// visit 'unvisted' vertices reachable from 'source'

	// 	list<T> neighbourList = neighbourMap[source];
	// 	for (T neighbour : neighbourList) {
	// 		if (visited.find(neighbour) == visited.end()) {
	// 			// neighbour is not visited

	// 			if (dfsHelper(neighbour, visited, source)) {
	// 				// we've found cycle in the subcomponent hence we've found a cycle in the component
	// 				return true;
	// 			}

	// 		} else {
	// 			// neighbour is visited

	// 			// check if source-neighbour is a backedge
	// 			if (neighbour != parent) {
	// 				// source-neighbour is backedge therefore we've found a cycle in the componenet
	// 				return true;
	// 			}
	// 		}
	// 	}

	// 	return false;
	// }

	bool dfsHelper(T u, unordered_set<T>& visited, T parent) {

		// mark 'u' as visited
		visited.insert(u);

		// visit 'unvisted' vertices reachable from 'u'

		list<T> neighbourList = neighbourMap[u];
		for (T v : neighbourList) {
			if (visited.find(v) == visited.end()) {
				// v is not visited

				if (dfsHelper(v, visited, u)) {
					// we've found cycle in the subcomponent hence we've found a cycle in the component
					return true;
				}

			} else {
				// v is visited

				// check if u-v is a backedge
				if (v != parent) {
					// u-v is backedge therefore we've found a cycle in the componenet
					return true;
				}
			}
		}

		return false;
	}


	bool isCyclePresent() {
		bool flag = false; // assume cycle is not present in the graph
		unordered_set<T> visited; // to keep track of visited vertices
		for (pair<T, list<T>> vertex : neighbourMap) {
			T vertexLabel = vertex.first;
			if (visited.find(vertexLabel) == visited.end()) {
				// check if cycle is present in the component that contains 'vertex'
				if (dfsHelper(vertexLabel, visited, vertexLabel)) {
					flag = true;
					break;
				}
			}
		}

		return flag;
	}
};


int main() {

	graph<char> g;

	g.addEdge('A', 'B');
	g.addEdge('A', 'C');
	g.addEdge('B', 'C');

	g.isCyclePresent() ? cout << "cycle found!" << endl :
	                          cout << "cycle not found!" << endl;

	return 0;
}