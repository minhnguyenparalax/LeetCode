#include <bits/stdc++.h>
using namespace std;

// You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.

// For each index i, names[i] and heights[i] denote the name and height of the ith person.

// Return names sorted in descending order by the people's heights.


// Example 1

// Input: names = ["Mary","John","Emma"], heights = [180,165,170]
// Output: ["Mary","Emma","John"]
// Explanation: Mary is the tallest, followed by Emma and John.
// Example 2:

// Input: names = ["Alice","Bob","Bob"], heights = [155,185,150]
// Output: ["Bob","Alice","Bob"]
// Explanation: The first Bob is the tallest, followed by Alice and the second Bob.

class Solution
{
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<int> idx(names.size());
        for (int i = 0; i < names.size(); ++i) {
            idx[i] = i;
        }
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return heights[i] > heights[j];
        });
        vector<string> ans(names.size());
        for (int i = 0; i < names.size(); ++i) {
            ans[i] = names[idx[i]];
        }
        return ans;
    }
};

int main() {
    Solution s;

    // Test 1
    vector<string> names1 = {"Mary", "John", "Emma"};
    vector<int> heights1 = {180, 165, 170};
    vector<string> result1 = s.sortPeople(names1, heights1);
    for (auto &name : result1) cout << name << " ";
    cout << endl;

    // // Test 2
    // vector<string> names2 = {"Alice", "Bob", "Bob"};
    // vector<int> heights2 = {155, 185, 150};
    // vector<string> result2 = s.sortPeople(names2, heights2);
    // for (auto &name : result2) cout << name << " ";
    // cout << endl;

    // return 0;
}
