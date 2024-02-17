#include <iostream>
#include<climits>
#include <unordered_map>
#include <map>

using namespace std;

unordered_map<int, vector<int>> cmap; // to store a mapping b/w a color and object weights of that color

int helper(int w[], int c[], int n, int m, int x, int i) {

    // base case

    if (i == m + 1) {
        // you've chosen items for colors 1 to m
        return x;
    }

    if (x == 0) { // i != m+1, we still colors left
        return INT_MAX;
    }

    // recursive case

    // make a decision for the ith color

    vector<int> optionsForIthColor = cmap[i];
    int minSoFar = INT_MAX;

    for (int xij : optionsForIthColor) {
        if (xij <= x) {
            minSoFar = min(minSoFar, helper(w, c, n, m, x - xij, i + 1));
        }
    }

    return minSoFar;

}

int helperTopDown(int w[], int c[], int n, int m, int x, int i, vector<vector<int>>& dp) {

    // lookup

    if (dp[i][x] != -1) {
        return dp[i][x];
    }

    // base case

    if (i == m + 1) {
        // you've chosen items for colors 1 to m
        return dp[i][x] = x;
    }

    if (x == 0) { // i != m+1, we still colors left
        return dp[i][x] = INT_MAX;
    }

    // recursive case

    // make a decision for the ith color

    vector<int> optionsForIthColor = cmap[i];
    int minSoFar = INT_MAX;

    for (int xij : optionsForIthColor) {
        if (xij <= x) {
            minSoFar = min(minSoFar, helperTopDown(w, c, n, m, x - xij, i + 1, dp));
        }
    }

    return dp[i][x] = minSoFar;

}

int colorfulKnapsack(int w[], int c[], int n, int m, int x) {

    for (int i = 0; i < n; i++) {

        cmap[c[i]].push_back(w[i]);

    }

    // int res = helper(w, c, n, m, x, 1);

    vector<vector<int>> dp(m + 2, vector<int>(x + 1, -1)); // 0th row is not used

    int res = helperTopDown(w, c, n, m, x, 1, dp);

    return res == INT_MAX ? -1 : res;

}

int main() {

    // int w[] = {2, 3, 4, 2, 4, 5, 2, 3};
    // int c[] = {1, 1, 1, 2, 2, 2, 3, 3};

    // int n = 8;
    // int m = 3;

    // int x = 13;

    // int w[] = {2, 3, 4, 2};
    // int c[] = {1, 1, 1, 2};

    // int n = 4;
    // int m = 2;

    // int x = 5;

    // int w[] = {2, 3, 8, 2, 1};
    // int c[] = {1, 1, 1, 2, 2};

    // int n = 4;
    // int m = 2;

    // int x = 7;

    cout << colorfulKnapsack(w, c, n, m, x) << endl;

    return 0;

}