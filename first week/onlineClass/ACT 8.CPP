#include <iostream>

using namespace std;

int numbers[100][100];
int main()
{
	int size;
	cout << "Digite el tamanio del arreglo" << endl;
	cin >> size;
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