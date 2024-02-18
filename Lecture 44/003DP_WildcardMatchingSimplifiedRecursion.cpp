/*

    https://leetcode.com/problems/wildcard-matching/

*/


#include<iostream>

using namespace std;


class Solution {
public:

    bool helper(string s, string p, int m, int n, int i, int j) {

        // base case

        if (i == m) {

            // check if p[j...n-1] matches s[m...m-1] = {}

            bool flag = true; // assume p[j...n-1] contains only stars

            for (int k = j; k < n; k++) {
                if (p[k] != '*') {
                    flag = false;
                    break;
                }
            }

            // if i == m and j == n then we should return true which is happening since the loop won't run

            return flag;

        }

        if (j == n) { // i != m

            // check if p[n...n-1] = {} matches s[i...m-1] (non-empty)

            return false;

        }

        // recursive case

        // check if p[j...n-1] matches s[i...m-1]

        if (s[i] == p[j] || p[j] == '?') {

            // recursively, check if p[j+1...n-1] matches s[i+1...m-1]

            return helper(s, p, m, n, i + 1, j + 1);

        } else if (p[j] == '*') {

            // option 1 : * matches with ""

            // option 2 : * matches with 1 or more chars.

            return helper(s, p, m, n, i, j + 1) or helper(s, p, m, n, i + 1, j);

        } else { // s[i] != p[j] and p[j] is not a wildcard character

            // p[j] is not wildcard

            return false;

        }

    }

    bool helperBottomUp(string s, string p, int m, int n) {

        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        // i == m

        for (int j = 0; j <= n; j++) {

            bool flag = true; // assume p[j...n-1] contains only stars

            for (int k = j; k < n; k++) {
                if (p[k] != '*') {
                    flag = false;
                    break;
                }
            }

            // if i == m and j == n then we should return true which is happening since the loop won't run

            dp[m][j] = flag;
        }

        // j == n

        for (int i = 0; i <= m; i++) {
            dp[i][n] = false;
        }

        dp[m][n] = true;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                // dp[i][j] = f(i, j)

                // check if p[j...n-1] matches s[i...m-1]

                if (s[i] == p[j] || p[j] == '?') {

                    // recursively, check if p[j+1...n-1] matches s[i+1...m-1]

                    dp[i][j] = dp[i + 1][j + 1];

                } else if (p[j] == '*') {

                    // option 1 : * matches with ""

                    // option 2 : * matches with 1 or more chars.

                    dp[i][j] = dp[i][j + 1] or dp[i + 1][j];

                } else { // s[i] != p[j] and p[j] is not a wildcard character

                    // p[j] is not wildcard

                    dp[i][j] = false;

                }

            }
        }

        return dp[0][0];

    }

    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        // return helper(s, p, m, n, 0, 0);

        return helperBottomUp(s, p, m, n);
    }
};

int main() {

    string s = "abcabc";
    string p = "a?b*";

    Solution soln;

    cout << soln.isMatch(s, p) << endl;

    return 0;
}
