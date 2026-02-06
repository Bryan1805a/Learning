// Tran Buu Ngoc - 231A290130

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
using namespace std;

#define KTMT 10

void menu();
void tao_ma_tran_ngau_nhien(int mt[][KTMT], int &n);
void xuat_ma_tran(int mt[][KTMT], int n);
void xuat_so_am(int mt[][KTMT], int n); // Cau 3
void tinh_tong_ma_tran(int mt[][KTMT], int n); // Cau 4
void tim_max_min(int mt[][KTMT], int n); // Cau 5
void sap_xep_tang_dan(int mt[][KTMT], int n); // Cau 6
bool tim_vi_tri_X(int mt[][KTMT], int n, int x, int &row, int &col); // Cau 7
int tim_max_theo_cot(int mt[][KTMT], int n, int k); // Cau 8
int dem_phan_tu_duong(int mt[][KTMT], int n); // Cau 9
int dem_so_lan_xuat_hien_cua_X(int mt[][KTMT], int n, int x); // Cau 10
bool is_all_even(int mt[][KTMT], int n); // Cau 11
int sum_row(int mt[][KTMT], int n, int k); // Cau 12
int tim_hang_co_sum_lon_nhat(int mt[][KTMT], int n, int m); // Cau 12

int main() {
    int arr[KTMT][KTMT], m;
    int chuc_nang;
    do {
        menu();
        cout << "Chon so: ";
        cin >> chuc_nang;

        switch (chuc_nang) {
            case 0:
                return 0;
                break;
            case 1:
                tao_ma_tran_ngau_nhien(arr, m);
                cout << "Ma tran" << endl;
                xuat_ma_tran(arr, m);
                break;
            case 2:
                cout << "Ma tran vuong: "<< endl;
                xuat_ma_tran(arr, m);
                break;
            case 3:
                cout << "Ma tran so am: " << endl;
                xuat_so_am(arr, m);
                break;
            case 4:
                tinh_tong_ma_tran(arr, m);
                break;
            case 5:
                tim_max_min(arr, m);
                break;
            case 6:
                sap_xep_tang_dan(arr, m);
                break;
            case 7:
                int x, row, col;
                cout << "Nhap gia tri can tim: ";
                cin >> x;

                if (tim_vi_tri_X(arr, m, x, row, col)) {
                    cout << "Tim thay " << x << " tai vi tri: dong = " << row << ", cot = " << col << endl;
                } else {
                    cout << "Khong tim thay gia tri " << x << endl;
                }
                cout << endl;
                break;
            case 8:
                int k;
                cout << "Nhap so dong: ";
                cin >> k;

                cout << "Phan tu lon nhat o dong " << k << ": " << tim_max_theo_cot(arr, m, k) << endl;
                cout << endl;
                break;
            case 9:
                cout << "So luong phan tu duong trong ma tran = " << dem_phan_tu_duong(arr, m) << endl;
                cout << endl;
                break;
            case 10:
                int X;
                cout << "Nhap X: ";
                cin >> X;

                cout << "So lan xuat hien cua X la " << dem_so_lan_xuat_hien_cua_X(arr, m, X) << endl;
                cout << endl;
                break;
            case 11:
                cout << endl;
                if (is_all_even(arr, m) == false) {
                    cout << "False";
                }
                else {
                    cout << "true";
                }
            default:
                break;
        }
    }
    while (chuc_nang != 0);
    return 0;
}

void menu() {
    cout << "Tran Buu Ngoc - 231A290130" << endl;
    cout << "1. Tao mang ngau nhien" << endl;
    cout << "2. Xuat mang" << endl;
    cout << "3. Xuat cac gia tri so am cua ma tran" << endl;
    cout << "4. Tinh tong ma tran" << endl;
    cout << "5. Tim max/min" << endl;
    cout << "6. Sap xep gia tri theo thu tu tang dan" << endl;
    cout << "7. Tim vi tri X" << endl;
    cout << "8. Tim phan tu Max cua dong k" << endl;
    cout << "9. Dem phan tu > 0" << endl;
    cout << "10. Dem so lan X xuat hien" << endl;
    cout << "11. Kiem tra ma tran la so chan" << endl;
    cout << "12. Tim dong co tong lon nhat" << endl;
}

