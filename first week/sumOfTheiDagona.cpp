#include <iostream>

using namespace std;

int matrix[10][10];
int sizeOfMatrix = 0;
int sumatory = 0;

void recordData();
void printMatrix(int matrix[10][10],int sizeOfMatrix);
void sumatoryMatrixDiagonal(int matrix[10][10], int sizeOfMatrix);

int main () {
  do
  {
    cout << "ingrese el tama;o de la matris (maximo 10, minimo 1)" << endl;
    cin >> sizeOfMatrix;
    if (sizeOfMatrix < 0 or sizeOfMatrix > 11)
    {
      cout << "Rango de valores incorrecto" << endl;
      continue;
    }
    break;
  } while (true);
  recordData();
  printMatrix(matrix, sizeOfMatrix);
  sumatoryMatrixDiagonal(matrix, sizeOfMatrix);
}

void recordData () {
  cout << "Ingrese los digitos de la matris" << endl;
  for (int y = 0; y < sizeOfMatrix; y++)
  {
    for (int x = 0; x < sizeOfMatrix; x++)
    {
      cin >> matrix[x][y];
    }
  }
}

void printMatrix(int matrix[10][10],int sizeOfMatrix) {
  for (int y = 0; y < sizeOfMatrix; y++)
  {
    for (int x = 0; x < sizeOfMatrix; x++)
    {
      cout << matrix[x][y];
    }
    cout << endl;
  }
}

void sumatoryMatrixDiagonal(int matrix[10][10], int sizeOfMatrix) {
  cout << "suma de la diagonal" << endl;
  for (int i = 0; i < sizeOfMatrix; i++)
  {
    sumatory = matrix[i][i] + sumatory; 
  } 
  cout << sumatory << endl;
} 