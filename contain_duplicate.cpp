#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// ===== Hàm kiểm tra xem có phần tử trùng không =====
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

// ===== Hàm main: cho phép người dùng tự nhập =====
int main() {
    int n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Nhap " << n << " phan tu: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << boolalpha; // In "true/false" thay vì "1/0"
    bool result = containsDuplicate(nums);

    cout << "Mang co phan tu trung? " << result << endl;

    return 0;
}
