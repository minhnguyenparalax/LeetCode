#include <iostream>
#include <string>
using namespace std;

// Given a string s consisting of words and spaces, return the length of the last word in the string.

// A word is a maximal substring consisting of non-space characters only.

 

// Example 1:

// Input: s = "Hello World"
// Output: 5
// Explanation: The last word is "World" with length 5.
// Example 2:

// Input: s = "   fly me   to   the moon  "
// Output: 4
// Explanation: The last word is "moon" with length 4.
// Example 3:

// Input: s = "luffy is still joyboy"
// Output: 6
// Explanation: The last word is "joyboy" with length 6.
class Solution {
public:
    int lengthOfLastWord(string s) {
        int end = s.length() - 1;

        while (end >= 0 && s[end] == ' ') {
            end--;
        }

        int start = end;
        while (start >= 0 && s[start] != ' ') {
            start--;
        }

        return end - start;        
    }
};

int main() {
    Solution sol;

    string s1 = "Hello World";
    string s2 = "   fly me   to   the moon  ";
    string s3 = "luffy is still joyboy";

    cout << "Input: \"" << s1 << "\" -> Output: " << sol.lengthOfLastWord(s1) << endl;
    cout << "Input: \"" << s2 << "\" -> Output: " << sol.lengthOfLastWord(s2) << endl;
    cout << "Input: \"" << s3 << "\" -> Output: " << sol.lengthOfLastWord(s3) << endl;

    return 0;
}
