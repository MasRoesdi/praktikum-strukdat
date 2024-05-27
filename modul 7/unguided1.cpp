#include <iostream>
using namespace std;

const int maksimalQueue = 5; // Batas maksimal antrian
int front = 0;               // Indeks awal antrian
int back = 0;                // Indeks akhit antrian

struct Mahasiswa {
    string nama;
    string nim;
    Mahasiswa *next;
};

Mahasiswa *head = nullptr;
Mahasiswa *tail = nullptr;

// Fungsi untuk melihat apakah antrian penuh
bool isFull()
{
    return back == maksimalQueue;
}

// Fungsi untuk melihat apakah antrian kosong atau tidak
bool isEmpty()
{
    return back == 0;
}

// Fungsi untuk menambahkan elemen ke antrian
void enqueueAntrian(string nama, string nim)
{
    Mahasiswa *baru = new Mahasiswa;
    baru->nama = nama;
    baru->nim = nim;
    baru->next = nullptr;
    if (tail != nullptr) {
        tail->next = baru;
        tail = baru;
    }
    else {
        head = baru;
        tail = baru;
    }
    back++;
}

// Fungsi untuk menghapus elemen dari antrian
void dequeueAntrian()
{
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        Mahasiswa *temp = head;
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            head = head->next;
        }
        delete temp;
        back--;
    }
}

// Fungsi untuk menghitung banyak elemen dalam antrian
int countQueue()
{
    return back;
}

// Fungsi untuk menghapus semua elemen dalam antrian
void clearQueue()
{
    Mahasiswa *temp = head;
    head = nullptr;
    tail = nullptr;
    for (int i = 0; i < back - 1; i++)
    {
        Mahasiswa *del = temp;
        temp = temp->next;
        delete del;
    }
    delete temp;
    back = 0;
    front = 0;
}

// Fungsi untuk melihat antrian semua elemen dalam antrian
void viewQueue()
{ 
    Mahasiswa *temp = head;
    cout << "Data antrian saat ini [Total " << countQueue() << " antrian]: " << endl;
    for (int i = 0; i < maksimalQueue; i++)
    {
        if (i < back)
        {
            cout << i + 1 << ". " << temp->nama << " : " << temp->nim << endl;
            temp = temp->next;
        }
        else
        {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main()
{
    string line(15, '=');
    int choice;
    
    while(true) {
        cout << endl << line << "[ Antrian Mahasiswa ]" << line << endl;
        viewQueue();
        cout << "\nPilih menu : \n";
        cout << "1. Tambah antrian\n2. Hapus antrian\n3. Bersihkan antrian\n0. Keluar\n";
        cout << "\nMasukkan pilihan : ";
        cin >> choice;
        cin.ignore();

        switch(choice) {
            case 0 : return 0;
            case 1 : {
                if (isFull()) {
                    cout << "Antrian sudah penuh." << endl;
                }
                else {
                    string nama, nim;
                    cout << "Masukkan nama mahasiswa : ";
                    getline(cin, nama);
                    cout << "Masukkan NIM : ";
                    getline(cin, nim);
                    enqueueAntrian(nama, nim);
                    cout << nama << " berhasil dimasukkan ke antrian." << endl;
                }
                break;
            }
            case 2 : {
                string temp = head->nama;
                dequeueAntrian();
                cout << temp << " berhasil dikeluarkan dari antrian." << endl;
                break;
            }
            case 3 : {
                char clarify;
                cout << "Apakah anda yakin untuk menghapus semua data antrian? [Y/T]";
                cin >> clarify;
                if (tolower(clarify) == 'y') {
                    clearQueue();
                    cout << "Semua data berhasil dihapus.\n\n";
                }
                else {
                    cout << "Penghapusan dibatalkan.\n\n";
                }
                break;
            }
        }
    }

    return 0;
}
