#include <iostream>
using namespace std;
void setNumbers();
void getNumbers();
int numbers[100], sizeOfNumbers;

int main()
{
  setNumbers();
  getNumbers();
}

void setNumbers()
{
  cout << "Ingrese el tamanio del arreglo" << endl;
  cin >> sizeOfNumbers;
  for (int i = 0; i < sizeOfNumbers; i++)
  {
    cout << "Digite un numero" << endl;
    cin >> numbers[i];
  }
}

void getNumbers()
{
  for (int i = sizeOfNumbers - 1; i >= 0; i--)
  {
    cout << i << "-->" << numbers[i] << endl;
  }
}
