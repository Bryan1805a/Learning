#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

#define KTM 30

struct SinhVien {
    string maSV, hoLot, ten;
    float diemTB;
};

void readStudentList(SinhVien a[], int& n, const char fileName[]);
void printStudentList(SinhVien a[], int n);
void printStudent(SinhVien sv);
void sortStudent(SinhVien a[], int n);
void findStudentWithHighestScore(SinhVien a[], int n);

int main() {
    SinhVien studentList[KTM];
    int soSV;

    readStudentList(studentList, soSV, "C:\\Users\\Bryan\\Documents\\Learning\\Cpp\\data\\student_list.txt");
    sortStudent(studentList, soSV);
    printStudentList(studentList, soSV);
    findStudentWithHighestScore(studentList, soSV);
    return 0;
}

void printStudent(SinhVien sv) {
    cout << setw(5) << sv.maSV << setw(31) << sv.hoLot << setw(6) << sv.ten << setw(5) << sv.diemTB << endl;
}

void printStudentList(SinhVien a[], int n) {
    for (int i = 0; i < n; i++) {
        printStudent(a[i]);
    }
}

void readStudentList(SinhVien a[], int& n, const char fileName[]) {
    ifstream inFile;
    inFile.open(fileName, ios::in);

    if (inFile.is_open()) {
        inFile >> n;

        for (int i = 0; i < n; i++) {
            getline(inFile, a[i].maSV, '#');
            getline(inFile, a[i].hoLot, '#');
            getline(inFile, a[i].ten, '#');
            inFile >> a[i].diemTB;
        }
    }
    else {
        cout << "Error";
    }
}

void sortStudent(SinhVien a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i].diemTB > a[j].diemTB) {
                SinhVien temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void findStudentWithHighestScore(SinhVien a[], int n) {
    SinhVien highestScore = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i].diemTB > highestScore.diemTB) {
            highestScore = a[i];
        }
    }

    for (int k = 0; k < n; k++) {
        if (a[k].diemTB == highestScore.diemTB) {
            printStudent(highestScore);
        }
    }
}