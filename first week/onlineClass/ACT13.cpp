#include <iostream>

using namespace std;

int main()
{
  char character[] = "raw";
  char characters[] = {'r', 'a', 'w'};
  char name[30];

  cout << "digite su nombre" << endl;
  cin.getline(name, 30);
  cout << name << endl;
}