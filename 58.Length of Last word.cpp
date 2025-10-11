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

        // Bỏ khoảng trắng ở cuối
        while (end >= 0 && s[end] == ' ') {
            end--;
        }

        int start = end;
        // Tìm vị trí bắt đầu của từ cuối cùng
        while (start >= 0 && s[start] != ' ') {
            start--;
        }

        return end - start;
    }
};

int main() {
    Solution sol;
    string s;

    cout << "Nhập chuỗi: ";
    getline(cin, s); // Cho phép nhập cả khoảng trắng

    cout << "Độ dài của từ cuối cùng là: " << sol.lengthOfLastWord(s) << endl;

    return 0;
}