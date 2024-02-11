
// https://leetcode.com/problems/dungeon-game/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:

    // recursive implementation

    int helper(vector<vector<int>>& dungeon, int m, int n, int i, int j) {

        // base case

        if (i == m - 1 and j == n - 1) {

            // find the minimum HP before you enter (m-1, n-1)th room

            return dungeon[m - 1][n - 1] >= 0 ? 1 : 1 - dungeon[m - 1][n - 1];

        }

        if (i == m || j == n) {

            // knight has gone outside the dungeon

            return INT_MAX;

        }

        // recursive case

        // find the minimum HP before you enter (i, j)th room

        // decide the next step

        // option 1 : move right

        int x = helper(dungeon, m, n, i, j + 1);

        // option 2 : move down

        int y = helper(dungeon, m, n, i + 1, j);

        // if (dungeon[i][j] == 0) {
        //     return min(x, y); // min(x, y) - dungeon[i][j] = min(x, y) - 0 = min(x, y)
        // } else if (dungeon[i][j] < 0) {
        //     return min(x, y) - dungeon[i][j];
        // } else { // dungeon[i][j] > 0
        //     return dungeon[i][j] >= min(x, y) ? 1 : min(x, y) - dungeon[i][j];
        // }

        return dungeon[i][j] >= min(x, y) ? 1 : min(x, y) - dungeon[i][j];

    }

    int helperTopDown(vector<vector<int>>& dungeon, int m, int n, int i, int j, vector<vector<int>>& dp) {

        // lookup

        if (dp[i][j] != -1) {
            // you've already solve f(i, j)
            return dp[i][j];
        }

        // base case

        if (i == m - 1 and j == n - 1) {

            // find the minimum HP before you enter (m-1, n-1)th room

            return dp[i][j] = dungeon[m - 1][n - 1] >= 0 ? 1 : 1 - dungeon[m - 1][n - 1];

        }

        if (i == m || j == n) {

            // knight has gone outside the dungeon

            return INT_MAX;

        }

        // recursive case

        // find the minimum HP before you enter (i, j)th room

        // decide the next step

        // option 1 : move right

        int x = helperTopDown(dungeon, m, n, i, j + 1, dp);

        // option 2 : move down

        int y = helperTopDown(dungeon, m, n, i + 1, j, dp);

        // if (dungeon[i][j] == 0) {
        //     return min(x, y); // min(x, y) - dungeon[i][j] = min(x, y) - 0 = min(x, y)
        // } else if (dungeon[i][j] < 0) {
        //     return min(x, y) - dungeon[i][j];
        // } else { // dungeon[i][j] > 0
        //     return dungeon[i][j] >= min(x, y) ? 1 : min(x, y) - dungeon[i][j];
        // }

        return dp[i][j] = dungeon[i][j] >= min(x, y) ? 1 : min(x, y) - dungeon[i][j];

    }

    // time : O(mn)
    // space: O(mn)

    int helperBottomUp(vector<vector<int>> dungeon, int m, int n) {

        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = 0; i <= m; i++) {
            dp[i][n] = INT_MAX;
        }

        for (int j = 0; j <= n; j++) {
            dp[m][j] = INT_MAX;
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                // dp[i][j] = f(i, j)

                if (i == m - 1 and j == n - 1) {
                    dp[i][j] = dungeon[i][j] >= 0 ? 1 : 1 - dungeon[i][j];
                } else {
                    int x = dp[i][j + 1]; // f(i, j+1)
                    int y = dp[i + 1][j]; // f(i+1, j)
                    dp[i][j] = dungeon[i][j] >= min(x, y) ? 1 : min(x, y) - dungeon[i][j];
                }

            }
        }

        return dp[0][0]; // at the 0,0th index of dp[][], we store f(0, 0)

    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {

        int m = dungeon.size();
        int n = dungeon[0].size();

        // return helper(dungeon, m, n, 0, 0);

        // vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        // return helperTopDown(dungeon, m, n, 0, 0, dp);

        return helperBottomUp(dungeon, m, n);

    }
};

int main() {

    Solution s;

    vector<vector<int>> dungeon = {{ -2, -3, 3}, { -5, -10, 1}, {10, 30, -5}};

    cout << s.calculateMinimumHP(dungeon) << endl;

}
