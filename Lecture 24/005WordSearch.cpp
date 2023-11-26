#include<iostream>
#include<vector>

using namespace std;

bool searchWord(vector<vector<char>>& board, string word, int m, int n, int i, int j, int k) {

	// base case

	if (k == word.size()) {

		// you've found the word in the board

		return true;

	}

	if (i == -1 || j == -1 || i == m || j == n) {

		// you've gone outside the board

		return false;
	}

	if (board[i][j] != word[k]) {

		// this cell is of no use

		return false;
	}

	// if(board[i][j] == '#') { // redundant, already handled above
	// 	return false;
	// }

	// recursive case

	// board[i][j] is equal to word[k], so we can use this cell

	board[i][j] = '#'; // block the (i, j)th cell of the board

	// decide the next step to find the (k+1)th character of the word[]

	if (searchWord(board, word, m, n, i, j + 1, k + 1)) {
		return true;
	}

	if (searchWord(board, word, m, n, i, j - 1, k + 1)) {
		return true;
	}

	if (searchWord(board, word, m, n, i - 1, j, k + 1)) {
		return true;
	}

	if (searchWord(board, word, m, n, i + 1, j, k + 1)) {
		return true;
	}

	board[i][j] = word[k]; // restore the original value at the (i, j)th cell

	return false;

}

bool exist(vector<vector<char>>& board, string word) {
	int m = board.size();
	int n = board[0].size();
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == word[0]) {
				if (searchWord(board, word, m, n, i, j, 0)) {
					return true;
				}
			}
		}
	}

	return false;
}


int main() {

	vector<vector<char>> board = {
		{'A', 'B', 'C', 'E'},
		{'S', 'F', 'C', 'S'},
		{'A', 'D', 'E', 'E'}
	};

	string word = "ABCCED";

	exist(board, word) ? cout << "true" << endl :
	                          cout << "false" << endl;

	return 0;
}