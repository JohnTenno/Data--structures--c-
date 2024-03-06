#include <iostream>

using namespace std;

int main()
{
  char lettersArray[] = {'a', 'b', 'c', 'd', 'e'};
  char anotherLettersArray[] = {'f', 'g', 'h', 'i', 'j'};
  char lettersArrayCopy[10];

  for (int i = 0; i < 10; i++)
  {
    if (i < 5)
    {
      lettersArrayCopy[i] = lettersArray[i];
    }
    else
    {
      lettersArrayCopy[i] = anotherLettersArray[i - 5];
    }
  }

  for (int i = 0; i < 10; i++)
  {
    cout << lettersArrayCopy[i] << endl;
  }
}