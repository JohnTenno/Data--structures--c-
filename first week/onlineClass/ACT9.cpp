#include <iostream>

using namespace std;

int main()
{
	int numbers[100][100];
	int size;
	int rows;
	int columns;

	cout << "Digite el tamanio de la fila" << endl;
	cin >> rows;
	cout << "Digite el tamanio de la columna" << endl;
	cin >> columns;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << "Ingrese un numero" << endl;
			cin >> numbers[i][j];
		}
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << i << "," << j << "-->" << numbers[i][j] << endl;
		}
	}
}