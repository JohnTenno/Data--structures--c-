#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <unordered_set>
#include <stack>

using namespace std;

struct nodo
{
  char nombre; // nombre del vertice o nodo
  struct nodo *sgte;
  struct arista *ady; // puntero hacia la primera arista del nodo
};

struct arista
{
  struct nodo *destino; // puntero al nodo de llegada
  struct arista *sgte;
};

typedef struct nodo *Tnodo;     // Tipo Nodo
typedef struct arista *Tarista; // Tipo Arista

Tnodo p = NULL; // puntero cabeza

void menu();
void insertar_nodo();
void agrega_arista(Tnodo &, Tnodo &, Tarista &);
void insertar_arista();
void vaciar_aristas(Tnodo &);
void eliminar_nodo();
void eliminar_arista();
void mostrar_grafo();
void mostrar_aristas();
void BFS();
void DFS();
void BFSUtil(Tnodo start);
void DFSUtil(Tnodo start);

int main()
{
  int op; // opción del menú

  system("color 0b");

  do
  {
    menu();
    cin >> op;

    switch (op)
    {
    case 1:
      insertar_nodo();
      break;
    case 2:
      insertar_arista();
      break;
    case 3:
      eliminar_nodo();
      break;
    case 4:
      eliminar_arista();
      break;
    case 5:
      mostrar_grafo();
      break;
    case 6:
      mostrar_aristas();
      break;
    case 7:
      BFS();
      break;
    case 8:
      DFS();
      break;
    case 9:
      break;

    default:
      cout << "OPCION NO VALIDA...!!!" << endl;
      break;
    }

    cout << endl;
    system("pause");
    system("cls");

  } while (op != 9);

  return 0;
}

void menu()
{
  cout << "\n\tREPRESENTACION DE GRAFOS DIRIGIDOS\n\n";
  cout << " 1. INSERTAR UN NODO" << endl;
  cout << " 2. INSERTAR UNA ARISTA" << endl;
  cout << " 3. ELIMINAR UN NODO" << endl;
  cout << " 4. ELIMINAR UNA ARISTA" << endl;
  cout << " 5. MOSTRAR GRAFO" << endl;
  cout << " 6. MOSTRAR ARISTAS DE UN NODO" << endl;
  cout << " 7. RECORRIDO EN AMPLITUD (BFS)" << endl;
  cout << " 8. RECORRIDO EN PROFUNDIDAD (DFS)" << endl;
  cout << " 9. SALIR" << endl;

  cout << "\n INGRESE OPCION: ";
}

void insertar_nodo()
{
  Tnodo t, nuevo = new struct nodo;
  cout << "INGRESE VARIABLE: ";
  cin >> nuevo->nombre;
  nuevo->sgte = NULL;
  nuevo->ady = NULL;

  if (p == NULL)
  {
    p = nuevo;
    cout << "PRIMER NODO...!!!" << endl;
  }
  else
  {
    t = p;
    while (t->sgte != NULL)
    {
      t = t->sgte;
    }
    t->sgte = nuevo;
    cout << "NODO INGRESADO...!!!" << endl;
  }
}

void agrega_arista(Tnodo &aux, Tnodo &aux2, Tarista &nuevo)
{
  Tarista q;
  if (aux->ady == NULL)
  {
    aux->ady = nuevo;
    nuevo->destino = aux2;
    cout << "PRIMERA ARISTA....!" << endl;
  }
  else
  {
    q = aux->ady;
    while (q->sgte != NULL)
    {
      q = q->sgte;
    }
    nuevo->destino = aux2;
    q->sgte = nuevo;
    cout << "ARISTA AGREGADA...!!!!" << endl;
  }
}

void insertar_arista()
{
  char ini, fin;
  Tarista nuevo = new struct arista;
  Tnodo aux, aux2;

  if (p == NULL)
  {
    cout << "GRAFO VACIO...!!!!" << endl;
    return;
  }
  nuevo->sgte = NULL;
  cout << "INGRESE NODO DE INICIO: ";
  cin >> ini;
  cout << "INGRESE NODO FINAL: ";
  cin >> fin;
  aux = p;
  aux2 = p;
  while (aux2 != NULL)
  {
    if (aux2->nombre == fin)
    {
      break;
    }
    aux2 = aux2->sgte;
  }
  while (aux != NULL)
  {
    if (aux->nombre == ini)
    {
      agrega_arista(aux, aux2, nuevo);
      return;
    }
    aux = aux->sgte;
  }
}

void vaciar_aristas(Tnodo &aux)
{
  Tarista q, r;
  q = aux->ady;
  while (q->sgte != NULL)
  {
    r = q;
    q = q->sgte;
    delete (r);
  }
}

