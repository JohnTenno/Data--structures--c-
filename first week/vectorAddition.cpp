//p2 31 01 24
#include <iostream>

int sumatoryVector(int vectorA[], int number);
void print(int vectorA[], int number);

using namespace std;

int number = 0;
int sumatory = 0;
int vectorA[20];

int main() {
    do {
        cout << "Ingrese un numero del 1 al 20" << endl;
        cin >> number;
        if (number <= 0 or number > 20) {
          continue;
        }
            break;
    } while (true);

    for (int i = 0; i < number; i++) {
        cout << "Dame el numero" << endl;
        cin >> vectorA[i];
    }

    sumatory = sumatoryVector(vectorA, number);
    cout << "La suma es: " << sumatory << endl;

    print(vectorA, number);

    return 0;
}

int sumatoryVector(int vectorA[], int number) {
    for (int i = 0; i < number; i++) {
        sumatory = vectorA[i] + sumatory;
    }
    return sumatory;
}

void print(int vectorA[], int number) {
    cout << "\n\nLos numeros son:" << endl;
    for (int i = 0; i < number; i++) {
        cout << "->" << vectorA[i] << endl;
    }
}