#include <iostream>
#include <string>
using namespace std;

struct Node
{
  string name;
  string phone;
  Node *left;  // Puntero al nodo hijo izquierdo
  Node *right; // Puntero al nodo hijo derecho

  // Constructor del nodo
  Node(string n, string p)
  {
    name = n;
    phone = p;
    left = nullptr;
    right = nullptr;
  }
};

// Definición de la clase ContactTree para gestionar los contactos
class ContactTree
{
  Node *root; // Puntero a la raiz del arbol

public:
  // Constructor de la clase, inicializa la raiz como nula
  ContactTree()
  {
    root = nullptr;
  }

  // insertar un nuevo contacto en el arbol
  void insert(string name, string phone)
  {
    Node *newNode = new Node(name, phone); // Crear un nuevo nodo con el nombre y teléfono dados
    if (root == nullptr)
    {
      root = newNode; // Si el arbol está vacío, el nuevo nodo es la raiz
      return;
    }

    Node *current = root;   // Puntero para recorrer el arbol
    Node *parent = nullptr; // Puntero al nodo padre

    while (true)
    {
      parent = current;
      if (name < current->name)
      {
        current = current->left;
        if (current == nullptr)
        {
          parent->left = newNode; // Insertar el nuevo nodo como hijo izquierdo
          return;
        }
      }
      else
      {
        current = current->right;
        if (current == nullptr)
        {
          parent->right = newNode; // Insertar el nuevo nodo como hijo derecho
          return;
        }
      }
    }
  }

  // para buscar un contacto por nombre
  Node *search(string name)
  {
    Node *current = root;
    while (current != nullptr && current->name != name)
    {
      if (name < current->name)
        current = current->left;
      else
        current = current->right;
    }
    return current;
  }

  // para realizar un recorrido en orden del arbol y mostrar los contactos
  void inorderTraversal(Node *node)
  {
    if (node == nullptr)
      return;
    inorderTraversal(node->left);                                              // Recorrer el subarbol izquierdo
    cout << "Nombre: " << node->name << ", Telefono: " << node->phone << endl; // Imprimir el contacto actual
    inorderTraversal(node->right);                                             // Recorrer el subarbol derecho
  }

  // para iniciar el recorrido en orden desde la raiz
  void displayContacts()
  {
    inorderTraversal(root);
  }
};

// Función principal
int main()
{
  ContactTree contacts; // Crear una instancia de la clase ContactTree

  // Insertar contactos en el arbol
  contacts.insert("John Tenno", "614304713");
  contacts.insert("La teacher", "614293821");
  contacts.insert("Mom", "6143047137");
  contacts.insert("hermano", "6143131740");

  // Buscar un contacto
  string searchName = "John Tenno";
  Node *contact = contacts.search(searchName);
  if (contact != nullptr)
    cout << "Contacto encontrado: " << contact->name << ", Telefono: " << contact->phone << endl;
  else
    cout << "Contacto " << searchName << " no encontrado." << endl;

  // Mostrar todos los contactos en orden
  cout << "\nLista de contactos en orden:" << endl;
  contacts.displayContacts();

  return 0;
}
