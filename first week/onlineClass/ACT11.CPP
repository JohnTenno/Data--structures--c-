#include <iostream>

using namespace std;

int main()
{
  int numbers[3][3];

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cout << "Digite un numero en la posicion: " << i << " " << j << endl;
      cin >> numbers[i][j];
    }
  }

  cout << "Matriz inicial" << endl;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cout << numbers[i][j];
    }
    cout << endl;
  }

  cout << "Matriz transpuesta" << endl;

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cout << numbers[j][i];
    }
    cout << endl;
  }
}