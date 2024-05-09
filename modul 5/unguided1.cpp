#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int TABLE_SIZE = 10;
string NIM;
int score;

class HashNode {
public:
    string NIM;
    int score;
    HashNode(string NIM, int score) {
        this->NIM = NIM;
        this->score = score;
    }
};

class HashTable {
private:
    vector<HashNode *> table[TABLE_SIZE];
public:
    int hash(string key) {
        int hashVal = 0;
        for (char c : key)
        {
            hashVal += c;
        }
        return hashVal % TABLE_SIZE;
    }

    void insert(string NIM, int score) {
        int hashVal = hash(NIM);
        for (auto node : table[hashVal]) {
            if (node->NIM == NIM) {
                node->NIM = NIM;
                return;
            }
        }
        table[hashVal].push_back(new HashNode(NIM, score));
    }

    void remove(string NIM) {
        int hashVal = hash(NIM);
        for (auto it = table[hashVal].begin(); it != table[hashVal].end(); it++) {
            if ((*it)->NIM == NIM) {
                table[hashVal].erase(it);
                return;
            }
        }
    }

    int searchByNIM(string NIM) {
        int hashVal = hash(NIM);
        for (auto node : table[hashVal])
        {
            if (node->NIM == NIM)
            {
                return node->score;
            }
        }
        return -1;
    }

    void searchByScore(int scores[2]) {
        if (scores[0] > scores[1]) {
            int temp = scores[0];
            scores[0] = scores[1];
            scores[1] = temp;
        }
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            cout << i << ": ";
            for (auto pair : table[i])
            {
                if (pair != nullptr && pair->score >= scores[0] && pair->score <= scores[1])
                {
                    cout << "[" << pair->NIM << ", " << pair->score << "]";
                }
            }
            cout << endl;
        }
    }

    void print()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            cout << i + 1 << ": ";
            for (auto pair : table[i])
            {
                if (pair != nullptr)
                {
                    cout << "[" << pair->NIM << ", " << pair->score << "]";
                }
            }
            cout << endl;
        }
    }
};

string inNIM() {
    string NIM;
    cout << "Masukkan NIM mahasiswa -> ";
    cin >> NIM;
    return NIM;
}

int inScore(int useBoundary = 0) {
    int score;
    if (useBoundary <= 0) {
        cout << "Masukkan nilai mahasiswa -> ";
    }
    else {
        cout << "Masukkan batas ke-" << useBoundary << " -> ";
    }
    cin >> score;
    return score;
}

string line = "=======================";

int main() {
    HashTable hashTable;
    int choice;
    bool run = true;

    while(run) {
        cout << line << "[ Data Mahasiswa ]" << line << endl;
        hashTable.print();
        cout << line << "[ Menu ]" << line << endl;
        cout << "1. Tambah mahasiswa\n";
        cout << "2. Hapus mahasiswa\n";
        cout << "3. Cari mahasiswa dengan NIM\n";
        cout << "4. Cari mahasiswa dengan nilai\n";
        cout << "0. Keluar";
        cout << "\nMasukkan pilihan -> ";
        cin >> choice;

        switch(choice) {
            case 0: return 0; break;
            case 1: {
                string NIM = inNIM();
                int score = inScore();
                hashTable.insert(NIM, score);
                break;
            }
            case 2: {
                string NIM = inNIM();
                hashTable.remove(NIM);
                break;
            }
            case 3: {
                string NIM = inNIM();
                int score = hashTable.searchByNIM(NIM);
                cout << "\nMahasiswa dengan NIM " << NIM << " memiliki nilai " << score << endl;
                break;
            }
            case 4: {
                int scores[] = {inScore(1), inScore(2)};
                hashTable.searchByScore(scores);
                break;
            }
            default: cout << "Mohon masukkan pilihan yang benar\n";
        }
    }
    return 0;
}