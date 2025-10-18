#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen; // Tập hợp lưu các số đã gặp

    for (int n : nums) {
        if (seen.count(n)) {
            // Nếu số n đã xuất hiện trong set => có phần tử trùng
            return true;
        }
        seen.insert(n); // Nếu chưa, thêm vào set
    }
    return false; // Không có phần tử trùng
}

// ==== Hàm main để test thử ====
int main() {
    vector<int> nums1 = {1, 2, 3, 3};
    vector<int> nums2 = {1, 2, 3, 4};

    cout << boolalpha; // In true/false thay vì 1/0
    cout << "Example 1: " << containsDuplicate(nums1) << endl; // true
    cout << "Example 2: " << containsDuplicate(nums2) << endl; // false

    return 0;
}
