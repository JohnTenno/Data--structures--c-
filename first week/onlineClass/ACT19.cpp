#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

int main()
{
  char word[] = "palabra";
  char secondWord[] = "sgunda palabra";
  strupr(word);
  strupr(secondWord);
  if (strcmp(word, secondWord) == 0)
  {
    cout << "las palabras son iguales" << endl;
  }
  else
  {
    cout << "las palabras son diferentes" << endl;
  }
}