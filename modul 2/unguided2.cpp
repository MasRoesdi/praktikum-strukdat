#include <iostream>

using namespace std;

int main() {
    int arrSize[3];
    cout << "Masukkan ukuran array 3 dimensi: ";
    for (int i = 0; i < 3; i++) {
        cin >> arrSize[i];
    }
    int arr[arrSize[0]][arrSize[1]][arrSize[2]];
    for (int x = 0; x < arrSize[0]; x++)
  {
    for (int y = 0; y < arrSize[1]; y++)
    {
      for (int z = 0; z < arrSize[2]; z++)
      {
        cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
        cin >> arr[x][y][z];
      }
    }
    cout << endl;
  }
  // Output Array
  for (int x = 0; x < arrSize[0]; x++)
  {
    for (int y = 0; y < arrSize[1]; y++)
    {
      for (int z = 0; z < arrSize[2]; z++)
      {
        cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
      }
    }
  }
  cout << endl;
  // Tampilan array
  for (int x = 0; x < arrSize[0]; x++)
  {
    for (int y = 0; y < arrSize[1]; y++)
    {
      for (int z = 0; z < arrSize[2]; z++)
      {
        cout << arr[x][y][z] << ends;
      }
      cout << endl;
    }
    cout << endl;
  }
}