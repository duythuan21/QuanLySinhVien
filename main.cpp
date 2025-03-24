#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

#define MAX 100

struct SinhVien {
    char maSV[10];
    char hoTen[50];
    char ngaySinh[15];
    char noiSinh[50];
    char lopHoc[10];
    float diemToan;
    float diemTriet;
    float diemAnh;
    float diemTB;
    char xepLoai[15];
};

SinhVien danhSachSV[MAX];
int soLuongSV = 0;

void tinhDiemTB(SinhVien &sv) {
    sv.diemTB = (sv.diemToan + sv.diemTriet + sv.diemAnh) / 3.0;
    if (sv.diemTB >= 8.0)
        strcpy(sv.xepLoai, "Gioi");
    else if (sv.diemTB >= 6.5)
        strcpy(sv.xepLoai, "Kha");
    else if (sv.diemTB >= 5.0)
        strcpy(sv.xepLoai, "Trung binh");
    else
        strcpy(sv.xepLoai, "Yeu");
}

void nhapSV() {
    if (soLuongSV >= MAX) {
        cout << "Danh sach da day!\n";
        return;
    }
    SinhVien sv;
    cout << "Nhap ma SV: "; cin >> sv.maSV;
    cin.ignore();
    cout << "Nhap ho va ten: "; cin.getline(sv.hoTen, 50);
    cout << "Nhap ngay sinh: "; cin >> sv.ngaySinh;
    cout << "Nhap noi sinh: "; cin >> sv.noiSinh;
    cout << "Nhap lop hoc: "; cin >> sv.lopHoc;
    cout << "Nhap diem Toan: "; cin >> sv.diemToan;
    cout << "Nhap diem Triet: "; cin >> sv.diemTriet;
    cout << "Nhap diem Anh: "; cin >> sv.diemAnh;
    tinhDiemTB(sv);
    danhSachSV[soLuongSV++] = sv;
    cout << "\nSinh vien da duoc them thanh cong!\n";
}

void luuFile() {
    ofstream file("ctql.dat", ios::binary);
    if (!file) {
        cout << "Loi mo file!\n";
        return;
    }
    file.write((char*)danhSachSV, sizeof(SinhVien) * soLuongSV);
    file.close();
    cout << "Da luu danh sach vao file ctql.dat\n";
}

void docFile() {
    ifstream file("ctql.dat", ios::binary);
    if (!file) {
        cout << "Loi mo file hoac file chua ton tai!\n";
        return;
    }
    soLuongSV = 0;
    while (file.read((char*)&danhSachSV[soLuongSV], sizeof(SinhVien))) {
        soLuongSV++;
    }
    file.close();
}

void inDanhSachSV() {
    cout << left << setw(10) << "Ma SV" << setw(20) << "Ho Ten" << setw(12) << "Ngay Sinh"
         << setw(12) << "Noi Sinh" << setw(8) << "Lop" << setw(8) << "Toan"
         << setw(8) << "Triet" << setw(8) << "Anh" << setw(8) << "TB" << "Xep Loai" << endl;
    for (int i = 0; i < soLuongSV; i++) {
        cout << left << setw(10) << danhSachSV[i].maSV << setw(20) << danhSachSV[i].hoTen << setw(12) << danhSachSV[i].ngaySinh
             << setw(12) << danhSachSV[i].noiSinh << setw(8) << danhSachSV[i].lopHoc << setw(8) << danhSachSV[i].diemToan
             << setw(8) << danhSachSV[i].diemTriet << setw(8) << danhSachSV[i].diemAnh << setw(8) << fixed << setprecision(2) << danhSachSV[i].diemTB
             << danhSachSV[i].xepLoai << endl;
    }
}

void timSVTheoMa() {
    char maSV[10];
    cout << "Nhap ma SV can tim: "; cin >> maSV;
    for (int i = 0; i < soLuongSV; i++) {
        if (strcmp(danhSachSV[i].maSV, maSV) == 0) {
            cout << "Tim thay sinh vien: " << danhSachSV[i].hoTen << " - Lop: " << danhSachSV[i].lopHoc << " - Xep loai: " << danhSachSV[i].xepLoai << endl;
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
