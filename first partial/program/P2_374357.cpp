#include <iostream>

using namespace std;

typedef struct Estudiante
{
  long int matricula;
  string nombre;
  float promedio;
  struct Estudiante *siguiente;
} Nodo;

struct EstudiantesLista
{
  Estudiante *cabeza;
  EstudiantesLista() : cabeza(nullptr) {}
};

void printMenu();
void addData(EstudiantesLista &list, Estudiante newEstudiante);
void deleteData(EstudiantesLista &list, int matricula);
void showData(EstudiantesLista &list);

int main()
{
  printMenu();
  return 0;
}

void printMenu()
{
  EstudiantesLista Lista;
  Estudiante estudiante;
  char option;
  bool exit = false;
  long int matricula;
  string nombre;
  float promedio;
  do
  {
    cout << "Menu" << endl;
    cout << "Selecionar una de las opciones correspondientes" << endl;
    cout << "a.- Agregar" << endl;
    cout << "b.- Eliminar" << endl;
    cout << "c.- Mostrar Lista" << endl;
    cout << "d.- Malir" << endl;

    cin >> option;
    // si funciona no es tonto :3
    if (option == 'A')
    {
      option = 'a';
    }
    if (option == 'B')
    {
      option = 'b';
    }
    if (option == 'C')
    {
      option = 'c';
    }

    switch (option)
    {
    case 'a':
      cout << "Ingrese nombre del estudiante: ";
      cin >> nombre;
      cout << "Ingrese la matricula del estudiante: ";
      cin >> matricula;
      cout << "Ingrese el promedio del estudiante: ";
      cin >> promedio;
      estudiante = {matricula, nombre, promedio, nullptr};
      addData(Lista, estudiante);
      break;
    case 'b':
      cout << "Cual es la matricula a eliminar?" << endl;
      cin >> matricula;
      deleteData(Lista, matricula);
      break;
    case 'c':
      showData(Lista);
      break;
    case 'd':
      exit = true;
      break;

    default:
      for (int i = 0; i < 4; i++)
      {
        cout << endl;
      }
      // no recorde como se hace el sistem clear :p
      cout << "Ingrese una opcion valida" << endl;
      break;
    }
  } while (exit == false);
}

void addData(EstudiantesLista &list, Estudiante newEstudiante)
{
  // if (list.cabeza == nullptr)
  // {
  cout << "La list de Estudiantees está vacía." << endl;
  Estudiante *NuevoNodo = new Estudiante;
  *NuevoNodo = newEstudiante;

  NuevoNodo->siguiente = list.cabeza;
  list.cabeza = NuevoNodo;

  // se me ciclo y ahi quede

  // }
  // else
  // {
  //   Estudiante *temp = list.cabeza;
  //   while (temp != nullptr)
  //   {
  //     if (temp->matricula < newEstudiante.matricula)
  //     {
  //       temp->siguiente = list.cabeza;
  //       list.cabeza = temp;
  //       break;
  //     }
  //   }
  // }
}

void deleteData(EstudiantesLista &list, int matricula)
{
  if (list.cabeza == nullptr)
  {
    cout << "La list de Estudiantees está vacía." << endl;
  }
  else
  {
    Estudiante *temp = list.cabeza;

    while (temp != nullptr)
    {
      if (temp->matricula == matricula)
      {
        delete temp;
        break;
      }
    }
  }
}

void showData(EstudiantesLista &list)
{
  Estudiante *temp = list.cabeza;
  while (temp != nullptr)
  {
    cout << "Nombre: " << temp->nombre << ", matricula: " << temp->matricula << ", promedio: " << temp->promedio << endl;
    temp = temp->siguiente;
  }
}

// no me dio el tiempo :3