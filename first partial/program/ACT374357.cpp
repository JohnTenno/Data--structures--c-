// INTRODUCCIÓN A LAS ESTRUCTURAS DE DATOS
// Actividad integradora
// Segundo parcial
// 1. Escribir en lenguaje C/C++, que permita gestionar una list simple enlazada de estructuras
// de datos que permita la administración de Clients frecuentes de “Al Super”.
// La estructura almacenará los siguientes campos:
// • Nombre del Client.
// • Puntos obtenidos.
// • Teléfono
// • Puntero al siguiente elemento de la list.
// El módulo deberá definir las siguientes operaciones sobre los elementos de la list:
// ✓ Inicializar: Inicializa la list, teniendo en cuenta que la list comienza sin ningún elemento.
// ✓ Añadir al inicio: Añade un nuevo elemento al principio de la list.
// ✓ Añadir al final: Añade un nuevo elemento al final de la list.
// ✓ Editar Datos del Client. De acuerdo al teléfono del Client, modificar datos.
// ✓ Pop Cola: Elimina el primer elemento de la list.
// ✓ Pop Pila: Elimina el último elemento de la list.
// ✓ Buscar winner: Recorre la list buscando el “Client” con más puntos y muestra el
// Nombre.
// ✓ Mostrar datos: Mostrar todos los Clients, con sus respectivos datos.
// 2. Considera lo mismo que en el punto 1, pero la representación debe ser una list enlazada
// Simple Circular.
// 3. Desarrolle en Lenguaje C/C++, donde solicite una expresión infija y convierta esta
// expresión a notación prefija y postfija. Además de mostrar el resultado de la expresión.
// Ejemplo.
// Notación Infija: ( 5 * 2 ) / 2
// Notación Prefija: / * 5 2 2
// Notación Postfija: 5 2 * 2 /
// Resultado: 5
// No olvide utilizar Estructuras de datos y pilas

#include <iostream>
#include <string>
using namespace std;

struct Client
{
  string name;
  int points;
  string phone;
  Client *next;
};

struct ClientList
{
  Client *head;
  ClientList() : head(nullptr) {}
};

void addAtStart(ClientList &list, Client newClient)
{
  Client *newNode = new Client;
  *newNode = newClient;
  newNode->next = list.head;
  list.head = newNode;
}

void addAtEnd(ClientList &list, Client newClient)
{
  Client *newNode = new Client;
  *newNode = newClient;
  newNode->next = nullptr;

  if (list.head == nullptr)
  {
    list.head = newNode;
  }
  else
  {
    Client *temp = list.head;
    while (temp->next != nullptr)
    {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

void edithData(ClientList &list, string phone, string newName, int newPoints, string newPhone)
{
  Client *temp = list.head;
  while (temp != nullptr)
  {
    if (temp->phone == phone)
    {
      temp->name = newName;
      temp->points = newPoints;
      temp->phone = newPhone;
      break;
    }
    temp = temp->next;
  }
}

void popCola(ClientList &list)
{
  if (list.head != nullptr)
  {
    Client *temp = list.head;
    list.head = list.head->next;
    delete temp;
  }
}

void popPila(ClientList &list)
{
  if (list.head != nullptr)
  {
    if (list.head->next == nullptr)
    {
      delete list.head;
      list.head = nullptr;
    }
    else
    {
      Client *temp = list.head;
      while (temp->next->next != nullptr)
      {
        temp = temp->next;
      }
      delete temp->next;
      temp->next = nullptr;
    }
  }
}

void searchWinner(ClientList &list)
{
  if (list.head == nullptr)
  {
    cout << "La list de clientes está vacía." << endl;
  }
  else
  {
    Client *temp = list.head;
    Client *winner = list.head;
    int maxPoints = list.head->points;

    while (temp != nullptr)
    {
      if (temp->points > maxPoints)
      {
        maxPoints = temp->points;
        winner = temp;
      }
      temp = temp->next;
    }

    cout << "El cliente winner con más puntos es: " << winner->name << endl;
  }
}

void showData(ClientList &list)
{
  Client *temp = list.head;
  while (temp != nullptr)
  {
    cout << "Nombre: " << temp->name << ", Puntos: " << temp->points << ", Teléfono: " << temp->phone << endl;
    temp = temp->next;
  }
}

int main()
{
  ClientList list;

  int opcion;
  do
  {
    cout << "\nMENU DE OPERACIONES:" << endl;
    cout << "1. Agregar Cliente al Inicio" << endl;
    cout << "2. Agregar Cliente al Final" << endl;
    cout << "3. Editar Datos de Cliente" << endl;
    cout << "4. Eliminar Primer Cliente (Pop Cola)" << endl;
    cout << "5. Eliminar Último Cliente (Pop Pila)" << endl;
    cout << "6. Buscar winner" << endl;
    cout << "7. Mostrar Datos de Clientes" << endl;
    cout << "0. Salir" << endl;
    cout << "Seleccione una opción: ";
    cin >> opcion;

    switch (opcion)
    {
    case 1:
      // Agregar Cliente al Inicio
      {
        string name, phone;
        int points;
        cout << "Ingrese nombre del cliente: ";
        cin >> name;
        cout << "Ingrese puntos del cliente: ";
        cin >> points;
        cout << "Ingrese teléfono del cliente: ";
        cin >> phone;
        Client newClient = {name, points, phone, nullptr};
        addAtStart(list, newClient);
        break;
      }
    case 2:
      // Agregar Cliente al Final
      {
        string name, phone;
        int points;
        cout << "Ingrese nombre del cliente: ";
        cin >> name;
        cout << "Ingrese puntos del cliente: ";
        cin >> points;
        cout << "Ingrese teléfono del cliente: ";
        cin >> phone;
        Client newClient = {name, points, phone, nullptr};
        addAtEnd(list, newClient);
        break;
      }
    case 3:
      // Editar Datos de Cliente
      {
        string phone, newName, newPhone;
        int newPoints;
        cout << "Ingrese teléfono del cliente a editar: ";
        cin >> phone;
        cout << "Ingrese nuevo nombre del cliente: ";
        cin >> newName;
        cout << "Ingrese nuevos puntos del cliente: ";
        cin >> newPoints;
        cout << "Ingrese nuevo teléfono del cliente: ";
        cin >> newPhone;
        edithData(list, phone, newName, newPoints, newPhone);
        break;
      }
    case 4:
      // Eliminar Primer Cliente (Pop Cola)
      popCola(list);
      break;
    case 5:
      // Eliminar Último Cliente (Pop Pila)
      popPila(list);
      break;
    case 6:
      // Buscar winner
      searchWinner(list);
      break;
    case 7:
      // Mostrar Datos de Clientes
      showData(list);
      break;
    case 0:
      cout << "Saliendo del programa." << endl;
      break;
    default:
      cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
    }
  } while (opcion != 0);

  return 0;
}
