#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

int main()
{
  char name[] = "jonathan";
  char nameCopy[20];

  strcpy(nameCopy, name);

  cout << nameCopy << endl;
}