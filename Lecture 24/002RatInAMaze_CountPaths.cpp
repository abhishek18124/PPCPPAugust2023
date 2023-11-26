/*

Given a m x n maze with some blocked cells (marked with 'X'), and rat that wants to
go from the src (0, 0) to the dst (m-1, n-1) design a recursive algorithm to

	> check if there exists a path from src to dst

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

		true (Yes, a path exist from src to dst)

*/

#include<iostream>

using namespace std;

int cnt = 0;

bool f(char maze[][10], int m, int n, int i, int j) {

	// base case

	if (i == m or j == n) {

		// rat is outside the maze

		return false;

	}

	if (i == m - 1 and j == n - 1) {

		// you've reached the destination

		cnt++;

		return true; // assume destination is not blocked

	}


	if (maze[i][j] == 'X') {

		// you've reached a blocked cell therefore you cannot go to the destination

		return false;

	}


	// recursive case

	// check if the rat can go from (i, j)th cell to (m-1, n-1)th cell

	// decide the next step

	// 1. move right

	bool X = f(maze, m, n, i, j + 1);

	// 2. move down

	bool Y = f(maze, m, n, i + 1, j);

	return X or Y;

}

int main() {

	char maze[][10] = {"0000",
	                   "00X0",
	                   "000X",
	                   "0X00"
	                  };
	int m = 4;
	int n = 4;

	f(maze, m, n, 0, 0);

	cout << cnt << endl;

	return 0;
}