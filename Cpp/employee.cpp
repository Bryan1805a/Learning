#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define MAX 10

struct NhanVien {
    string hoTen;
    float bacLuong;
};


void writeFile(string tenFile, NhanVien ds[], int n) {
    ofstream out(tenFile);

    for (int i = 0; i < n; i++) {
        out << ds[i].hoTen << "#" 
            << ds[i].bacLuong << endl;
    }

    out.close();
}


void docFile(string tenFile, NhanVien ds[], int &n) {
    ifstream inFile(tenFile);
    string line;
    n = 0;

    while (getline(inFile, line) && n < MAX) {
        int pos = line.find('#');

        ds[n].hoTen = line.substr(0, pos);
        ds[n].bacLuong = stof(line.substr(pos + 1));

        n++;
    }

    inFile.close();
}


void xuatBacLuongLonHon(NhanVien ds[], int n) {
    cout << "\nNhan vien co bac luong > 2.34:\n";

    for (int i = 0; i < n; i++) {
        if (ds[i].bacLuong > 2.34) {
            cout << ds[i].hoTen << " - " << ds[i].bacLuong << endl;
        }
    }
}


void xuatVaTinhLuong(NhanVien ds[], int n) {
    cout << "\nDanh sach nhan vien va luong:\n";

    for (int i = 0; i < n; i++) {
        float luong = ds[i].bacLuong * 1150000;

        cout << ds[i].hoTen << " - Bac luong: " << ds[i].bacLuong << " - Luong: " << luong << endl;
    }
}


void timBacLuongMax(NhanVien ds[], int n) {
    float max = ds[0].bacLuong;

    for (int i = 1; i < n; i++) {
        if (ds[i].bacLuong > max) {
            max = ds[i].bacLuong;
        }
    }

    cout << "\nBac luong cao nhat: " << max << endl;
}

int main() {

    NhanVien ds[MAX];
    int n;
    n = 3;

    for (int i = 0; i < n; i++) {
        cout << "Nhap ho ten: ";
        getline(cin, ds[i].hoTen);

        cout << "Nhap bac luong: ";
        cin >> ds[i].bacLuong;
        cin.ignore();
    }

    writeFile("nhanvien.txt", ds, n);
    docFile("nhanvien.txt", ds, n);

    xuatBacLuongLonHon(ds, n);
    xuatVaTinhLuong(ds, n);
    timBacLuongMax(ds, n);

    return 0;
}