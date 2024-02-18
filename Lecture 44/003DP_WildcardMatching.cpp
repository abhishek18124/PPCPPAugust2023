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

        if (s[i] == p[j]) {

            // recursively, check if p[j+1...n-1] matches s[i+1...m-1]

            return helper(s, p, m, n, i + 1, j + 1);

        } else {

            if (p[j] == '?' || p[j] == '*') {

                // p[j] is a wildcard

                if (p[j] == '?') {

                    // recursively, check if p[j+1...n-1] matches s[i+1...m-1]

                    return helper(s, p, m, n, i + 1, j + 1);


                } else { // p[j] == "*"

                    // option 1 : * matches with ""

                    // option 2 : * matches with 1 or more chars.

                    return helper(s, p, m, n, i, j + 1) or helper(s, p, m, n, i + 1, j);

                }


            } else {

                // p[j] is not wildcard

                return false;

            }

        }

    }

    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        return helper(s, p, m, n, 0, 0);
    }
};

int main() {

    string s = "abcabc";
    string p = "a?b*";

    Solution soln;

    cout << soln.isMatch(s, p) << endl;

    return 0;
}
