#include <iostream>

using namespace std;

int main()
{
  int numbers[2][2] = {{1, 2}, {3, 4}};
  int getNumbers[2][2];

  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      getNumbers[i][j] = numbers[i][j];
    }
  }

  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      cout << "[" << getNumbers[i][j] << "]";
    }
    cout << endl;
  }
}