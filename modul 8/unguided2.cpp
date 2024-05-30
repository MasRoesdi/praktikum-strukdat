#include <iostream>
using namespace std;
int main()
{
    string s;
    int count = 0;
    
    cout << "\t HITUNG HURUF VOKAL" << endl;
    cout << "\nMasukkan kalimat : ";
    getline(cin, s);
    
    for (int i = 0; i < s.length(); i++) {
        char c = tolower(s[i]);
        if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') count++;
    }

    cout << "\nKalimat yang dimasukkan memiliki " << count << " huruf vokal.";
    return 0;
}