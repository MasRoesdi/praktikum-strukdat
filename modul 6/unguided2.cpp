#include <iostream>
#include <sstream>

using namespace std;

bool hasThreeWords(string sentence) {
    stringstream stream(sentence);
    string temp;
    int count = 0;
    while (stream >> temp) count++;
    if (count >= 3) return true;
    else return false;
}

string reverse(string sentence) {
    string temp;
    int length = sentence.length();
    for (int i = length; i > 0; i--) temp += sentence[i - 1];
    return temp;
}

int main() {
    string sentence;

    cout << "Masukkan kalimat [Min. 3 kata] : ";
    getline(cin, sentence);

    if (sentence.length() == 0) {
        cout << "Kalimat masih kosong.";
        return 0;
    }
    else if (hasThreeWords(sentence)) {
        cout << "Kalimat kurang dari 3 kata";
        return 0;
    }

    string reversed = reverse(sentence);
    cout << "Hasil : " << reversed << endl;

    return 0;
}