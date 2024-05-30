#include <iostream>
using namespace std;

int arr[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
int arrLength = sizeof(arr)/sizeof(arr[0]);
int cari;

int seqSearch() {
    int count = 0;
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == cari)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    // algoritma Sequential Search

    cout << "\t Program Sequential Search Sederhana\n" << endl;
    cout << "Data array : ";
    for (int x : arr) {
        cout << x << ", ";
    }
    cout << "\n\nMasukkan angka yang akan cari : ";
    cin >> cari;

    cout << "\nTerdapat " << seqSearch() << " angka " << cari << " di dalam data.";
    return 0;
}