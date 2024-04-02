#include <iostream>
#include <iomanip>
using namespace std;

class Node {
public:
    string name;
    int price;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push(string name, int price) {
        Node* newNode = new Node;
        newNode->name = name;
        newNode->price = price;
        newNode->prev = nullptr;
        newNode->next = head;
        
        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        
        head = newNode;
    }

    void pushAt(string name, int price, int index) {
        Node* newNode = new Node;
        newNode->name = name;
        newNode->price = price;

        if (head != nullptr) {
            Node* current = head;
            int i;
            while (current != nullptr && i < index) {
                current = current->prev;
                i++;
            }
            newNode->prev = current;
            newNode->next = current->next;
            current->next->prev = newNode; 
        } else {
            push(name, price);
        }
    }

    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        
        delete temp;
    }

    void popAt(int index) {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;

        int i;
        while (temp->next != nullptr && i < index) {
            temp = temp->prev;
        }

        temp->prev->prev = temp->prev->prev
        
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            return;
        }
        
        delete temp;
    }

    bool update(string oldName, string newName, int oldprice, int newprice) {
        Node* current = head;
        
        while (current != nullptr) {
            if (current->price == oldprice && current->name == oldName) {
                current->name = newName;
                current->price = newprice;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    void display() {
        string line = string(25, '=');
        Node* current = head;
        cout << line << endl;
        cout << "| Nama Produk " << setw(16) << left << "| Harga " << setw(8) << left << "|" << endl;
        cout << line << endl;
        while (current != nullptr) {
            cout << "| " << current->name << setw(16) << left << current->price << setw(8) << left << "|" << endl;  
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    string indent = string(3, ' ');
    string name, nameNew;
    int price, priceNew, index;
    while (true) {
        cout << "Toko Skincare Purwokerto" << endl;
        cout << indent << "1. Tambah data" << endl;
        cout << indent << "2. Hapus data" << endl;
        cout << indent << "3. Update data" << endl;
        cout << indent << "4. Tambah data urutan tertentu" << endl;
        cout << indent << "5. Hapus data urutan tertentu" << endl;
        cout << indent << "6. Hapus semua data" << endl;
        cout << indent << "7. Tampilkan data" << endl;
        cout << indent << "8. Exit" << endl;
        
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                cout << "Masukkan nama produk : ";
                cin >> name;
                cout << "Masukkan harga produk : ";
                cin >> price;
                list.push(name, price);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                cout << "Masukkan nama produk lama : ";
                cin >> name;
                cout << "Masukkan harga produk lama : ";
                cin >> price;
                cout << "Masukkan nama produk baru : ";
                cin >> nameNew;
                cout << "Masukkan harga produk baru : ";
                cin >> priceNew;
                bool updated = list.update(name, nameNew, price, priceNew);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                cout << "Masukkan nama produk : ";
                cin >> name;
                cout << "Masukkan harga produk : ";
                cin >> price;
                cout << "Masukkan index produk : ";
                cin >> index;
                list.pushAt(name, price, index);
                break;
            }
            case 5: {

                break;
            }
            case 6: {
                list.deleteAll();
                break;
            }
            case 7: {
                list.display();
                break;
            }
            case 8: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}