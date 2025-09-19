// //Palindrome is a text Which can read same forward and backward
// //after remove white space and convert uppercase to lowercase
// //Example: Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.

class Solution {
public:
    bool isPalindrome(string s) {
        string newStr = "";
        for (char i : s) {
            if (isalnum(i)) {
                newStr += tolower(i);
            }
        }
        int l = 0, r = newStr.size() - 1;
        while (l < r) {
            if (newStr[l++] != newStr[r--]) return false;
        }
        return true;
    }
};