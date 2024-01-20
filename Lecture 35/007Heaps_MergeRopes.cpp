/*

    There are given n ropes of different lengths, we need to connect these ropes into one rope.
    The cost to connect two ropes is equal to the sum of their lengths. We need to connect the
    ropes with minimum cost.

    Example :

    Input : {4, 3, 2, 6}
    Output: 29

*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {

    vector<int> ropeLengths = {4, 3, 2, 6};

    // priority_queue<int, vector<int>, greater<int>> minHeap;

    // for (int i = 0; i < ropeLengths.size(); i++) {
    //     minHeap.push(ropeLengths[i]);
    // }

    priority_queue<int, vector<int>, greater<int>> minHeap(ropeLengths.begin(), ropeLengths.end());

    int minCost = 0;

    while (minHeap.size() > 1) { // n-1 times

        int firstSmallest = minHeap.top();
        minHeap.pop(); // logn

        int secondSmallest =  minHeap.top();
        minHeap.pop(); // logn

        minCost += firstSmallest + secondSmallest;

        minHeap.push(firstSmallest + secondSmallest); // logn

    }

    // n-1(logn+logn+logn) ~ O(nlogn)

    cout << minCost << endl;


    return 0;
}