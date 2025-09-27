#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        int count = 0;
        for (char c : word)
            if (isupper(c)) count++;

        return count == word.size()               // all uppercase
            || count == 0                         // all lowercase
            || (count == 1 && isupper(word[0]));  // only first letter uppercase
    }
};

int main() {
    Solution sol;

    // Test cases
    string w1 = "USA";
    string w2 = "leetcode";
    string w3 = "Google";
    string w4 = "FlaG";

    cout << w1 << " -> " << (sol.detectCapitalUse(w1) ? "true" : "false") << endl;
    cout << w2 << " -> " << (sol.detectCapitalUse(w2) ? "true" : "false") << endl;
    cout << w3 << " -> " << (sol.detectCapitalUse(w3) ? "true" : "false") << endl;
    cout << w4 << " -> " << (sol.detectCapitalUse(w4) ? "true" : "false") << endl;

    // Allow user input
    string input;
    cout << "Enter a word to test: ";
    cin >> input;
    cout << input << " -> " << (sol.detectCapitalUse(input) ? "true" : "false") << endl;

    return 0;
}
