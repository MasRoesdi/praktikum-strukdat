#include <iostream> // memanggil library iostream untuk input output

using namespace std; // default library std

// fungsi main, start program dari sini
int main() {
    char op; // variabel op untuk menyimpan operasi yang akan dilakukan pengguna
    float num1, num2; // tempat menyimpan angka satu dan angka dua

    cout << "Masukkan operator (+, -, *, /) : "; // meminta operator aritmatika
    cin >> op; // input operator
    cout << "Masukkan dua angka : "; // meminta dua angka
    cin >> num1 >> num2; // input dua angka
    // percabangan dari input operasi pengguna
    switch (op)
    {   
        // jika operator yang diinputkan adalah +, maka perintah di dalam case akan dijalankan
        case '+':
            cout << "Hasil penjumlahan: " << num1 + num2; // tampil hasil penjumlahan
            break; // memberhentikan case supaya case lain tidak dijalankan
        // jika operator adalah -
        case '-':
            cout << "Hasil pengurangan: " << num1 - num2; // tampil hasil pengurangan
            break; //memberhentikan case
        // jika operator adalah *
        case '*':
            cout << "Hasil perkalian: " << num1 * num2; // tampil hasil perkalian
            break; // stop case
        // jika operator adalah /
        case '/':
            // cek apakah angka kedua tidak sama dengan 0
            if (num2 != 0) {
                cout << "Hasil pembagian: " << num1 / num2; // tampil hasil pembagian
            }
            // jika angka kedua sama dengan 0
            else {
                cout << "Error! Tidak dapat melakukan pembagian dengan nol."; // tampil error
            }
            break; // stop case
        // selain keempat operator di atas, default akan dieksekusi
        default:
            cout << "Error! operator is not correct."; // tampil error
    }
    return 0; // program berhenti
}