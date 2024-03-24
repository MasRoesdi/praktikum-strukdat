#include <stdio.h> // include library stdio.h, untuk struct

// membuat struct mahasiswa
struct Mahasiswa
{
    const char *name; // untuk menyimpan nama
    const char *address; // menyimpan alamat
    int age; // menyimpan umur
};
// fungsi utama, program mulai dari sini
int main() {
    struct Mahasiswa mhs1, mhs2; // membuat koleksi data mhs1 dan mhs2

    mhs1.name = "Dian"; // nama mhs1 adalah Dian
    mhs1.address = "Mataram"; // alamat mhs1 di Mataram
    mhs1.age = 22; // umur mhs1 adalah 22 tahun
    mhs2.name = "Bambang"; // nama mhs2 adalah Bambang
    mhs2.address = "Surabaya"; // alamat di Surabaya
    mhs2.age = 23; // umur 23 tahun

    // output informasi mahasiswa 1
    printf("## Mahasiswa 1 ##\n"); // header
    printf("Nama: %s\n", mhs1.name); // nama
    printf("Alamat: %s\n", mhs1.address); // alamat
    printf("Umur: %d\n", mhs1.age); // umur
    // output informasi mahasiswa 2
    printf("## Mahasiswa 2 ##\n"); // header
    printf("Nama: %s\n", mhs2.name); // nama
    printf("Alamat: %s\n", mhs2.address); // alamat
    printf("Umur: %d\n", mhs2.age); // umur
    return 0; // program selesai
}