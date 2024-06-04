#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Kieu cua cac nut tren cay (chua thong tin ve mot sinh vien).
struct Node {
    int sbd; // So bao danh
    string hoTen; // Ho ten sinh vien
    Node* left; // Con tro toi nut con trai
    Node* right; // Con tro toi nut con phai

    // Ham tao.
    Node(int s, string h, Node* l = nullptr, Node* r = nullptr) 
        : sbd(s), hoTen(h), left(l), right(r) {}
};

// Lop cay nhi phan tim kiem.
class BSTree {
public:
    // Ham tao (ban dau cay rong).
    BSTree() : root(nullptr) {}

    // Ham huy (xoa het cac nut tren cay).
    ~BSTree() {
        makeEmpty();
    }

    // Kiem tra cay co rong hay khong.
    bool isEmpty() const {
        return root == nullptr;
    }

    // Xoa het cac nut tren cay.
    void makeEmpty() {
        makeEmpty(root);
    }

    // Chen mot sinh vien moi vao cay.
    void insert(int sbd, string hoTen) {
        insert(sbd, hoTen, root);
    }

    // Tim sinh vien theo so bao danh.
    Node* search(int sbd) const {
        return search(sbd, root);
    }

    // Duyet cay theo thu tu truoc (Preorder).
    void preorderTraversal() const {
        preorderTraversal(root);
        cout << endl;
    }

    // Duyet cay theo thu tu giua (Inorder).
    void inorderTraversal() const {
        inorderTraversal(root);
        cout << endl;
    }

    // Duyet cay theo thu tu sau (Postorder).
    void postorderTraversal() const {
        postorderTraversal(root);
        cout << endl;
    }

    // Ham sap xep vun dong (heap sort).
    void heapSort() {
        vector<Node*> nodes;
        storeNodes(root, nodes);
        makeEmpty();
        buildHeap(nodes);
        for (Node* node : nodes) {
            insert(node->sbd, node->hoTen);
        }
    }

private:
    Node* root; // Con tro toi nut goc cua cay

    // Xoa rong cay (viet theo kieu de quy).
    void makeEmpty(Node*& t) {
        if (t != nullptr) {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
            t = nullptr;
        }
    }

    // Chen mot sinh vien moi vao cay (viet theo kieu de quy).
    void insert(int sbd, string hoTen, Node*& t) {
        if (t == nullptr) {
            t = new Node(sbd, hoTen);
        } else if (sbd < t->sbd) {
            insert(sbd, hoTen, t->left);
        } else if (sbd > t->sbd) {
            insert(sbd, hoTen, t->right);
        }
    }

    // Tim sinh vien theo so bao danh (viet theo kieu de quy).
    Node* search(int sbd, Node* t) const {
        if (t == nullptr || t->sbd == sbd) {
            return t;
        } else if (sbd < t->sbd) {
            return search(sbd, t->left);
        } else {
            return search(sbd, t->right);
        }
    }

    // Duyet cay theo thu tu truoc (Preorder).
    void preorderTraversal(Node* t) const {
        if (t != nullptr) {
            cout << t->sbd << " - " << t->hoTen << " ";
            preorderTraversal(t->left);
            preorderTraversal(t->right);
        }
    }

    // Duyet cay theo thu tu giua (Inorder).
    void inorderTraversal(Node* t) const {
        if (t != nullptr) {
            inorderTraversal(t->left);
            cout << t->sbd << " - " << t->hoTen << " ";
            inorderTraversal(t->right);
        }
    }

    // Duyet cay theo thu tu sau (Postorder).
    void postorderTraversal(Node* t) const {
        if (t != nullptr) {
            postorderTraversal(t->left);
            postorderTraversal(t->right);
            cout << t->sbd << " - " << t->hoTen << " ";
        }
    }

    // Ham storeNodes: luu tru cac node vao vector.
    void storeNodes(Node* t, vector<Node*>& nodes) {
        if (t == nullptr) return;
        storeNodes(t->left, nodes);
        nodes.push_back(t);
        storeNodes(t->right, nodes);
    }

    // Ham buildHeap: xay dung heap tu cac node.
    void buildHeap(vector<Node*>& nodes) {
        int n = nodes.size();
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(nodes, n, i);
        }
        for (int i = n - 1; i > 0; i--) {
            swap(nodes[0], nodes[i]);
            heapify(nodes, i, 0);
        }
    }

    // Ham heapify: tao vun dong.
    void heapify(vector<Node*>& nodes, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && nodes[left]->sbd > nodes[largest]->sbd) {
            largest = left;
        }
        if (right < n && nodes[right]->sbd > nodes[largest]->sbd) {
            largest = right;
        }
        if (largest != i) {
            swap(nodes[i], nodes[largest]);
            heapify(nodes, n, largest);
        }
    }
};

int main() {
    BSTree bst;
    // Chen mot so sinh vien moi vao cay.
    bst.insert(5, "Tuan");
    bst.insert(6, "Lan");
    bst.insert(3, "Cong");
    bst.insert(8, "Huong");
    bst.insert(7, "Binh");
    bst.insert(4, "Hai");
    bst.insert(2, "Son");

    // Tim hai sinh vien co so bao danh 4 va 9.
    Node* n1 = bst.search(4);
    Node* n2 = bst.search(9);

    // In ket qua tim kiem
    if (n1 != nullptr)
        cout << "Sinh vien voi SBD=4 la " << n1->hoTen << endl;
    if (n2 == nullptr)
        cout << "Khong tim thay sinh vien voi SBD=9" << endl;

    // In cay theo thu tu giua (Inorder).
    cout << "Inorder traversal before sorting: ";
    bst.inorderTraversal();

    // Sap xep vun dong
    bst.heapSort();

    // In cay theo thu tu giua (Inorder).
    cout << "Inorder traversal after sorting: ";
    bst.inorderTraversal();

    // Lam rong cay.
    bst.makeEmpty();
    if (bst.isEmpty())
        cout << "Cay da bi xoa rong" << endl;

    return 0;
}