#include <iostream>
using namespace std;

// Deklarasi Struct Node
struct Node {
    string nama;
    int umur;
    Node* next;
};

Node* head;
Node* tail;

// Inisialisasi Node
void init() {
    head = NULL;
    tail = NULL;
}

// Pengecekan apakah list kosong
bool isEmpty() {
    return head == NULL;
}

// Tambah Node di depan
void insertDepan(string nama, int umur) {
    Node* baru = new Node;
    baru->nama = nama;
    baru->umur = umur;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
}

// Tambah Node di belakang
void insertBelakang(string nama, int umur) {
    Node* baru = new Node;
    baru->nama = nama;
    baru->umur = umur;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// Hitung jumlah Node di list
int hitungList() {
    Node* hitung = head;
    int jumlah = 0;
    while (hitung != NULL) {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

// Tambah Node di posisi tengah
void insertTengah(string nama, int umur, int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi diluar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node* baru = new Node();
        baru->nama = nama;
        baru->umur = umur;
        Node* bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Node di depan
void hapusDepan() {
    if (!isEmpty()) {
        Node* hapus = head;
        if (head->next != NULL) {
            head = head->next;
            delete hapus;
        } else {
            head = tail = NULL;
            delete hapus;
        }
    } else {
        cout << "List kosong!" << endl;
    }
}

// Hapus Node di belakang
void hapusBelakang() {
    if (!isEmpty()) {
        if (head != tail) {
            Node* hapus = tail;
            Node* bantu = head;
            while (bantu->next != tail) {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        } else {
            head = tail = NULL;
        }
    } else {
        cout << "List kosong!" << endl;
    }
}

// Hapus Node di posisi tengah
void hapusTengah(int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi diluar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node* hapus;
        Node* bantu = head;
        for (int nomor = 1; nomor < posisi - 1; nomor++) {
            bantu = bantu->next;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
}

// Ubah data Node di depan
void ubahDepan(string nama, int umur) {
    if (!isEmpty()) {
        head->nama = nama;
        head->umur = umur;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah data Node di posisi tengah
void ubahTengah(string nama, int umur, int posisi) {
    if (!isEmpty()) {
        if (posisi < 1 || posisi > hitungList()) {
            cout << "Posisi di luar jangkauan" << endl;
        } else if (posisi == 1) {
            cout << "Posisi bukan posisi tengah" << endl;
        } else {
            Node* bantu = head;
            for (int nomor = 1; nomor < posisi; nomor++) {
                bantu = bantu->next;
            }
            bantu->nama = nama;
            bantu->umur = umur;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah data Node di belakang
void ubahBelakang(string nama, int umur) {
    if (!isEmpty()) {
        tail->nama = nama;
        tail->umur = umur;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus semua Node di list
void clearList() {
    Node* bantu = head;
    while (bantu != NULL) {
        Node* hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan semua data Node di list
void tampil() {
    if (!isEmpty()) {
        Node* bantu = head;
        cout << "Daftar data :" << endl;
        while (bantu != NULL) {
            cout << bantu->nama << " : " << bantu->umur << endl;
            bantu = bantu->next;
        }
        cout << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

string inNama() {
    string nama;
    cout << endl << "Masukkan nama -> ";
    cin >> nama;
    return nama;
}

int inUmur() {
    int umur;
    cout << endl << "Masukkan umur -> ";
    cin >> umur;
    return umur;
}

int inPosisi() {
    int posisi;
    cout << endl << "Masukkan posisi data -> ";
    cin >> posisi;
    return posisi;
}

int main() {
    bool runApp = true;
    string line = "============";
    int choice;
    init();

    cout << "Selamat datang!" << endl;
    while(runApp) {
        cout << line << "[ List perintah ]" << line << endl;
        cout << "1. Masukkan data (depan)" << endl;
        cout << "2. Masukkan data (belakang)" << endl;
        cout << "3. Masukkan data (tengah)" << endl;
        cout << "4. Hapus data (depan)" << endl;
        cout << "5. Hapus data (belakang)" << endl;
        cout << "6. Hapus data (tengah)" << endl;
        cout << "7. Ubah data (depan)" << endl;
        cout << "8. Ubah data (belakang)" << endl;
        cout << "9. Ubah data (tengah)" << endl;
        cout << "10. Tampil data" << endl;
        cout << line << line << line;
        cout << endl << "Masukkan pilihan [1 - 9] -> ";
        cin >> choice;

        switch(choice) {
            case 1: insertDepan(inNama(), inUmur()); break;
            case 2: insertBelakang(inNama(), inUmur()); break;
            case 3: insertTengah(inNama(), inUmur(), inPosisi()); break;
            case 4: hapusDepan(); break;
            case 5: hapusBelakang(); break;
            case 6: hapusTengah(inPosisi()); break;
            case 7: ubahDepan(inNama(), inUmur()); break;
            case 8: ubahBelakang(inNama(), inUmur()); break;
            case 9: ubahTengah(inNama(), inUmur(), inPosisi()); break;
            case 10: tampil(); break;
            default: cout << "Input tidak valid!" << endl << endl;
        }
    }
    return 0;
}