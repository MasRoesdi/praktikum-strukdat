#include <iostream> // memanggil library iostream, input output

using namespace std; // set default library ke std

// titik awal eksekusi program
int main()
{
    int nilai[5]; // buat array baru dengan 5 slot item
    nilai[0] = 23; // item index-0 bernilai 23
    nilai[1] = 50; // item index-1 bernilai 50
    nilai[2] = 34; // item index-2 bernilai 34
    nilai[3] = 78; // item index-3 bernilai 78
    nilai[4] = 90; // item index-4 bernilai 90

    // output isi array
    cout << "Isi array pertama : " << nilai[0] << endl; // output index-0
    cout << "Isi array kedua : " << nilai[1] << endl; // output index-1
    cout << "Isi array ketiga : " << nilai[2] << endl; // output index-2
    cout << "Isi array keempat : " << nilai[3] << endl; // output index-3
    cout << "Isi array kelima : " << nilai[4] << endl; // output index-4
    return 0; // program selesai
}