/*

Given a m x n maze with some blocked cells (marked with 'X'), and rat that wants to
go from the src (0, 0) to the dst (m-1, n-1) design a recursive algorithm to

	> generate all the paths from src to dst

such at each step the rat can only move in the right or down direction.

Constraint

 1 <= m, n < 10

Example
	Input :

		maze = {"0000",
	            "00X0",
	            "000X",
	            "0X00"}

	Output :

	       {"1100", {"1000", {"1000",
            "0100",	 "1100",  "1000",
            "0110",  "0110",  "1110",
            "0011"}  "0011"}  "0011"}

*/

#include<iostream>

using namespace std;

#include<iostream>

using namespace std;

void printPath(char path[][10], int m, int n) {

	for (int i = 0; i < m; i++) {

		for (int j = 0; j < n; j++) {
			cout << path[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;

}

void f(char maze[][10], char path[][10], int m, int n, int i, int j) {

	// base case

	if (i == m or j == n) {

		// rat is outside the maze

		return;

	}

	if (i == m - 1 and j == n - 1) {

		// you've reached the destination

		path[i][j] = '1';

		printPath(path, m, n);

		path[i][j] = '0';

		return; // assume destination is not blocked

	}


	if (maze[i][j] == 'X') {

		// you've reached a blocked cell therefore you cannot go to the destination

		return;

	}


	// recursive case

	// decide the next step

	path[i][j] = '1';

	// 1. move right

	f(maze, path, m, n, i, j + 1);

	// 2. move down

	f(maze, path, m, n, i + 1, j);

	path[i][j] = '0'; // backtracking or undo step

}


int main() {

	char maze[][10] = {"0000",
	                   "00X0",
	                   "000X",
	                   "0X00"
	                  };

	char path[][10] = {"0000",
	                   "0000",
	                   "0000",
	                   "0000"
	                  };
	int m = 4;
	int n = 4;

	f(maze, path, m, n, 0, 0);

	return 0;
}
