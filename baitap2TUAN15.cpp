#include <iostream>
#include <cstddef>
 
template <typename T>
class BinaryTree {
private:
    struct Node {
        T data;
        Node *left;
        Node *right;
        Node *parent;
 
        Node(T val) : data(val), left(nullptr), right(nullptr), parent(nullptr) {}
    };
 
    Node *root;
    size_t size;
 
    void clear(Node *node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }
 
public:
    BinaryTree() : root(nullptr), size(0) {
        std::cout << "Cay nhi phan da duoc khoi tao." << std::endl;
    }
 
    ~BinaryTree() {
        clear(root);
        std::cout << "Cay nhi phan da duoc huy." << std::endl;
    }
 
    void InitBTree() {
        clear(root);
        root = nullptr;
        size = 0;
        std::cout << "Cay nhi phan da duoc lam rong." << std::endl;
    }
 
    Node *InsertParent(T x, Node *P) {
        if (!P && !root) {
            root = new Node(x);
            size = 1;
            std::cout << "Nut goc da duoc chen vao cay." << std::endl;
            return root;
        }
        return nullptr; // Khong the chen nut cha neu P khong phai la null hoac cay khong rong
    }
 
    Node *InsertLeftChild(T x, Node *P) {
        if (P && !P->left) {
            P->left = new Node(x);
            P->left->parent = P;
            size++;
            std::cout << "Nut con trai da duoc chen vao cay." << std::endl;
            return P->left;
        }
        return nullptr; // Khong the chen nut con trai neu P la null hoac nut con trai da ton tai
    }
 
    Node *InsertRightChild(T x, Node *P) {
        if (P && !P->right) {
            P->right = new Node(x);
            P->right->parent = P;
            size++;
            std::cout << "Nut con phai da duoc chen vao cay." << std::endl;
            return P->right;
        }
        return nullptr; // Khong the chen nut con phai neu P la null hoac nut con phai da ton tai
    }
 
    Node *FindNode(T x, Node *node = nullptr) {
        if (!node) node = root;
        if (!node) return nullptr;
        if (node->data == x) return node;
        Node *foundNode = FindNode(x, node->left);
        if (!foundNode) foundNode = FindNode(x, node->right);
        return foundNode;
    }
 
    void DeleteCurrentNode(Node *P) {
        if (P == root) {
            clear(root);
            root = nullptr;
            size = 0;
            std::cout << "Nut goc da duoc xoa." << std::endl;
        } else if (P) {
            if (P->parent->left == P) P->parent->left = nullptr;
            if (P->parent->right == P) P->parent->right = nullptr;
            clear(P);
            size--;
            std::cout << "Nut da duoc xoa khoi cay." << std::endl;
        }
    }
 
    void DeleteLeftChild(Node *P) {
        if (P && P->left) {
            clear(P->left);
            P->left = nullptr;
            size--;
            std::cout << "Nut con trai da duoc xoa." << std::endl;
        }
    }
 
    void DeleteRightChild(Node *P) {
        if (P && P->right) {
            clear(P->right);
            P->right = nullptr;
            size--;
            std::cout << "Nut con phai da duoc xoa." << std::endl;
        }
    }
 
    size_t GetSize() const {
        std::cout << "Kich thuoc cua cay: " << size << std::endl;
        return size;
    }
};
 
int main() {
    BinaryTree<int> tree;
    // Khởi tạo cây rỗng
    tree.InitBTree();
    // Chèn nút cha (chỉ khi cây rỗng)
    auto rootNode = tree.InsertParent(1, nullptr);
    // Chèn nút con trái và nút con phải
    auto leftChild = tree.InsertLeftChild(2, rootNode);
    auto rightChild = tree.InsertRightChild(3, rootNode);
    // Tìm nút có giá trị 2
    auto foundNode = tree.FindNode(2);
    if (foundNode != nullptr) {
        std::cout << "Tim thay nut co gia tri 2." << std::endl;
    }
    // Xóa nút hiện tại (nút con trái)
    tree.DeleteCurrentNode(leftChild);
    // Xóa nút con phải của rootNode
    tree.DeleteRightChild(rootNode);
    // Lấy kích thước của cây
    size_t size = tree.GetSize();
    return 0;
}