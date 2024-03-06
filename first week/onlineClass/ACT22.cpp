#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

int main()
{
  char words[30];
  int vocalA = 0;
  int vocalE = 0;
  int vocalI = 0;
  int vocalO = 0;
  int vocalU = 0;
  int total = 0;

  cout << "ingrese su frase" << endl;
  cin.getline(words, 30);

  for (int i = 0; i < 30; i++)
  {
    switch (words[i])
    {
    case 'a':
      vocalA++;
      break;
    case 'e':
      vocalE++;
      break;
    case 'i':
      vocalI++;
      break;
    case 'o':
      vocalO++;
      break;
    case 'u':
      vocalU++;
      break;
    }
  }
  total = vocalA + vocalE + vocalI + vocalO + vocalU;
  cout << "en numero de vocales es " << total << endl;

  cout << "A " << vocalA << endl;
  cout << "E " << vocalE << endl;
  cout << "I " << vocalI << endl;
  cout << "O " << vocalO << endl;
  cout << "U " << vocalU << endl;
}