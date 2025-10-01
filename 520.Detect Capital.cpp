// We define the usage of capitals in a word to be right when one of the following cases holds:

// All letters in this word are capitals, like "USA".
// All letters in this word are not capitals, like "leetcode".
// Only the first letter in this word is capital, like "Google".
// Given a string word, return true if the usage of capitals in it is right.
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(const string &word) {
        int upperCount = 0;
        for (char c : word) {
            if (isupper(c)) upperCount++;
        }
        // 3 điều kiện hợp lệ:
        return (upperCount == word.size())                 // Tất cả chữ hoa
            || (upperCount == 0)                           // Tất cả chữ thường
            || (upperCount == 1 && isupper(word[0]));      // Chỉ chữ đầu hoa
    }
};

int main() {
    Solution sol;

    // Test cases
    string tests[] = {"USA", "leetcode", "Google", "FlaG"};
    for (const string &w : tests) {
        cout << w << " -> " << (sol.detectCapitalUse(w) ? "true" : "false") << endl;
    }

    // User input
    string input;
    cout << "Enter a word to test: ";
    cin >> input;
    cout << input << " -> " << (sol.detectCapitalUse(input) ? "true" : "false") << endl;

    return 0;
}