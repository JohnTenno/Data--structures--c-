#include <iostream>

using namespace std;

int vectorOfNumbers[100];
int count;
int higherNumber;

int main()
{
  cout << "Digite el numero de los elementos del arreglo:" << endl;
  cin >> count;

  for (int i = 0; i < count; i++)
  {
    cout << i + 1 << ". Digite un numero:" << endl;
    cin >> vectorOfNumbers[i];

    if (vectorOfNumbers[i] > higherNumber)
    {
      higherNumber = vectorOfNumbers[i];
    }
  }
  cout << "\n el numero mayor es:" << higherNumber << endl;
}