#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *left;
  Node *right;
  Node(int val)
  {
    data = val;
    left = nullptr;
    right = nullptr;
  }
};

class BinaryTree
{
  Node *root;

public:
  BinaryTree()
  {
    root = nullptr;
  }

  void insert(int data)
  {
    Node *newNode = new Node(data);
    if (root == nullptr)
    {
      root = newNode;
      return;
    }

    Node *current = root;
    Node *parent = nullptr;

    while (true)
    {
      parent = current;
      if (data < current->data)
      {
        current = current->left;
        if (current == nullptr)
        {
          parent->left = newNode;
          return;
        }
      }
      else
      {
        current = current->right;
        if (current == nullptr)
        {
          parent->right = newNode;
          return;
        }
      }
    }
  }

  void inorderTraversal(Node *node)
  {
    if (node == nullptr)
      return;
    inorderTraversal(node->left);
    cout << node->data << " ";
    inorderTraversal(node->right);
  }

  void inorder()
  {
    inorderTraversal(root);
  }
};

int main()
{
  BinaryTree tree;

  tree.insert(10);
  tree.insert(6);
  tree.insert(15);
  tree.insert(3);
  tree.insert(8);
  tree.insert(20);

  cout << "Recorrido en orden del arbol binario: ";
  tree.inorder();
  cout << endl;

  return 0;
}
