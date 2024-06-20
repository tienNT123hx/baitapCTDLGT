#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Khai báo cấu trúc Node để biểu diễn các phần tử trong mục lục
struct Node {
    string title; // Tiêu đề của chương/mục
    int pageNumber; // Số trang bắt đầu của chương/mục
    vector<Node*> children; // Danh sách các mục con

    Node(string t, int p) : title(t), pageNumber(p) {}
};

// Khai báo cấu trúc Tree để biểu diễn toàn bộ mục lục
struct Tree {
    Node* root; // Gốc của cây, thường là tiêu đề của cuốn sách

    Tree() : root(nullptr) {}

    // Phương thức để thêm một node vào cây
    void addNode(Node* parent, Node* child) {
        parent->children.push_back(child);
    }

    // Phương thức để đếm số chương của cuốn sách
    int countChapters(Node* node) {
        if (node == nullptr) return 0;
        int count = (node->title.find("Chapter") != string::npos) ? 1 : 0;
        for (Node* child : node->children) {
            count += countChapters(child);
        }
        return count;
    }

    // Phương thức để tìm chương dài nhất
    Node* findLongestChapter(Node* node, int& maxPages) {
        if (node == nullptr) return nullptr;
        Node* longestChapter = nullptr;
        if (node->title.find("Chapter") != string::npos) {
            int chapterPages = node->pageNumber;
            if (!node->children.empty()) {
                chapterPages = node->children.front()->pageNumber - node->pageNumber;
            }
            if (chapterPages > maxPages) {
                maxPages = chapterPages;
                longestChapter = node;
            }
        }
        for (Node* child : node->children) {
            Node* tmp = findLongestChapter(child, maxPages);
            if (tmp != nullptr) longestChapter = tmp;
        }
        return longestChapter;
    }

    // Phương thức để tìm và xoá một mục
    bool deleteSection(Node* &node, const string& title) {
        if (node == nullptr) return false;
        if (node->title == title) {
            for (Node* child : node->children) {
                delete child;
            }
            delete node;
            node = nullptr;
            return true;
        }
        for (Node* &child : node->children) {
            if (deleteSection(child, title)) {
                return true;
            }
        }
        return false;
    }

    // Phương thức để in ra đề mục của một chương
    void printChapter(Node* node, const string& chapterTitle) {
        if (node == nullptr) return;
        if (node->title == chapterTitle) {
            cout << "Chapter: " << node->title << endl;
            for (Node* child : node->children) {
                cout << "Section: " << child->title << endl;
            }
            return;
        }
        for (Node* child : node->children) {
            printChapter(child, chapterTitle);
        }
    }
};

// Hàm main để thử nghiệm cấu trúc cây
int main() {

    // Tạo cây mục lục
    Tree bookIndex;
    bookIndex.root = new Node("Book Title", 1);

    // Thêm chương và mục
    Node* chapter1 = new Node("Chapter 1: Introduction", 2);
    bookIndex.addNode(bookIndex.root, chapter1);
    bookIndex.addNode(chapter1, new Node("Section 1.1: Overview", 3));
    // ...

    // 1. Xác định số chương của cuốn sách
    cout << "Number of chapters: " << bookIndex.countChapters(bookIndex.root) << endl;

    // 2. Tìm chương dài nhất của cuốn sách
    int maxPages = 0;
    Node* longestChapter = bookIndex.findLongestChapter(bookIndex.root, maxPages);
    cout << "Longest chapter: " << longestChapter->title << " with " << maxPages << " pages" << endl;

    // 3. Thực hiện tìm một mục và xoá mục đó khỏi sách
    string sectionToDelete = "Section 1.1: Overview";
    if (bookIndex.deleteSection(bookIndex.root, sectionToDelete)) {
        cout << "Deleted section: " << sectionToDelete << endl;
    } else {
        cout << "Section not found." << endl;
    }

    // 4. Tìm một chương bất kỳ và in ra đề mục của chương đó
    string chapterToPrint = "Chapter 1: Introduction";
    bookIndex.printChapter(bookIndex.root, chapterToPrint);

    return 0;
}