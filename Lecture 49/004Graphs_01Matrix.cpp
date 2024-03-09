// https://leetcode.com/problems/01-matrix/

#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

// 1. brute-force approach - time : O(m^2.n^2)

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

	int m = mat.size();
	int n = mat[0].size();

	vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] == 0) {
				for (int ii = 0; ii < m; ii++) {
					for (int jj = 0; jj < n; jj++) {
						dist[ii][jj] = min(dist[ii][jj], abs(ii - i) + abs(jj - j));
					}
				}
			}
		}
	}

	return dist;

}

// 2. multi-source-bfs approach - time : O(m.n)

vector<vector<int>> updateMatrixOptimised(vector<vector<int>>& mat) {

	int m = mat.size();
	int n = mat[0].size();

	vector<vector<int>> dist(m, vector<int>(n));

	queue<pair<int, int>> q; // each vertex is a pair<int, int>
	vector<vector<bool>> visited(m, vector<bool>(n, false));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] == 0) {

				// (i, j)th cell corresponds to a source vertex

				q.push({i, j}); // q.push(make_pair(i, j));
				visited[i][j] = true;
				dist[i][j] = 0;

			}
		}
	}

	vector<int> dx = {0, 0, -1, 1};
	vector<int> dy = {1, -1, 0, 0};

	while (!q.empty()) {

		pair<int, int> front = q.front();
		q.pop();

		int px = front.first;
		int py = front.second;

		for (int k = 0; k < 4; k++) {

			int nx = px + dx[k];
			int ny = py + dy[k];

			if (nx >= 0 and nx < m and ny >= 0 and ny < n and visited[nx][ny] == false) {

				visited[nx][ny] = true;
				q.push({nx, ny});
				dist[nx][ny] = dist[px][py] + 1;

			}

		}

	}

	return dist;

}


int main() {

	vector<vector<int>> mat = {
		{0, 1, 1, 1, 0},
		{1, 1, 1, 1, 1},
		{1, 1, 0, 1, 1},
		{1, 1, 1, 1, 1},
		{0, 1, 1, 1, 0}
	};

	// vector<vector<int>> dist = updateMatrix(mat);
	// for (vector<int> row : dist) {
	// 	for (int col : row) {
	// 		cout << col << " ";
	// 	}
	// 	cout << endl;
	// }

	vector<vector<int>> dist = updateMatrixOptimised(mat);
	for (vector<int> row : dist) {
		for (int col : row) {
			cout << col << " ";
		}
		cout << endl;
	}

	return 0;
}