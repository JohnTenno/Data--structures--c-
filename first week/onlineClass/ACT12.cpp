#include <iostream>

using namespace std;

int main()
{
  int numbers[100][100];
  int rows;
  int columns;

  bool simetric = false;

  cout << "Digite el numero de filas: ";
  cin >> rows;
  cout << "Digite el numero de columnas: ";
  cin >> columns;

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      cout << "capture un numero" << endl;
      cin >> numbers[i][j];
    }
  }

  if (rows == columns)
  {
    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < columns; j++)
      {
        if (numbers[i][j] == numbers[j][i])
        {
          simetric = true;
        }
      }
    }
  }

  if (simetric)
  {
    cout << "La matriz es simetrica" << endl;
  }
  else
  {
    cout << "La matriz no es simetrica" << endl;
  }
}