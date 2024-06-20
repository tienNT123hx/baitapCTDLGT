#include <iostream>
#include <string>
using namespace std;

// Khai báo cấu trúc Node để biểu diễn mỗi mục trong mục lục
struct Node {
    int index; // Index dạng số
    string title; // Tên mục dạng chuỗi ký tự
    Node* left; // Con trái
    Node* right; // Con phải

    Node(int idx, string t) : index(idx), title(t), left(nullptr), right(nullptr) {}
};

// Hàm để so sánh hai cây nhị phân
bool areIdentical(Node* root1, Node* root2) {
    // Nếu cả hai cây đều trống, chúng giống nhau
    if (root1 == nullptr && root2 == nullptr) return true;

    // Nếu một trong hai cây trống, chúng không giống nhau
    if (root1 == nullptr || root2 == nullptr) return false;

    // Kiểm tra index và title của node hiện tại và tiếp tục so sánh các node con
    return (root1->index == root2->index) && (root1->title == root2->title) &&
           areIdentical(root1->left, root2->left) &&
           areIdentical(root1->right, root2->right);
}

// Hàm main để thử nghiệm giải thuật
int main() {
    // Tạo cây nhị phân cho sách 1
    Node* root1 = new Node(1, "Book Title");
    root1->left = new Node(2, "Chapter 1: Introduction");
    root1->right = new Node(3, "Chapter 2: Background");
    root1->left->left = new Node(4, "Section 1.1: Overview");
    root1->left->right = new Node(5, "Section 1.2: Basics");

    // Tạo cây nhị phân cho sách 2
    Node* root2 = new Node(1, "Book Title");
    root2->left = new Node(2, "Chapter 1: Introduction");
    root2->right = new Node(3, "Chapter 2: Background");
    root2->left->left = new Node(4, "Section 1.1: Overview");
    root2->left->right = new Node(5, "Section 1.2: Basics");

    // Gọi hàm areIdentical để kiểm tra
    if (areIdentical(root1, root2)) {
        cout << "Hai cuon sach la ban copy cua nhau" << endl;
    } else {
        cout << "Hai cuon sach khong phai la ban copy cua nhau" << endl;
    }

    // Giải phóng bộ nhớ
    delete root1->left->left;
    delete root1->left->right;
    delete root1->left;
    delete root1->right;
    delete root1;

    delete root2->left->left;
    delete root2->left->right;
    delete root2->left;
    delete root2->right;
    delete root2;

    return 0;
}