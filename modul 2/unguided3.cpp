#include <iostream>

using namespace std;

int main() {
    bool runApp = true;
    int arr[5];
    int max, min, avg = 0, choice;
    
    cout << "Masukkan 5 data array : ";
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    while (runApp) {
        cout << endl << "1. Tampilkan nilai maksimum";
        cout << endl << "2. Tampilkan nilai minimum";
        cout << endl << "3. Tampilkan nilai rata - rata";
        cout << endl << "Masukkan pilihan [1-3] : ";
        cin >> choice;

        switch (choice) {
            case 1 : {
                cout << "Nilai maksimum : ";
                max = arr[0];
                for (int i = 1; i < 5; i++) {
                    if (arr[i] > max) max = arr[i];
                }
                cout << max << endl;
                break;
            }
            case 2: {
                cout << "Nilai minimum : ";
                min = arr[0];
                for (int i = 1; i < 5; i++) {
                    if (arr[i] < min) min = arr[i];
                }
                cout << min << endl;
                break;
            }
            case 3: {
                cout << "Nilai rata - rata : ";
                for (int i = 0; i < 5; i++) {
                    avg += arr[i];
                }
                avg /= 5;
                cout << avg << endl;
                break;
            }
            default: cout << "Input tidak valid!" << endl;
        }
    }
}