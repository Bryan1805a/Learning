#include <iostream>
#include <fstream>  // Thư viện bắt buộc để làm việc với file (fstream = file stream)
#include <vector>   // Dùng mảng động vector cho tiện
#include <cstdlib>  // Thư viện chứa hàm rand() và srand()
#include <ctime>    // Thư viện chứa hàm time()

using namespace std;

void ghiFile(int n) {
    ofstream fOut("songuyen.inp"); 
    
    if (!fOut) {
        cout << "Khong the tao hoac mo file!" << endl;
        return;
    }

    srand(time(NULL)); 

    for (int i = 1; i <= n; i++) {
        int r = rand() % 100; 
        fOut << r << " ";

        if (i % 10 == 0) {
            fOut << endl;
        }
    }

    fOut.close();
}

void docFileVaIn() {
    ifstream fIn("songuyen.inp");

    if (!fIn) {
        cout << "Khong tim thay file songuyen.inp de doc!" << endl;
        return;
    }

    vector<int> mangSo;
    int tam;

    
    while (fIn >> tam) {
        mangSo.push_back(tam); 
    }

    fIn.close();
    cout << "\n-> Du lieu doc duoc tu file va luu vao mang:\n";
    for (int i = 0; i < mangSo.size(); i++) {
        cout << mangSo[i] << " ";
        // In cho đẹp: xuống dòng mỗi 10 số (tương tự lúc ghi)
        if ((i + 1) % 10 == 0) cout << endl;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Nhap so luong so nguyen n can sinh: ";
    cin >> n;

    // Bước 1: Ghi file
    ghiFile(n);

    // Bước 2: Đọc file và in mảng
    docFileVaIn();

    return 0;
}