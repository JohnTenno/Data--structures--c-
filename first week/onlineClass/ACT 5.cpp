#include <iostream>

using namespace std;

int vectorTotal = 1;
int vectorOfNumbers[5] = {1, 2, 3, 4, 5};

int main()
{
  for (int i = 0; i < 5; i++)
  {
    vectorTotal *= vectorOfNumbers[i];
  }
  cout << "la multiplicacion de los elementos del vector es: " << vectorTotal << endl;
}