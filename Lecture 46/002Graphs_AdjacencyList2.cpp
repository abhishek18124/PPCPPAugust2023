/*

Implementation of the graph using adjacency list.

Note : each vertex in the graph is generic.

*/

#include<iostream>
#include<map>
#include<list>

using namespace std;

template <typename T>
class graph {

	map<T, list<T>> neighbourMap; // to store the graph representation
	bool isDirected; // to indicate if the graph is directed or not

public :

	graph(bool isDirected = false) {
		this->isDirected = isDirected;
	}

	void addEdge(T u, T v) {

		// adds an edge b/w vertex u and v

		neighbourMap[u].push_back(v);
		if (!isDirected) {
			neighbourMap[v].push_back(u);
		}

	}

	void print() {

		// prints the adjacency list representation of the graph

		for (pair<T, list<T>> vertex : neighbourMap) {
			T vertexLabel = vertex.first;
			list<T> neighbours = vertex.second;
			cout << vertexLabel << " : ";
			for (T ngb : neighbours) {
				cout << ngb << " ";
			}
			cout << endl;
		}

	}
};

int main() {

	// graph<int> g;

	// g.addEdge(0, 1);
	// g.addEdge(0, 2);
	// g.addEdge(1, 3);
	// g.addEdge(2, 3);
	// g.addEdge(2, 4);
	// g.addEdge(3, 4);

	graph<char> g;

	g.addEdge('A', 'B');
	g.addEdge('A', 'C');
	g.addEdge('B', 'D');
	g.addEdge('C', 'D');
	g.addEdge('C', 'E');
	g.addEdge('D', 'E');


	g.print();

	return 0;
}