void tao_ma_tran_ngau_nhien(int mt[][KTMT], int &n) {
    do {
        cout << "Nhap so luong phan tu: ";
        cin >> n;
    }
    while (n <= 0 || n > KTMT);

    srand(time(0));
    for (int k = 0; k < n; k++) {
        for (int j = 0; j < n; j++) {
            mt[k][j] = -20 + rand() % 41;
        }
    }
}

void xuat_ma_tran(int mt[][KTMT], int n) {
    for (int k = 0; k < n; k++) {
        cout << endl;
        for (int j = 0; j < n; j++) {
            cout << setw(5) << mt[k][j];
        }
    }
    cout << endl << endl;
}

// Cau 3
void xuat_so_am(int mt[][KTMT], int n) {
    for (int k = 0; k < n; k++) {
        cout << endl;
        for (int j = 0; j < n; j++) {
            if (mt[k][j] < 0) {
                cout << setw(5) << mt[k][j];
            }
            else {
                cout << setw(5) << "*";
            }
        }
    }
    cout << endl << endl;
}

// Cau 4
void tinh_tong_ma_tran(int mt[][KTMT], int n) {
    int tong = 0;
    for (int k = 0; k < n; k++) {
        for (int j = 0; j < n; j++) {
            tong += mt[k][j];
        }
    }
    
    cout << "Tong ma tran: " << tong << endl;
    cout << endl;
}

// Cau 5
void tim_max_min(int mt[][KTMT], int n) {
    
    for (int k = 0; k < n; k++) {
        for (int j = 0; j < n; j++) {
            if (mt[k][j] < mt[0][0]) {
                int temp = mt[0][0];
                mt[0][0] = mt[k][j];
                mt[k][j] = temp;
            }
            else if (mt[k][j] > mt[n-1][n-1]) {
                int temp = mt[n-1][n-1];
                mt[n-1][n-1] = mt[k][j];
                mt[k][j] = temp;
            }
        }
    }

    cout << "Phan tu lon nhat: " << mt[n-1][n-1] << endl;
    cout << "Phan tu nho nhat: " << mt[0][0] << endl;
    cout << endl;
}

// Cau 6
void sap_xep_tang_dan(int mt[][KTMT], int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (mt[k][j] > mt[k][j + 1]) {
                    int temp = mt[k][j];
                    mt[k][j] = mt[k][j + 1];
                    mt[k][j + 1] = temp;
                }
            }
        }
    }

    cout << endl;
}

// Cau 7
bool tim_vi_tri_X(int mt[][KTMT], int n, int x, int &row, int &col) {
    for (int k = 0; k < n; k++) {
        for (int j = 0; j < n; j++) {
            if (mt[k][j] == x) {
                row = k;
                col = j;
                return true;
            }
        }
    }
    return false;
}

// Cau 8
int tim_max_theo_cot(int mt[][KTMT], int n, int k) {
    int max_row = mt[k][0];
    int pos = 0;

    for (int j = 1; j < n; j++) {
        if (mt[k][j] > max_row) {
            max_row = mt[k][j];
            pos = j; // Neu can xuat vi tri (Optional)
        }
    }

    return max_row;
}

// Cau 9
int dem_phan_tu_duong(int mt[][KTMT], int n) {
    int tong = 0;

    for (int k = 0; k < n; k++) {
        for (int j = 0; j < n; j++) {
            if (mt[k][j] > 0) {
                tong += 1;
            }
        }
    }
    
    return tong;
}

// Cau 10
int dem_so_lan_xuat_hien_cua_X(int mt[][KTMT], int n, int x) {
    int tong = 0;

    for (int k = 0; k < n; k++) {
        for (int j = 0; j < n; j++) {
            if (mt[k][j] == x) {
                tong += 1;
            }
        }
    }
    
    return tong;
}

// cau 11
bool is_all_even(int mt[][KTMT], int n) {
    for (int k = 0; k < n; k++)
        for (int j = 0; j < n; j++)
            if (mt[k][j] % 2 != 0)
                return false;
    return true;
}

int sum_row(int mt[][KTMT], int n, int k) {
    int sum = 0;
    for (int j = 0; j < n; j++) {
        sum += mt[k][j];
    }
    return sum;
}

int tim_hang_co_sum_lon_nhat(int mt[][KTMT], int n, int m) {
    int max_sum = sum_row(mt, m, 0);
    int row_index = 0;

    for (int i = 1; i < n; i++) {
        int current_sum = sum_row(mt, m, i);
        if (current_sum > max_sum) {
            max_sum = current_sum;
            row_index = i;
        }
    }

    return row_index;
}