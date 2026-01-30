#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

#define KTM 50

void nhapSoNguyen(int& x, const char* str);
void taoM1C(int a[], int& n);
void xuatM1C(int a[], int n);
bool kiemTraSNT(int num);
void xuatSNT(int arr[], int n);
int* insertValue(int arr[], int n, int index, int value);
int* xoaGiaTri(int arr[], int n, int value);
int* sapXepTang(int arr[], int n);
bool kiemTraSoChinhPhuong(int num);
void xuatSCP(int arr[], int n);
bool timSoChanLonNhat(int arr[], int n, int& x);
bool timSoNguyenToNhoNhat(int arr[], int n, int& x);
int timViTriPhanTu(int arr[], int n, int x);

// --------------------------------------------
int main() {
    int arr[KTM], spt;

    

    while (true) {
        int luaChon = -1;

        cout << "----------------" << endl;
        cout << "1. Tao mang random" << endl;
        cout << "2. Xuat mang" << endl;
        cout << "3. Xuat gia tri nguyen to trong mang" << endl;
        cout << "4. Them gia tri vao mang" << endl;
        cout << "5. Xoa gia tri trong mang" << endl;
        cout << "6. Sap xep tang dan" << endl;
        cout << "7. Xuat so chinh phuong" << endl;
        cout << "8. Tim so chan lon nhat" << endl;
        cout << "9. Tim so nguyen to nho nhat" << endl;
        cout << "10. Tim vi tri phan tu X" << endl;
        cout << "0. Exit" << endl;
        cout << "----------------" << endl;
        cout << "Nhap lua chon: ";
        cin >> luaChon;

        if (luaChon == 0) {
            cout << "Exit" << endl;
            break;
        }
        else if (luaChon == 1) {
            taoM1C(arr, spt);
            cout << "Done." << endl;
        }
        else if (luaChon == 2) {
            cout << "Mang da tao" << endl;
            xuatM1C(arr, spt);
            cout << endl;
        }
        else if (luaChon == 3) {
            cout << "Cac gia tri nguyen to trong mang:" << endl;
            xuatSNT(arr, spt);
            cout << endl;
        }
        else if (luaChon == 4) {
            int index;
            int value;

            cout << "Nhap vi tri: ";
            cin >> index;
            cout << "Nhap gia tri: ";
            cin >> value;
            cout << endl;
            insertValue(arr, spt, index, value);
            cout << "Da them gia tri!" <<  endl;
            xuatM1C(arr, spt);
            cout << endl;
        }
        else if (luaChon == 5) {
            int value;

            cout << "Nhap gia tri can xoa: ";
            cin >> value;
            xoaGiaTri(arr, spt, value);
            cout << "Da xoa gia tri!" << endl;
            xuatM1C(arr, spt);
            cout << endl;
        }
        else if (luaChon == 6) {
            sapXepTang(arr, spt);
            cout << "Done." <<  endl;
        }
        else if (luaChon == 7) {
            xuatSCP(arr, spt);
            cout << "Done." << endl;
        }
        else if (luaChon == 8) {
            int x;
            bool check = timSoChanLonNhat(arr, spt, x);

            if (check == true) {
                cout << "Da tim thay so chan lon nhat: " << x << endl;
            }
            else {
                cout << "Khong tim thay" << endl;
            }
        }
        else if (luaChon == 9) {
            int x;
            bool check = timSoNguyenToNhoNhat(arr, spt, x);

            if (check == true) {
                cout << "Dax tim thay so nguyen to nho nhat: " << x << endl;
            }
            else {
                cout << "Khong tim thay." << endl;
            }
        }
        else if (luaChon == 10) {
            int x;
            cout << "Nhap gia tri can tim: ";
            cin >> x;

            int index = timViTriPhanTu(arr, spt, x);

            if (index == -1) {
                cout << "Khong tim thay." << endl;
            }
            else {
                cout << "Phan tu nam tai vi tri: " << index << endl;
            }

        }
    }
    
    return 0;
}
// --------------------------------------------

// Cau 1
void nhapSoNguyen(int& x, const char* str) {
    cout << str;
    cin >> x;
}

// Cau 1
void taoM1C(int a[], int& n) {
    nhapSoNguyen(n, "Nhap so luong phan tu: ");
    srand(time(0));

    for (int k = 0; k < n; k++) {
        a[k] = -10 + rand() % 61;
    }
}

// Cau 2
void xuatM1C(int a[], int n) {
    for (int k = 0; k < n; k++) {
        cout << a[k] << " ";
    }
}

// Cau 3
bool kiemTraSNT(int num) {
    if (num <= 1) return false;
    if (num == 2 || num == 3) return true;
    if (num % 2 == 0) return false;

    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) return false;
    }

    return true;
}

// Cau 3
void xuatSNT(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        bool check = kiemTraSNT(arr[i]);

        if (check == true) {
            cout << arr[i] << " ";
        }
    }
}

// Cau 4
int* insertValue(int arr[], int n, int index, int value) {
    int i;
    n++;

    for (i = n; i >= index; i--) {
        arr[i] == arr[i - 1];
    }

    arr[index - 1] = value;

    return arr;
}

// Cau 5
int* xoaGiaTri(int arr[], int n, int value) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            for (int j = i; j < n-1; j++) {
                arr[j] = arr[j+1];
            }
            n--;
            break;
        }
    }

    return arr;
}

// Cau 6
int* sapXepTang(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    return arr;
}

// Cau 7
bool kiemTraSoChinhPhuong(int num) {
    for (int i = 1; i < num; i++) {
        if (i * i == num) {
            return true;
        }
    }
    return false;
}

void xuatSCP(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        bool check = kiemTraSoChinhPhuong(arr[i]);

        if (check == true) {
            cout << arr[i] << " ";
        }
    }
}

// Cau 8
bool timSoChanLonNhat(int arr[], int n, int& x) {
    bool flag = false;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            if (!flag) {
                flag = true;
                x = arr[i];
            }
            else {
                if (arr[i] > x) {
                    x = arr[i];
                }
            }
        }
    }
    return flag;
}

// Cau 9
bool timSoNguyenToNhoNhat(int arr[], int n, int& x) {
    bool flag = false;

    for (int i = 0; i < n; i++) {
        bool check = kiemTraSNT(arr[i]);
        if (check == true) {
            if (flag == false) {
                flag = true;
                x = arr[i];
            }
            else {
                if (arr[i] < x) {
                    x = arr[i];
                }
            }
        }
    }
    return flag;
}

int timViTriPhanTu(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
            break;
        }
    }

    return -1;
}