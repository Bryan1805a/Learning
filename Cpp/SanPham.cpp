#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_SP = 100;

struct SanPham {
    string maSP;   
    string tenSP;  
    int soLuong;
    double giaBan;
};

void inSanPham(const SanPham& sp) {
    cout << left << setw(10) << sp.maSP
         << setw(35) << sp.tenSP
         << setw(10) << sp.soLuong
         << setw(15) << fixed << setprecision(2) << sp.giaBan << "\n";
}

double tinhDoanhThu(const SanPham& sp) {
    
    return sp.soLuong * sp.giaBan * 0.9;
}

void docDuLieu(SanPham dssp[], int& n, const string& tenFile) {
    ifstream file(tenFile);
    if (!file.is_open()) {
        cout << "Error: Cannot open file" << tenFile << "!\n";
        n = 0;
        return;
    }

    n = 0;
    SanPham sp;
    
    while (n < MAX_SP && file >> sp.maSP) {
        file.ignore(); 
        getline(file, sp.tenSP); 
        file >> sp.soLuong >> sp.giaBan;
        
        dssp[n] = sp; 
        n++;          
    }
    file.close();
}

void xuatDanhSach(const SanPham dssp[], int n) {
    cout << string(70, '-') << "\n";
    cout << left << setw(10) << "Ma SP" << setw(35) << "Ten San Pham" 
         << setw(10) << "So Luong" << setw(15) << "Gia Ban" << "\n";
    cout << string(70, '-') << "\n";
    for (int i = 0; i < n; i++) {
        inSanPham(dssp[i]);
    }
    cout << string(70, '-') << "\n";
}


void inSanPhamSoLuong20Den50(const SanPham dssp[], int n) {
    cout << "\n--- Danh sach san pham co so luong tu 20 den 50 ---\n";
    bool timThay = false;
    for (int i = 0; i < n; i++) {
        if (dssp[i].soLuong >= 20 && dssp[i].soLuong <= 50) {
            inSanPham(dssp[i]);
            timThay = true;
        }
    }
    if (!timThay) cout << "Khong co san pham nao thoa man dieu kien.\n";
}


double tinhTongDoanhThu(const SanPham dssp[], int n) {
    double tong = 0;
    for (int i = 0; i < n; i++) {
        tong += tinhDoanhThu(dssp[i]);
    }
    return tong;
}

void sapXepTheoTenGiamDan(SanPham dssp[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            
            if (dssp[i].tenSP < dssp[j].tenSP) {
                
                SanPham temp = dssp[i];
                dssp[i] = dssp[j];
                dssp[j] = temp;
            }
        }
    }
}

void inSanPhamGiaThapNhat(const SanPham dssp[], int n) {
    if (n == 0) return;
    
    cout << "\n--- Cac san pham co gia ban thap nhat ---\n";
    double giaMin = dssp[0].giaBan;
    
    
    for (int i = 1; i < n; i++) {
        if (dssp[i].giaBan < giaMin) giaMin = dssp[i].giaBan;
    }
    
    
    for (int i = 0; i < n; i++) {
        if (dssp[i].giaBan == giaMin) inSanPham(dssp[i]);
    }
}

void timKiemTheoMaSP(const SanPham dssp[], int n, const string& maCanTim) {
    cout << "\n--- Tim kiem san pham co ma: " << maCanTim << " ---\n";
    for (int i = 0; i < n; i++) {
        if (dssp[i].maSP == maCanTim) {
            inSanPham(dssp[i]);
            return; 
        }
    }
    cout << "Day la san pham chuan bi nhap ve\n";
}

int main() {
    SanPham dssp[MAX_SP]; 
    int n = 10;
    
    docDuLieu(dssp, n, "C:/Users/Bryan/Documents/Learning/Cpp/data.txt");
    if (n == 0) {
        cout << "Khong co du lieu de xu ly.\n";
        return 1;
    }
    cout << "Danh sach san pham vua doc tu file:\n";
    xuatDanhSach(dssp, n);
    
    inSanPhamSoLuong20Den50(dssp, n);
    
    cout << "\ne. Tong doanh thu tat ca san pham: " << fixed << setprecision(2) 
         << tinhTongDoanhThu(dssp, n) << "\n";
    
    sapXepTheoTenGiamDan(dssp, n);
    cout << "\nf. Danh sach san pham sau khi sap xep Giam Dan theo Ten:\n";
    xuatDanhSach(dssp, n);
    inSanPhamGiaThapNhat(dssp, n);
    timKiemTheoMaSP(dssp, n, "SP005"); 
    timKiemTheoMaSP(dssp, n, "SP999"); 

    return 0;
}