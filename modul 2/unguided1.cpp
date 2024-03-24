#include <iostream>

using namespace std;

int main() {
    int arr[10];
    
    cout << "Masukkan 10 data array : ";
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }
    cout << "Nomor genap : ";
    for (int i = 0; i < 10; i++) {
        if (arr[i] % 2 == 0) {
            cout << arr[i] << ", ";
        }
    }
    cout << endl << "Nomor ganjil : ";
    for (int i = 0; i < 10; i++) {
        if (arr[i] % 2 != 0) {
            cout << arr[i] << ", ";
        }
    }
}