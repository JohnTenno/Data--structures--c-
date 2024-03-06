#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

int main()
{
  char word[20];
  char secondWord[20];
  cout << "ingrese la primer palabra" << endl;
  cin >> word;
  cout << "ingrese la segunda palabra" << endl;
  cin >> secondWord;

  if (strcmp(word, secondWord) == 0)
  {
    cout << "las cadenas son iguales" << endl;
  }
  else
  {
    if (strcmp(word, secondWord) < 0)
    {
      cout << word << " va primero" << endl;
    }
    else
    {
      cout << word << " va despues" << endl;
    }
  }
}