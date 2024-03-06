#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

int main()
{
  char numberAsCaracter[20];
  char secondNumberAsCaracter[20];
  int numberAsNumber;
  float secondNumberAsNumber;

  cout << "digite un numero" << endl;
  cin >> numberAsCaracter;
  cout << "digite un numero con decimales" << endl;
  cin >> secondNumberAsCaracter;

  numberAsNumber = atoi(numberAsCaracter);
  secondNumberAsNumber = atof(secondNumberAsCaracter);

  cout << "la suma es " << numberAsNumber + secondNumberAsNumber << endl;
}