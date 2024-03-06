#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

int main()
{
  char main[] = "hola que tal ";
  char msg[] = "Ingrese el nombre del usuario";
  char user[20];

  cout << msg << endl;
  cin >> user;

  strcat(main, user);

  cout << main;
}