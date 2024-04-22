#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

typedef struct
{
  string name;
  int number;
  string summary;
  float price;
  int amount;
} Product;

void show(Product product, Product anotherProduct);
int main()
{
  Product product, anotherProduct;
  cout << "Ingrese nombre: " << endl;
  fflush(stdin);
  getline(cin, product.name);
  cout << "Ingrese el numero del producto: " << endl;
  cin >> product.number;
  cout << "Ingrese la descripcion de el producto: " << endl;
  fflush(stdin);
  getline(cin, product.summary);
  cout << "Ingrese el precio del precio: " << endl;
  cin >> product.price;
  cout << "Ingrese la cantidad de el prodcuto: " << endl;
  cin >> product.amount;

  cout << "Ingrese nombre del otro producto: " << endl;
  fflush(stdin);
  getline(cin, anotherProduct.name);
  cout << "Ingrese el numero del producto del otro producto: " << endl;
  cin >> anotherProduct.number;
  cout << "Ingrese la descripcion de el producto del otro producto: " << endl;
  fflush(stdin);
  getline(cin, anotherProduct.summary);
  cout << "Ingrese el precio del precio del otro producto: " << endl;
  cin >> anotherProduct.price;
  cout << "Ingrese la cantidad de el prodcuto del otro producto: " << endl;
  cin >> anotherProduct.amount;
  show(product, anotherProduct);
}

void show(Product product, Product anotherProduct)
{
  cout << "Nombre del producto " << product.name << endl;
  cout << "Numero del producto " << product.number << endl;
  cout << "Descripcion del producto " << product.summary << endl;
  cout << "Precio del producto " << product.price << endl;
  cout << "Cantidad del producto " << product.amount << endl;

  cout << "===========================" << endl;
  cout << endl;
  cout << "===========================" << endl;

  cout << "Nombre del producto " << anotherProduct.name << endl;
  cout << "Numero del producto " << anotherProduct.number << endl;
  cout << "Descripcion del producto " << anotherProduct.summary << endl;
  cout << "Precio del producto " << anotherProduct.price << endl;
  cout << "Cantidad del producto " << anotherProduct.amount << endl;
}