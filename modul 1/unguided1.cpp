#include <iostream> //`Memanggil` library iostream untuk input/output

using namespace std; //Set default library ke std

// fungsi boolean untuk autentikasi pengguna
// parameter berupa username dan pin akun
// akan mengembalikan nilai boolean
// true jika sesuai, false jika salah
bool checkAuth(string username, int pin) {
    // cek username dan pin
    // jika username bukan bakso dan pin bukan 17701369
    // maka jalankan perintah
    if (username != "bakso" && pin != 17701369) {
        return false; // mengembalikan nilai false
    }
    // jika username adalah bakso dan pin adalah 17701369
    // maka jalankan perintah
    else {
        return true; // mengembalikan nilai true
    }
}

// deklarasi fungsi main, program pertama kali di eksekusi dari fungsi ini.
int main() {
    string username; // untuk menyimpan nama pengguna berupa huruf dan angka
    int pin; // untuk menyimpan pin pengguna, hanya untuk angka

    // menampilkan interface
    cout << "==========[ Bank Abang ]==========" << endl;
    cout << "Masukkan username: "; // meminta username
    cin >> username; // input username
    cout << "Masukkan 8 angka pin: "; // meminta pin
    cin >> pin; // memasukkan pin

    // mengecek autentikasi pengguna dengan memanggil fungsi checkAuth
    // jika return fungsi adalah true, maka pengguna akan disambut
    if (checkAuth(username, pin)) {
        cout << "Selamat datang, bakso!" << endl; // sambut pengguna
    }
    // jika tidak, maka akan muncul pesan
    else {
        cout << "Kredensial salah, memberhentikan program..." << endl; // pesan kredensial salah
    }

    return 0; // memberhentikan program
}