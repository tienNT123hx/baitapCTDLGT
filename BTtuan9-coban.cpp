
#include <iostream>
#include <cstring>

using namespace std;

struct Ngay {
    int ngay;
    int thang;
    int nam;
};

struct SinhVien {
    char maSV[8];
    char hoTen[50];
    int gioiTinh;
    Ngay ngaySinh;
    char diaChi[100];
    char lop[12];
    char khoa[7];
};

struct Node {
    SinhVien data;
    Node *link;
};

struct List {
    Node *first;
    Node *last;
};

// Hàm kh?i t?o danh sách
void KhoiTaoDS(List *L) {
    L->first = NULL;
    L->last = NULL;
}

// Hàm ki?m tra danh sách r?ng
bool DanhSachRong(List L) {
    return L.first == NULL;
}

// Hàm nh?p sinh viên
void NhapSV(List *L) {
    SinhVien sv;
    Node *p;

    cout << "Nhap ma sinh vien: ";
    cin >> sv.maSV;

    cout << "Nhap ho ten: ";
    cin.ignore(); // Xóa b? nh? ð?m ð?u vào
    cin.getline(sv.hoTen, 50);

    cout << "Nhap gioi tinh: ";
    cin >> sv.gioiTinh;

    cout << "Nhap ngay sinh: ";
    cin >> sv.ngaySinh.ngay >> sv.ngaySinh.thang >> sv.ngaySinh.nam;

    cout << "Nhap dia chi: ";
    cin.ignore(); // Xóa b? nh? ð?m ð?u vào
    cin.getline(sv.diaChi, 100);

    cout << "Nhap lop: ";
    cin.ignore(); // Xóa b? nh? ð?m ð?u vào
    cin.getline(sv.lop, 12);

    cout << "Nhap khoa: ";
    cin.ignore(); // Xóa b? nh? ð?m ð?u vào
    cin.getline(sv.khoa, 7);

    p = new Node;
    p->data = sv;
    p->link = NULL;

    if (DanhSachRong(*L)) {
        L->first = p;
        L->last = p;
    } else {
        p->link = L->first;
        L->first = p;
    }
}

// Hàm duy?t và in danh sách
void InDS(List L) {
    Node *p;

    if (DanhSachRong(L)) {
        cout << "Danh sach rong!\n";
        return;
    }

    p = L.first;
    while (p != NULL) {
        cout << "Ma sinh vien: " << p->data.maSV << endl;
        cout << "Ho ten: " << p->data.hoTen << endl;
        cout << "Gioi tinh: " << p->data.gioiTinh << endl;
        cout << "Ngay sinh: " << p->data.ngaySinh.ngay << "/"<< p->data.ngaySinh.thang << "/" << p->data.ngaySinh.nam << endl;
        cout << "Dia chi: " << p->data.diaChi << endl;
        cout << "Lop: " << p->data.lop << endl;
        cout << "Khoa: " << p->data.khoa << endl;
        cout << "---------------------\n";
        p = p->link;
    }
}

// Hàm t?m ki?m sinh viên theo m?
Node *TimSVTheoMa(List L, char maSV[]) {
    Node *p;

    if (DanhSachRong(L)) {
        return NULL;
    }

    p = L.first;
    while (p != NULL && strcmp(p->data.maSV, maSV) != 0) {
        p = p->link;
    }

    return p;
}

void ThemSV(List *L) {
    SinhVien sv;
    Node *p, *q;

    NhapSV(&sv);

    p = new Node;
    p->data = sv;

    if (DanhSachRong(*L)) {
        L->first = p;
        L->last = p;
    } else {
        cout << "Nhap vi tri chen (bat dau tu 1): ";
        int viTri;
        cin >> viTri;

        if (viTri < 1) {
            cout << "Vi tri chen khong hop le!\n";
            return;
        }

        q = NULL;
        for (int i = 1; i < viTri; i++) {
            if (q == NULL) {
                q = L->first;
            } else {
                q = q->link;
            }
        }

        if (q == NULL) { // Them vao cuoi danh sach
            p->link = NULL;
            L->last->link = p;
            L->last = p;
        } else {
            p->link = q->link;
            q->link = p;
        }
    }
}

void SapXepDS(List *L, char criterion[]) {
    if (DanhSachRong(*L) || L->first->link == NULL) {
        return;
    }

    for (Node *p = L->first; p->link != NULL; p = p->link) {
        for (Node *q = p->link; q != NULL; q = q->link) {
            if (strcmp(criterion, "ten") == 0) {
                if (strcmp(p->data.hoTen, q->data.hoTen) > 0) {
                    SinhVien temp = p->data;
                    p->data = q->data;
                    q->data = temp;
                }
            } else if (strcmp(criterion, "ngaysinh") == 0) {
                if (p->data.ngaySinh.nam > q->data.ngaySinh.nam ||
                    (p->data.ngaySinh.nam == q->data.ngaySinh.nam &&
                     p->data.ngaySinh.thang > q->data.ngaySinh.thang) ||
                    (p->data.ngaySinh.nam == q->data.ngaySinh.nam &&
                     p->data.ngaySinh.thang == q->data.ngaySinh.thang &&
                     p->data.ngaySinh.ngay > q->data.ngaySinh.ngay)) {
                    SinhVien temp = p->data;
                    p->data = q->data;
                    q->data = temp;
                }
            }
        }
    }
}
int main(){
    List L;
char maSV[8];
Node *p;

// Nhap du lieu cho danh sach
NhapSV(&L);
NhapSV(&L);

// Sap xep danh sach
SapXepMSV(&L);

// In danh sach
InDS(L);
}

