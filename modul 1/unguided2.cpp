#include <iostream> // memanggil library iostream, input output
#include <stdio.h> // memanggil library stdio, supaya bisa menggunakan struct
#include <string> // memanggil library string, untuk menggunakan tipe data string

using namespace std; // set default library ke std (standard library)

// Membuat class baru dengan nama player
class player {
    // semacam flag atau identifier (tanda) yang memberitahu compiler bahwa
    // kode di bawah kata kunci 'PUBLIC' dapat diakses oleh semua fungsi.
    // ini ada hubungannya dengan OOP.
    public:
        // set attribut class
        int id; // attribut id
        string name; // attribut nama pemain
        int clanId; // attribut id clan pemain

        // deklarasi method dalam class
        // untuk method di bawah, digunakan untuk menampilkan info terkait player
        void playerInfo() {
            cout << "ID: " << id << endl; // output id pemain
            cout << "Name: " << name << endl; // output nama pemain
            cout << "Clan ID: " << clanId << endl; // output id clain pemain
        }
};

// Membuat struct baru dengan nama clan
struct clan {
    // set attribut dari struct
    int id; // attribut id
    string name; // attribut nama

    // set method di dalam struct
    // method ini hanya digunakan untuk mengembalikan nilai name
    string getName() {
        return name; // mengembalikan nama klan
    }
};

// deklarasi fungsi utama
int main() {
    player player1; // deklarasi player1
    clan clan1; // deklarasi clan1

    player1.id = 1; // mengisi attribut id pemain
    player1.name = "John"; // mengisi attribut nama pemain
    player1.clanId = 1; // mengisi attribut id clan pemain

    clan1.id = 1; // mengisi attribut id klan
    clan1.name = "John Clan"; // mengisi attribut nama klan

    player1.playerInfo(); // memanggil fungsi untuk menampilkan info dari attribut player1

    cout << "ID: " << clan1.id << endl; // output id klan
    cout << "Name: " << clan1.name << endl; // output nama klan

    return 0; // memberhentikan program
}