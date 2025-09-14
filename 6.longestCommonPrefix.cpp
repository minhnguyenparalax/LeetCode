// string::substr
#include <iostream>
#include<vector>
#include <string>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++)
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.length() - 1);
                if (prefix.empty()) return "";
            }
        return prefix;
    }
};

int main()
{
    Solution slt;
    vector<string> strs = {"dog","racecar","car"};
    cout<<slt.longestCommonPrefix(strs);
}