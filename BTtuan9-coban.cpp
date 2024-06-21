#include<bits/stdc++.h>
using namespace std;

struct SinhVien {
    string maSV;
    string hoTen;
    string gioiTinh;
    string ngaySinh;
    string diaChi;
    string lop;
    string khoa;
};

void nhapThongTin(SinhVien& sv) {
    cout << "Nhap ma sinh vien: ";
    cin >> sv.maSV;
    cin.ignore();
    cout << "Nhap ho ten: ";
    getline(cin, sv.hoTen);
    cout << "Nhap gioi tinh: ";
    cin >> sv.gioiTinh;
    cin.ignore();
    cout << "Nhap ngay sinh (dd): ";
    string ngay;
    getline(cin, ngay);
    cout << "Nhap thang sinh (mm): ";
    string thang;
    getline(cin, thang);
    cout << "Nhap nam sinh (yyyy): ";
    string nam;
    getline(cin, nam);
    sv.ngaySinh = ngay + "/" + thang + "/" + nam;
    cout << "Nhap dia chi: ";
    getline(cin, sv.diaChi);
    cout << "Nhap lop: ";
    cin >> sv.lop;
    cin.ignore();
    cout << "Nhap khoa: ";
    getline(cin, sv.khoa);
}

bool compare(const SinhVien& sv1, const SinhVien& sv2) {
    return sv1.maSV < sv2.maSV;
}

void themSinhVien(list<SinhVien>& ListSV, SinhVien sv) {
    ListSV.push_back(sv);
    ListSV.sort(compare);
}

void loaiVaInSinhVienTrungNgaySinh(list<SinhVien>& ListSV) {
    map<string, int> count;
    for (auto it = ListSV.begin(); it != ListSV.end(); ++it) {
        count[it->ngaySinh]++;
    }

    bool foundDuplicate = false;
    for (auto it = ListSV.begin(); it != ListSV.end(); ) {
        if (count[it->ngaySinh] > 1) {
            it = ListSV.erase(it);
            foundDuplicate = true;
        } else {
            ++it;
        }
    }

    if (!foundDuplicate) {
        cout << "Khong co sinh vien nao trung ngay sinh." << endl;
    } else {
        for (auto it = ListSV.begin(); it != ListSV.end(); ++it) {
            cout << "Ma sinh vien: " << it->maSV << endl;
            cout << "Ho ten: " << it->hoTen << endl;
            cout << "Gioi tinh: " << it->gioiTinh << endl;
            cout << "Ngay sinh: " << it->ngaySinh << endl;
            cout << "Dia chi: " << it->diaChi << endl;
            cout << "Lop: " << it->lop << endl;
            cout << "Khoa: " << it->khoa << endl;
            cout << "-------------------------" << endl;
        }
    }
}

int main() {
    list<SinhVien> ListSV;
    SinhVien sv;
    int n;

    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << ":" << endl;
        nhapThongTin(sv);
        themSinhVien(ListSV, sv);
    }

    loaiVaInSinhVienTrungNgaySinh(ListSV);

    cout << "Nhap thong tin sinh vien can them: " << endl;
    nhapThongTin(sv);
    themSinhVien(ListSV, sv);

    cout << "Danh sach sinh vien sau khi them: " << endl;
    for (auto it = ListSV.begin(); it != ListSV.end(); ++it) {
        cout << "Ma sinh vien: " << it->maSV << endl;
        cout << "Ho ten: " << it->hoTen << endl;
        cout << "Gioi tinh: " << it->gioiTinh << endl;
        cout << "Ngay sinh: " << it->ngaySinh << endl;
        cout << "Dia chi: " << it->diaChi << endl;
        cout << "Lop: " << it->lop << endl;
        cout << "Khoa: " << it->khoa << endl;
        cout << "-------------------------" << endl;
    }

    return 0;
}
