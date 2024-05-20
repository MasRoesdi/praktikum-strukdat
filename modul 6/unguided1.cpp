#include <iostream>

using namespace std;

string reverse(string sentence) {
    string temp;
    int length = sentence.length();
    for (int i = length; i > 0; i--) temp += sentence[i - 1];
    return temp;
}

int main() {
    string sentence;

    cout << "Masukkan kalimat : ";
    getline(cin, sentence);

    if (sentence.length() == 0) {
        cout << "Kalimat masih kosong.";
        return 0;
    }

    string reversed = reverse(sentence);

    if (reversed == sentence) {
        cout << "Kalimat tersebut adalah palindrom\n";
    }
    else {
        cout << "Kalimat tersebut bukan palindrom\n";
    }

    return 0;
}