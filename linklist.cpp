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
        head = new ListNode(-1); // Dùng "dummy node"
        tail = head;
    }

    // ======= Lấy giá trị tại chỉ số index =======
    int get(int index) {
        ListNode* curr = head->next;
        int i = 0;
        while (curr != nullptr) {
            if (i == index) return curr->val;
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
        if (newNode->next == nullptr) tail = newNode;
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

        if (curr != nullptr && curr->next != nullptr) {
            if (curr->next == tail) tail = curr; // Nếu xóa nút cuối
            ListNode* toDelete = curr->next;
            curr->next = curr->next->next;
            delete toDelete;
            return true;
        }
        return false;
    }

    // ======= In danh sách ra màn hình =======
    void printList() {
        ListNode* curr = head->next;
        cout << "Danh sach hien tai: ";
        while (curr != nullptr) {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

// ======= Hàm main: cho phép nhập lệnh từ người dùng =======
int main() {
    LinkedList list;
    int choice;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Chen vao dau danh sach\n";
        cout << "2. Chen vao cuoi danh sach\n";
        cout << "3. Lay gia tri tai vi tri\n";
        cout << "4. Xoa phan tu tai vi tri\n";
        cout << "5. In danh sach\n";
        cout << "0. Thoat\n";
        cout << "================\n";
        cout << "Nhap lua chon: ";
        cin >> choice;

        if (choice == 1) {
            int val;
            cout << "Nhap gia tri can chen vao dau: ";
            cin >> val;
            list.insertHead(val);
        }
        else if (choice == 2) {
            int val;
            cout << "Nhap gia tri can chen vao cuoi: ";
            cin >> val;
            list.insertTail(val);
        }
        else if (choice == 3) {
            int index;
            cout << "Nhap vi tri can lay: ";
            cin >> index;
            int value = list.get(index);
            if (value == -1) cout << "Khong ton tai vi tri nay!\n";
            else cout << "Gia tri tai vi tri " << index << " la: " << value << endl;
        }
        else if (choice == 4) {
            int index;
            cout << "Nhap vi tri can xoa: ";
            cin >> index;
            if (list.remove(index)) cout << "Da xoa thanh cong.\n";
            else cout << "Khong ton tai vi tri nay!\n";
        }
        else if (choice == 5) {
            list.printList();
        }
        else if (choice == 0) {
            cout << "Thoat chuong trinh.\n";
        }
        else {
            cout << "Lua chon khong hop le!\n";
        }

    } while (choice != 0);

    return 0;
}

