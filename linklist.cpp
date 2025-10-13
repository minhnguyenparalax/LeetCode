#include <iostream>
#include <vector>
using namespace std;

// ======= Cấu trúc Node của danh sách liên kết đơn =======
class ListNode {
public:
    int val;            // Giá trị của nút
    ListNode* next;     // Con trỏ trỏ đến nút tiếp theo

    // Constructor: khởi tạo giá trị và trỏ next = nullptr
    ListNode(int val) : val(val), next(nullptr) {}

    // Constructor khác: cho phép chỉ định luôn nút tiếp theo
    ListNode(int val, ListNode* next) : val(val), next(next) {}
};

// ======= Lớp LinkedList: Quản lý danh sách liên kết đơn =======
class LinkedList {
private:
    ListNode* head; // Con trỏ đầu danh sách (dummy head)
    ListNode* tail; // Con trỏ cuối danh sách

public:
    // ======= Hàm khởi tạo =======
    LinkedList() {
        // Dùng "dummy node" để đơn giản hóa việc xóa đầu danh sách
        head = new ListNode(-1);
        tail = head;
    }

    // ======= Lấy giá trị tại chỉ số index =======
    int get(int index) {
        ListNode* curr = head->next;
        int i = 0;
        while (curr != nullptr) {
            if (i == index) {
                return curr->val;
            }
            i++;
            curr = curr->next;
        }
        return -1; // Nếu index vượt quá độ dài danh sách
    }

    // ======= Chèn phần tử vào đầu danh sách =======
    void insertHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head->next;
        head->next = newNode;
        // Nếu danh sách trống ban đầu, cập nhật lại tail
        if (newNode->next == nullptr) {
            tail = newNode;
        }
    }

    // ======= Chèn phần tử vào cuối danh sách =======
    void insertTail(int val) {
        tail->next = new ListNode(val);
        tail = tail->next;
    }

    // ======= Xóa phần tử tại vị trí index =======
    bool remove(int index) {
        int i = 0;
        ListNode* curr = head;
        while (i < index && curr != nullptr) {
            i++;
            curr = curr->next;
        }

        // Nếu tìm thấy nút cần xóa
        if (curr != nullptr && curr->next != nullptr) {
            if (curr->next == tail) {
                tail = curr; // Nếu xóa nút cuối, cập nhật tail
            }
            ListNode* toDelete = curr->next;
            curr->next = curr->next->next;
            delete toDelete;
            return true;
        }
        return false;
    }

    // ======= Trả về toàn bộ giá trị trong danh sách =======
    vector<int> getValues() {
        vector<int> res;
        ListNode* curr = head->next;
        while (curr != nullptr) {
            res.push_back(curr->val);
            curr = curr->next;
        }
        return res;
    }

    // ======= In danh sách ra màn hình =======
    void printList() {
        ListNode* curr = head->next;
        cout << "Danh sach: ";
        while (curr != nullptr) {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

// ======= Hàm main để chạy thử =======
int main() {
    LinkedList list;

    // Thêm phần tử vào cuối danh sách
    list.insertTail(10);
    list.insertTail(20);
    list.insertTail(30);
    list.printList(); // Kết quả: 10 20 30

    // Thêm phần tử vào đầu danh sách
    list.insertHead(5);
    list.printList(); // Kết quả: 5 10 20 30

    // Lấy giá trị tại index 2
    cout << "Gia tri tai vi tri 2: " << list.get(2) << endl; // 20

    // Xóa phần tử tại index 1
    list.remove(1);
    list.printList(); // Kết quả: 5 20 30

    // Lấy toàn bộ giá trị ra vector
    vector<int> vals = list.getValues();
    cout << "Cac gia tri trong vector: ";
    for (int v : vals) cout << v << " ";
    cout << endl;

    return 0;
}
