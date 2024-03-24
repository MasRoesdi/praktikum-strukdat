#include <iostream> // memanggil library iostream, input output
#include <map> // memanggil library map untuk menggunakan fitur map
#include <string> // memanggil library string supaya dapat menggunakan tipe data string

using namespace std; // set default library ke std

// program dimulai dari sini
int main() {
    // deklarasi map baru dengan key berupa string dan value berupa string
    // key disini bisa diibaratkan sebagai index dalam array
    // layaknya index, setiap nilai key harus unik, beda dari key lain
    map<string, string> companies;

    // input value ke map
    companies["AAPL"] = "Apple"; // memasukkan value Apple dengan key AAPL 
    companies["MSFT"] = "Microsoft"; // memasukkan value microsoft dengan key MSFT
    companies["NVDA"] = "NVIDIA"; // memasukkan value NVIDIA dengan key NVDA

    // output map value ke console
    cout << companies["AAPL"] << endl; // menampilkan value map dengan key AAPL
    cout << companies["MSFT"] << endl; // menampilkan value map dengan key MSFT
    cout << companies["NVDA"] << endl; // menampilkan value map dengan key NVDA

    return 0; // memberhentikan program   
}