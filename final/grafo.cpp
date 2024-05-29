#include <iostream>
#include <vector>
#include <string>
using namespace std;

// nodo en la lista de adyacencia
struct AdjListNode
{
  int dest;
  AdjListNode *next;
};

//  lista de adyacencia
struct AdjList
{
  AdjListNode *head;
};

// Clase para representar un grafo
class Graph
{
  int V;          // Número de vertices en el grafo
  AdjList *array; // Lista de adyacencia

  // Vector para almacenar los nombres de las paradas de autobús
  // un vector sirve para almacenar secuencias continuas de elemttos, y puede creecer y decreser dinamicamente
  vector<string> busStops;

public:
  Graph(int V)
  {
    this->V = V;
    array = new AdjList[V];
    // cada elemento es una instancia de adjlist sirve para guardar la lista de cada vertice
    for (int i = 0; i < V; ++i)
      array[i].head = nullptr;
  }

  //  añadir el nombre de una parada de autobús
  void addBusStop(int index, string name)
  {
    if (index >= 0 && index < V)
    {
      if (busStops.size() <= index)
      {
        busStops.resize(index + 1);
      }
      busStops[index] = name;
    }
  }

  //  para añadir una arista al grafo
  void addEdge(int src, int dest)
  {
    AdjListNode *newNode = new AdjListNode;
    newNode->dest = dest;
    newNode->next = array[src].head;
    array[src].head = newNode;
  }

  //  para imprimir el grafo
  void printGraph()
  {
    for (int v = 0; v < V; ++v)
    {
      AdjListNode *pCrawl = array[v].head;
      cout << "\nLista de rutas desde " << busStops[v] << ":\n";
      while (pCrawl)
      {
        cout << busStops[v] << " -> " << busStops[pCrawl->dest] << "\n";
        pCrawl = pCrawl->next;
      }
    }
  }
};

int main()
{
  int V = 5;
  Graph graph(V);

  // Añadir nombres a las paradas de autobús
  graph.addBusStop(0, "Chihuahua 2000");
  graph.addBusStop(1, "La 20");
  graph.addBusStop(2, "Riberas");
  graph.addBusStop(3, "Tec");
  graph.addBusStop(4, "Uach");

  // Añadir rutas entre las paradas de autobús
  graph.addEdge(0, 1);
  graph.addEdge(0, 4);
  graph.addEdge(1, 2);
  graph.addEdge(1, 3);
  graph.addEdge(1, 4);
  graph.addEdge(2, 3);
  graph.addEdge(3, 4);

  // Imprimir el grafo
  graph.printGraph();

  return 0;
}