void eliminar_nodo()
{
  char var;
  Tnodo aux, ant;
  aux = p;
  cout << "ELIMINAR UN NODO" << endl;
  if (p == NULL)
  {
    cout << "GRAFO VACIO...!!!!" << endl;
    return;
  }
  cout << "INGRESE NOMBRE DE VARIABLE: ";
  cin >> var;

  while (aux != NULL)
  {
    if (aux->nombre == var)
    {
      if (aux->ady != NULL)
        vaciar_aristas(aux);

      if (aux == p)
      {
        p = p->sgte;
        delete (aux);
        cout << "NODO ELIMINADO...!!!!" << endl;
        return;
      }
      else
      {
        ant->sgte = aux->sgte;
        delete (aux);
        cout << "NODO ELIMINADO...!!!!" << endl;
        return;
      }
    }
    else
    {
      ant = aux;
      aux = aux->sgte;
    }
  }
}

void eliminar_arista()
{
  char ini, fin;
  Tnodo aux, aux2;
  Tarista q, r;
  cout << "\n ELIMINAR ARISTA" << endl;
  cout << "INGRESE NODO DE INICIO: ";
  cin >> ini;
  cout << "INGRESE NODO FINAL: ";
  cin >> fin;
  aux = p;
  aux2 = p;
  while (aux2 != NULL)
  {
    if (aux2->nombre == fin)
    {
      break;
    }
    else
      aux2 = aux2->sgte;
  }
  while (aux != NULL)
  {
    if (aux->nombre == ini)
    {
      q = aux->ady;
      while (q != NULL)
      {
        if (q->destino == aux2)
        {
          if (q == aux->ady)
            aux->ady = aux->ady->sgte;
          else
            r->sgte = q->sgte;
          delete (q);
          cout << "ARISTA  " << aux->nombre << "----->" << aux2->nombre << " ELIMINADA.....!!!!" << endl;
          return;
        }
        r = q;
        q = q->sgte;
      }
    }
    aux = aux->sgte;
  }
}

void mostrar_grafo()
{
  Tnodo ptr;
  Tarista ar;
  ptr = p;
  cout << "NODO|LISTA DE ADYACENCIA" << endl;

  while (ptr != NULL)
  {
    cout << "   " << ptr->nombre << "|";
    if (ptr->ady != NULL)
    {
      ar = ptr->ady;
      while (ar != NULL)
      {
        cout << " " << ar->destino->nombre;
        ar = ar->sgte;
      }
    }
    ptr = ptr->sgte;
    cout << endl;
  }
}

void mostrar_aristas()
{
  Tnodo aux;
  Tarista ar;
  char var;
  cout << "MOSTRAR ARISTAS DE NODO" << endl;
  cout << "INGRESE NODO: ";
  cin >> var;
  aux = p;
  while (aux != NULL)
  {
    if (aux->nombre == var)
    {
      if (aux->ady == NULL)
      {
        cout << "EL NODO NO TIENE ARISTAS...!!!!" << endl;
        return;
      }
      else
      {
        cout << "NODO|LISTA DE ADYACENCIA" << endl;
        cout << "   " << aux->nombre << "|";
        ar = aux->ady;

        while (ar != NULL)
        {
          cout << ar->destino->nombre << " ";
          ar = ar->sgte;
        }
        cout << endl;
        return;
      }
    }
    aux = aux->sgte;
  }
}

void BFS()
{
  char start;
  cout << "INGRESE EL NODO INICIAL PARA BFS: ";
  cin >> start;

  Tnodo aux = p;
  while (aux != NULL && aux->nombre != start)
  {
    aux = aux->sgte;
  }

  if (aux != NULL)
  {
    BFSUtil(aux);
  }
  else
  {
    cout << "NODO NO ENCONTRADO" << endl;
  }
}

void BFSUtil(Tnodo start)
{
  if (start == NULL)
  {
    return;
  }

  unordered_set<char> visited;
  queue<Tnodo> q;
  visited.insert(start->nombre);
  q.push(start);

  while (!q.empty())
  {
    Tnodo current = q.front();
    q.pop();
    cout << current->nombre << " ";

    Tarista ar = current->ady;
    while (ar != NULL)
    {
      if (visited.find(ar->destino->nombre) == visited.end())
      {
        visited.insert(ar->destino->nombre);
        q.push(ar->destino);
      }
      ar = ar->sgte;
    }
  }
  cout << endl;
}

void DFS()
{
  char start;
  cout << "INGRESE EL NODO INICIAL PARA DFS: ";
  cin >> start;

  Tnodo aux = p;
  while (aux != NULL && aux->nombre != start)
  {
    aux = aux->sgte;
  }

  if (aux != NULL)
  {
    DFSUtil(aux);
  }
  else
  {
    cout << "NODO NO ENCONTRADO" << endl;
  }
}

void DFSUtil(Tnodo start)
{
  if (start == NULL)
  {
    return;
  }

  unordered_set<char> visited;
  stack<Tnodo> s;
  visited.insert(start->nombre);
  s.push(start);

  while (!s.empty())
  {
    Tnodo current = s.top();
    s.pop();
    cout << current->nombre << " ";

    Tarista ar = current->ady;
    while (ar != NULL)
    {
      if (visited.find(ar->destino->nombre) == visited.end())
      {
        visited.insert(ar->destino->nombre);
        s.push(ar->destino);
      }
      ar = ar->sgte;
    }
  }
  cout << endl;
}
