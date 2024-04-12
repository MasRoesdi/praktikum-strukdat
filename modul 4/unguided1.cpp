#include <iostream>
#include <iomanip>
using namespace std;

struct Node {
    string nama;
    string nim;
    Node *next;
};

Node *head;
Node *tail;

void init() {
    head = NULL;
    tail = NULL;
}

bool isEmpty() {
    return head == NULL;
}

void insertDepan(string nama, string nim) {
    Node *baru = new Node;
    baru->nama = nama;
    baru->nim = nim;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
    cout << "\nData telah ditambahkan\n";
}

void insertBelakang(string nama, string nim) {
    Node *baru = new Node;
    baru->nama = nama;
    baru->nim = nim;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
    cout << "\nData telah ditambahkan\n";
}

int hitungList() {
    Node *hitung = head;
    int jumlah = 0;
    while (hitung != NULL) {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

void insertTengah(string nama, string nim, int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi diluar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node *baru = new Node();
        baru->nama = nama;
        baru->nim = nim;
        Node *bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

void hapusDepan() {
    if (!isEmpty()) {
        Node *hapus = head;
        string namaLama = head->nama;
        if (head->next != NULL) {
            head = head->next;
        } else {
            head = tail = NULL;
        }
        delete hapus;
        cout << "\nData " << namaLama << " berhasil dihapus\n";
    } else {
        cout << "List kosong!" << endl;
    }
}

void hapusBelakang() {
    if (!isEmpty()) {
        Node *hapus = tail;
        string namaLama = tail->nama;
        if (head != tail) {
            Node *bantu = head;
            while (bantu->next != tail) {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        } else {
            head = tail = NULL;
        }
        delete hapus;
        cout << "\nData " << namaLama << " berhasil dihapus\n";
    } else {
        cout << "List kosong!" << endl;
    }
}

void hapusTengah(string nama, string nim) {
    if (!isEmpty()) {
        Node *bantu = head;
        Node *hapus;
        Node *sebelum = NULL;
        while (bantu != NULL) {
            if (bantu->nama == nama && bantu->nim == nim) {
                hapus = bantu;
                if (sebelum != NULL) {
                    sebelum->next = bantu->next;
                } else {
                    head = bantu->next;
                }
                delete hapus;
                cout << "\nData " << nama << " berhasil dihapus\n";
                return;
            }
            sebelum = bantu;
            bantu = bantu->next;
        }
        cout << "\nData tidak ditemukan\n";
    }
    else {
        cout << "List kosong!\n";
    }
    
}

void ubahDepan(string nama, string nim) {
    if (!isEmpty()) {
        string namaLama = head->nama;
        head->nama = nama;
        head->nim = nim;
        cout << "\nData " << namaLama << " telah diganti dengan data " << nama << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

void ubahTengah(string nama, string nim, string namaLama, string nimLama) {
    if (!isEmpty()) {
        Node *bantu = head;
        while (bantu != NULL) {
            if (bantu->nama == namaLama && bantu->nim == nimLama) {
                bantu->nama = nama;
                bantu->nim = nim;
                cout << "\nData " << namaLama << " telah diganti dengan data " << nama << endl;
                return;
            }
            bantu = bantu->next;
        }
        cout << "\nData tidak ditemukan\n";
    } else {
        cout << "List masih kosong!" << endl;
    }
}

void ubahBelakang(string nama, string nim) {
    if (!isEmpty()) {
        string namaLama = tail->nama;
        tail->nama = nama;
        tail->nim = nim;
        cout << "\nData " << namaLama << " telah diganti dengan \nData " << nama << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

void clearList() {
    Node *bantu = head;
    Node *hapus;
    while (bantu != NULL) {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

void tampil() {
    Node *bantu = head;
    cout << "\nData MAHASISWA\n\n" << setw(32) << left << "NAMA" << setw(32) << left << "NIM";
    cout << endl;
    if (!isEmpty()) {
        while (bantu != NULL) {
            cout << setw(32) << left << bantu->nama << setw(32) << left << bantu->nim;
            cout << endl;
            bantu = bantu->next;
        }
        cout << endl << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

string inputNama(bool baru = true) {
    string nama;
    if (baru) {
        cout << "Masukkan nama : ";
    }
    else {
        cout << "Masukkan nama lama : ";
    }
    cin >> nama;
    return nama;
}

string inputNIM(bool baru = true) {
    string nim;
    if (baru) {
        cout << "Masukkan NIM : ";
    }
    else {
        cout << "Masukkan NIM lama : ";
    }
    cin >> nim;
    return nim;
}

int inputPosisi() {
    int posisi;
    cout << "Masukkan posisi : ";
    cin >> posisi;
    return posisi;
}

int main() {
    init();
    int pilih;
    while (true) {
        cout << "PROGRAM SINGLE LINKED LIST NON-CIRCULAR\n\n";
        cout << "1. Tambah Depan\n";
        cout << "2. Tambah Belakang\n";
        cout << "3. Tambah Tengah\n";
        cout << "4. Ubah Depan\n";
        cout << "5. Ubah Belakang\n";
        cout << "6. Ubah Tengah\n";
        cout << "7. Hapus Depan\n";
        cout << "8. Hapus Belakang\n";
        cout << "9. Hapus Tengah\n";
        cout << "10. Hapus List\n";
        cout << "11. TAMPILKAN\n";
        cout << "0. Keluar\n\n";
        cout << "Pilih Operasi : ";
        cin >> pilih;

        switch (pilih) {
            case 0: {
                return 0;
            }
            case 1: {
                cout << "\n- Tambah Depan\n\n";
                string nama = inputNama();
                string nim = inputNIM();
                insertDepan(nama, nim);
                break;
            }
            case 2: {
                cout << "\n- Tambah Belakang\n\n";
                string nama = inputNama();
                string nim = inputNIM();
                insertBelakang(nama, nim);
                break;
            }
            case 3: {
                cout << "\n- Tambah Tengah\n\n";
                string nama = inputNama();
                string nim = inputNIM();
                int posisi = inputPosisi();
                insertTengah(nama, nim, posisi);
                break;
            }
            case 4: {
                cout << "\n- Ubah Depan\n\n";
                string nama = inputNama();
                string nim = inputNIM();
                ubahDepan(nama, nim);
                break;
            }
            case 5: {
                cout << "\n- Ubah Depan\n\n";
                string nama = inputNama();
                string nim = inputNIM();
                ubahBelakang(nama, nim);
                break;
            }
            case 6: {
                cout << "\n- Ubah Tengah\n\n";
                string namaLama = inputNama(false);
                string nimLama = inputNIM(false);
                string nama = inputNama();
                string nim = inputNIM();
                ubahTengah(nama, nim, namaLama, nimLama);
                break;
            }
            case 7: {
                cout << "\n- Hapus Depan\n\n";
                hapusDepan();
                break;
            }
            case 8: {
                cout << "\n- Hapus Belakang\n\n";
                hapusBelakang();
                break;
            }
            case 9: {
                cout << "\n- Hapus Tengah\n\n";
                string nama = inputNama();
                string nim = inputNIM();
                hapusTengah(nama, nim);
                break;
            }
            case 10: {
                cout << "\n- Hapus List\n\n";
                clearList();
                break;
            }
            case 11: {
                tampil();
                break;
            }
            default: cout << "Pilihan tidak valid\n\n";
        }
    }
    return 0;
}