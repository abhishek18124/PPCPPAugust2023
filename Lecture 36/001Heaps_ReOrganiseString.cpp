#include<iostream>
#include<queue>
#include<string>

using namespace std;

string reorganise(const string& str) {

    // int freq[26];

    // memset(freq, 0, sizeof(freq));

    // int freq[26] = {};

    int freq[26] = {0};

    for (char ch : str) {
        freq[ch - 'a']++;
    }

    priority_queue<pair<int, char>> maxHeap; // by default, maxHeap is built based on the first element of the pair

    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            maxHeap.push({freq[i], i + 'a'});
        }
    }

    string out = "";

    while (!maxHeap.empty()) {

        if (maxHeap.size() == 1) {

            pair<int, char> maxPair = maxHeap.top();
            maxHeap.pop();

            if (maxPair.first == 1) {

                // str can be reorganised

                out += maxPair.second;

            } else {

                // str cannot reorganised

                out = "";

            }

        } else {

            pair<int, char> firstMaxPair = maxHeap.top();
            maxHeap.pop();

            pair<int, char> secondMaxPair = maxHeap.top();
            maxHeap.pop();

            out += firstMaxPair.second;
            firstMaxPair.first--;

            out += secondMaxPair.second;
            secondMaxPair.first--;

            if (firstMaxPair.first > 0) {
                maxHeap.push(firstMaxPair);
            }

            if (secondMaxPair.first > 0) {
                maxHeap.push(secondMaxPair);
            }
        }

    }

    return out;

}

int main() {

    string str = "aaaaabbbbcccdd";

    cout << reorganise(str) << endl;

    return 0;
}