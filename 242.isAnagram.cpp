// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

//anargram là chuỗi nhỏ của một chuỗi lớn

// Example 1:

// Input: s = "anagram", t = "nagaram"

// Output: true

// Example 2:

// Input: s = "rat", t = "car"

// Output: false

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        // tạo 2 vector lưu tần suất ký tự
        vector<int> freqS(26, 0);
        vector<int> freqT(26, 0);

        for (char c : s) {
            freqS[c - 'a']++;
        }
        for (char c : t) {
            freqT[c - 'a']++;
        }

        // so sánh trực tiếp 2 vector
        return freqS == freqT;
    }
};

int main() {
    string s, t;
    cout << "Nhap chuoi s: ";
    cin >> s;
    cout << "Nhap chuoi t: ";
    cin >> t;

    Solution sol;
    cout << (sol.isAnagram(s, t) ? "true" : "false") << endl;

    return 0;
}
