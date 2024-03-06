#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

int main()
{
  char words[20];
  char revwords[20];

  cout << "ingrese una palabra" << endl;
  cin >> words;
  strcpy(revwords, words);
  strrev(revwords);

  if (strcmp(words, revwords) == 0)
  {
    cout << "la palabra es polindroma" << endl;
  }
}