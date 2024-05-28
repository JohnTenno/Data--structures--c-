#include <iostream>
using namespace std;

struct AdjListNode
{
  int dest;
  AdjListNode *next;
};

struct AdjList
{
  AdjListNode *head;
};

class Graph
{
  int V;
  AdjList *array;

public:
  Graph(int V)
  {
    this->V = V;
    array = new AdjList[V];
    for (int i = 0; i < V; ++i)
      array[i].head = nullptr;
  }

  void addEdge(int src, int dest)
  {
    AdjListNode *newNode = new AdjListNode;
    newNode->dest = dest;
    newNode->next = array[src].head;
    array[src].head = newNode;
  }

  void printGraph()
  {
    for (int v = 0; v < V; ++v)
    {
      AdjListNode *pCrawl = array[v].head;
      cout << "\n Lista de adyacencia del vrtice " << v << "\n cabeza ";
      while (pCrawl)
      {
        cout << "-> " << pCrawl->dest;
        pCrawl = pCrawl->next;
      }
      cout << endl;
    }
  }
};

int main()
{
  int V = 5;
  Graph graph(V);

  graph.addEdge(0, 1);
  graph.addEdge(0, 4);
  graph.addEdge(1, 2);
  graph.addEdge(1, 3);
  graph.addEdge(1, 4);
  graph.addEdge(2, 3);
  graph.addEdge(3, 4);

  graph.printGraph();

  return 0;
}
