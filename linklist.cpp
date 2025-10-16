#include <iostream>
#include <vector>
using namespace std;

// ========================================================
// 🧩 Cấu trúc Node (nút) của danh sách liên kết đơn
// ========================================================
class ListNode {
public:
    int val;            // Giá trị lưu trong nút
    ListNode* next;     // Con trỏ trỏ đến nút kế tiếp trong danh sách

    // Constructor 1: Khởi tạo nút với giá trị và con trỏ = nullptr
    ListNode(int val) : val(val), next(nullptr) {}

    // Constructor 2: Khởi tạo nút và chỉ định luôn nút tiếp theo
    ListNode(int val, ListNode* next) : val(val), next(next) {}
};

// ========================================================
// 📘 Lớp LinkedList: Quản lý danh sách liên kết đơn
// ========================================================
class LinkedList {
private:
    ListNode* head; // Con trỏ đầu danh sách (dùng dummy node để dễ xử lý)
    ListNode* tail; // Con trỏ trỏ đến nút cuối cùng

public:
    // ======= Hàm khởi tạo danh sách =======
    LinkedList() {
        head = new ListNode(-1); // Dummy head: không chứa dữ liệu thực, chỉ làm gốc
        tail = head;             // Lúc đầu, tail trỏ cùng head (vì danh sách rỗng)
    }

    // ========================================================
    // 🔍 Lấy giá trị tại vị trí index (0-based)
    // Trả về -1 nếu index không hợp lệ
    // ========================================================
    int get(int index) {
        ListNode* curr = head->next; // Bắt đầu từ nút đầu tiên thật sự
        int i = 0;
        while (curr != nullptr) {
            if (i == index) return curr->val; // Nếu đếm đủ index thì trả về giá trị
            i++;
            curr = curr->next;
        }
        return -1; // Nếu index vượt giới hạn
    }

    // ========================================================
    // ➕ Chèn phần tử vào đầu danh sách (sau dummy head)
    // ========================================================
    void insertHead(int val) {
        // Tạo nút mới
        ListNode* newNode = new ListNode(val);

        // Nối nút mới vào đầu danh sách
        newNode->next = head->next;
        head->next = newNode;

        // Nếu trước đó danh sách rỗng → cập nhật tail
        if (newNode->next == nullptr) tail = newNode;
    }

    // ========================================================
    // ➕ Chèn phần tử vào cuối danh sách
    // ========================================================
    void insertTail(int val) {
        tail->next = new ListNode(val); // Tạo nút mới và nối vào cuối
        tail = tail->next;              // Cập nhật tail trỏ đến nút mới
    }

    // ========================================================
    // ❌ Xóa phần tử tại vị trí index
    // Trả về true nếu xóa thành công, false nếu không tìm thấy
    // ========================================================
    bool remove(int index) {
        int i = 0;
        ListNode* curr = head; // Duyệt từ dummy head
        while (i < index && curr != nullptr) {
            i++;
            curr = curr->next;
        }

        // Nếu curr hợp lệ và có nút kế tiếp để xóa
        if (curr != nullptr && curr->next != nullptr) {
            // Nếu nút bị xóa là nút cuối → cập nhật tail
            if (curr->next == tail) tail = curr;

            // Giải phóng bộ nhớ cho nút cần xóa
            ListNode* toDelete = curr->next;
            curr->next = curr->next->next;
            delete toDelete;
            return true;
        }
        return false; // Không tìm thấy vị trí hợp lệ
    }

    // ========================================================
    // 🖨️ In toàn bộ danh sách ra màn hình
    // ========================================================
    void printList() {
        ListNode* curr = head->next;
        cout << "Danh sach hien tai: ";
        while (curr != nullptr) {
            cout << curr->val << " "; // In giá trị từng nút
            curr = curr->next;
        }
        cout << endl;
    }
};

// ========================================================
// 🚀 Hàm main: Giao diện nhập lệnh từ người dùng
// ========================================================
int main() {
    LinkedList list; // Tạo danh sách rỗng ban đầu
    int choice;      // Lưu lựa chọn menu của người dùng

    do {
        // ======= Hiển thị menu =======
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

        // ======= Xử lý lựa chọn =======
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
            if (value == -1)
                cout << "Khong ton tai vi tri nay!\n";
            else
                cout << "Gia tri tai vi tri " << index << " la: " << value << endl;
        }
        else if (choice == 4) {
            int index;
            cout << "Nhap vi tri can xoa: ";
            cin >> index;
            if (list.remove(index))
                cout << "Da xoa thanh cong.\n";
            else
                cout << "Khong ton tai vi tri nay!\n";
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
