/*
    https://leetcode.com/problems/knight-dialer/
*/

#include<iostream>
#include<vector>

#define vvvi vector<vector<vector<int>>>

using namespace std;


class Solution {
public:

    vector<int> dx = { -2, -2, 2, 2, -1, 1, -1, 1};
    vector<int> dy = {1, -1, 1, -1, 2, 2, -2, -2};

    int MOD = 1e9 + 10;

    int helper(int i, int j, int m) {

        // base case

        if ((i == 3 and j == 0) || (i == 3 and j == 2)) {
            // you are at '*' or '#'
            return 0;
        }

        if (i > 3 || i < 0 || j > 2 || j < 0) {
            // you've gone outside the keypad
            return 0;
        }

        if (m == 0) {
            // you've dialled an n-digit number
            return 1;
        }

        // recursive case

        // count the #phoneNumbers the knight can dial by making 'm' moves starting from the (i, j)th cell

        int cnt = 0;

        // decide the next move

        for (int k = 0; k < 8; k++) {

            cnt += helper(i + dx[k], j + dy[k], m - 1) % MOD;

        }

        return cnt % MOD;


    }

    int helperTopDown(int i, int j, int m, vvvi& dp) {

        // base case

        if ((i == 3 and j == 0) || (i == 3 and j == 2)) {
            // you are at '*' or '#'
            return 0;
        }

        if (i > 3 || i < 0 || j > 2 || j < 0) {
            // you've gone outside the keypad
            return 0;
        }

        if (m == 0) {
            // you've dialled an n-digit number
            return 1;
        }

        // lookup

        if (dp[i][j][m] != -1) {
            return dp[i][j][m];
        }

        // recursive case

        // count the #phoneNumbers the knight can dial by making 'm' moves starting from the (i, j)th cell

        int cnt = 0;

        // decide the next move

        for (int k = 0; k < 8; k++) {

            cnt = (cnt + helperTopDown(i + dx[k], j + dy[k], m - 1, dp)) % MOD;

        }

        return dp[i][j][m] = cnt % MOD;


    }


    int knightDialer(int n) {

        vvvi dp(4, vector<vector<int>>(3, vector<int>(n, -1)));

        int total = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                // count # distinct phone numbers of length 'n' the knight can dial starting from the (i, j)th cell
                if (i == 3 and j == 0 || i == 3 || j == 2) continue;
                // total += helper(i, j, n - 1);
                total = (total + helperTopDown(i, j, n - 1, dp)) % MOD;
            }
        }
        return total % MOD;
    }
};

int main() {

    Solution s;

    cout << s.knightDialer(2) << endl;
    cout << s.knightDialer(3) << endl;

    return 0;
}