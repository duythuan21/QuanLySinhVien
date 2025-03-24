#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

struct SinhVien {
    string maSV;
    string hoTen;
    string ngaySinh;
    string noiSinh;
    string lopHoc;
    float diemToan;
    float diemTriet;
    float diemAnh;
    float diemTB;
    string xepLoai;
};

vector<SinhVien> danhSachSV;

void tinhDiemTB(SinhVien &sv) {
    sv.diemTB = (sv.diemToan + sv.diemTriet + sv.diemAnh) / 3.0;
    if (sv.diemTB >= 8.0)
        sv.xepLoai = "Gioi";
    else if (sv.diemTB >= 6.5)
        sv.xepLoai = "Kha";
    else if (sv.diemTB >= 5.0)
        sv.xepLoai = "Trung binh";
    else
        sv.xepLoai = "Yeu";
}

void nhapSV() {
    SinhVien sv;
    cout << "Nhap ma SV: "; cin >> sv.maSV;
    cin.ignore();
    cout << "Nhap ho va ten: "; getline(cin, sv.hoTen);
    cout << "Nhap ngay sinh: "; cin >> sv.ngaySinh;
    cout << "Nhap noi sinh: "; cin >> sv.noiSinh;
    cout << "Nhap lop hoc: "; cin >> sv.lopHoc;
    cout << "Nhap diem Toan: "; cin >> sv.diemToan;
    cout << "Nhap diem Triet: "; cin >> sv.diemTriet;
    cout << "Nhap diem Anh: "; cin >> sv.diemAnh;
    tinhDiemTB(sv);
    danhSachSV.push_back(sv);
    cout << "\nSinh vien da duoc them thanh cong!\n";
}

void luuFile() {
    ofstream file("ctql.dat", ios::binary);
    if (!file) {
        cout << "Loi mo file!\n";
        return;
    }
    size_t size = danhSachSV.size();
    file.write(reinterpret_cast<char*>(&size), sizeof(size));
    file.write(reinterpret_cast<char*>(danhSachSV.data()), size * sizeof(SinhVien));
    file.close();
    cout << "Da luu danh sach vao file ctql.dat\n";
}

void docFile() {
    ifstream file("ctql.dat", ios::binary);
    if (!file) {
        cout << "Loi mo file hoac file chua ton tai!\n";
        return;
    }
    size_t size;
    file.read(reinterpret_cast<char*>(&size), sizeof(size));
    danhSachSV.resize(size);
    file.read(reinterpret_cast<char*>(danhSachSV.data()), size * sizeof(SinhVien));
    file.close();
}

void inDanhSachSV() {
    cout << left << setw(10) << "Ma SV" << setw(20) << "Ho Ten" << setw(12) << "Ngay Sinh"
         << setw(12) << "Noi Sinh" << setw(8) << "Lop" << setw(8) << "Toan"
         << setw(8) << "Triet" << setw(8) << "Anh" << setw(8) << "TB" << "Xep Loai" << endl;
    for (const auto &sv : danhSachSV) {
        cout << left << setw(10) << sv.maSV << setw(20) << sv.hoTen << setw(12) << sv.ngaySinh
             << setw(12) << sv.noiSinh << setw(8) << sv.lopHoc << setw(8) << sv.diemToan
             << setw(8) << sv.diemTriet << setw(8) << sv.diemAnh << setw(8) << fixed << setprecision(2) << sv.diemTB
             << sv.xepLoai << endl;
    }
}

void timSVTheoMa() {
    string maSV;
    cout << "Nhap ma SV can tim: "; cin >> maSV;
    for (const auto &sv : danhSachSV) {
        if (sv.maSV == maSV) {
            cout << "Tim thay sinh vien: " << sv.hoTen << " - Lop: " << sv.lopHoc << " - Xep loai: " << sv.xepLoai << endl;
            return;
        }
    }
    cout << "Khong tim thay sinh vien!\n";
}

int main() {
    int choice;
    do {
        cout << "\nMENU\n";
        cout << "(1) Nhap thong tin SV\n";
        cout << "(2) In danh sach SV\n";
        cout << "(3) Tim thong tin cua 1 sinh vien (dua vao MSSV)\n";
        cout << "(4) Luu danh sach vao file\n";
        cout << "(5) Doc danh sach tu file\n";
        cout << "(6) Thoat\n";
        cout << "Chon chuc nang: ";
        cin >> choice;
        switch (choice) {
            case 1: nhapSV(); break;
            case 2: inDanhSachSV(); break;
            case 3: timSVTheoMa(); break;
            case 4: luuFile(); break;
            case 5: docFile(); break;
            case 6: cout << "Thoat chuong trinh!\n"; break;
            default: cout << "Lua chon khong hop le!\n";
        }
    } while (choice != 6);
    return 0;
}
