/*
Tran Buu Ngoc - 231A290130
Buoi 5: Lam viec voi file
27/2/2016
*/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#define KTM 50

void read_file(int a[], int &n, const char file_name[]);
void print_file(int a[], int n);

void read_2d_array(int a[][KTM], int &row, int &col, const char file_name[]);
void print_2d_array(int a[][KTM], int row, int col);

// ------------------------------------------------------------

int main() {
    int arr[KTM], sopt;
    read_file(arr, sopt, "C:\\Users\\Bryan\\Documents\\Learning\\Cpp\\data\\one_d_array.txt");
    print_file(arr, sopt);

    int mt[KTM][KTM], row, col;
    read_2d_array(mt, row, col, "C:\\Users\\Bryan\\Documents\\Learning\\Cpp\\data\\two_d_array.txt");
    print_2d_array(mt, row, col);
    return 0;
}

// ------------------------------------------------------------

void read_file(int a[], int &n, const char file_name[]) {
    ifstream inFile;
    inFile.open(file_name, ios::in);

    if (inFile.is_open()) {
        inFile >> n;

        for (int k = 0; k < n; k++) {
            inFile >> a[k];
        }

        inFile.close();
    }
    else {
        cout << "\nCannot open file";
    }
}

void print_file(int a[], int n) {
    cout << "\nArray contents:\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

void read_2d_array(int a[][KTM], int &row, int &col, const char file_name[]) {
    ifstream inFile;
    inFile.open(file_name, ios::in);

    if (inFile.is_open()) {
        inFile >> row >> col;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                inFile >> a[i][j];
            }
        }

        inFile.close();
    }
    else {
        cout << "Error";
    }
}

void print_2d_array(int a[][KTM], int row, int col) {
    cout << "\nContent:\n";

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << setw(4) << a[i][j];
        }
        cout << endl;
    }
}