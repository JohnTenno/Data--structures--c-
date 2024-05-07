#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Arbol
{
  int dato;
  struct Arbol *izq;
  struct Arbol *der;
} arbol;
arbol *raiz;
enum
{
  FALSO = 0,
  VERDADERO
};

/*PROTOTIPOS*/
void inicializar(void);
int vacio(arbol *hoja);
int eshoja(arbol *hoja);
arbol *insertar(arbol *raiz, arbol *hoja, int num);
int busqueda(arbol *hoja, int num);
int alturax(arbol *hoja, int num);
int alturafull(arbol *hoja, int *altura);
void auxaltura(arbol *hoja, int *altura, int cont);
int nodos(arbol *hoja);
void auxnodos(arbol *hoja, int *cont);
arbol *borrarx(arbol *hoja, int num);
arbol *podar(arbol *hoja);
void preorden(arbol *hoja);
void inorden(arbol *hoja);
void posorden(arbol *hoja);
void menu_recorridos(void);
void menu_busquedas(void);
void menu_alturas(void);
void menu_nodos(void);
void menu_podar(void);

void inicializar(void)
{
  raiz = NULL;
}

int vacio(arbol *hoja)
{
  if (!hoja)
    return VERDADERO;
  return FALSO;
}

int eshoja(arbol *hoja)
{
  if (hoja->izq == NULL && hoja->der == NULL)
    return VERDADERO;
  return FALSO;
}

arbol *insertar(arbol *raiz, arbol *hoja, int num)
{
  if (!hoja)
  {
    hoja = (arbol *)malloc(sizeof(arbol));
    hoja->dato = num;
    hoja->izq = NULL;
    hoja->der = NULL;
    if (!raiz)
      return hoja;
    else if (num < raiz->dato)
      raiz->izq = hoja;
    else
      raiz->der = hoja;
    return hoja;
  }
  else if (num < hoja->dato)
    insertar(hoja, hoja->izq, num);
  else
    insertar(hoja, hoja->der, num);
  return raiz;
}

int busqueda(arbol *hoja, int num)

/* Aquí tienes una explicación de la función:
- Utiliza un bucle while para recorrer el árbol comenzando desde el nodo raíz (hoja).
- Si el número objetivo (num) se encuentra en el nodo actual (hoja->dato), la función devuelve un valor verdadero (VERDADERO).
- Si el número objetivo no se encuentra en el nodo actual, la función compara el número objetivo con el valor en el nodo actual para determinar si debe moverse al nodo hijo izquierdo (hoja->izq) o al nodo hijo derecho (hoja->der).
- La función continúa este proceso hasta que encuentre el número objetivo o llegue a un nodo hoja (hoja es NULL).
- Si el número objetivo no se encuentra en el árbol, la función devuelve un valor falso (FALSO). */
{
  while (hoja)
  {
    if (num == hoja->dato)
      return VERDADERO;
    else
    {
      if (num < hoja->dato)
        hoja = hoja->izq;
      else
        hoja = hoja->der;
    }
  }
  return FALSO;
}

int alturax(arbol *hoja, int num)
{
  int altura = 1;

  while (hoja)
  {
    if (num == hoja->dato)
      return altura;
    else
    {
      altura++;
      if (num < hoja->dato)
        hoja = hoja->izq;
      else
        hoja = hoja->der;
    }
  }
  return FALSO;
}

int alturafull(arbol *hoja, int *altura)
{
  auxaltura(hoja, altura, 1);
  return *altura;
}

void auxaltura(arbol *hoja, int *altura, int cont)
{
  if (!hoja)
    return;

  auxaltura(hoja->izq, altura, cont + 1);
  auxaltura(hoja->der, altura, cont + 1);
  if ((eshoja(hoja) && cont) > *altura)
    *altura = cont;
}

int nodos(arbol *hoja)
{
  int nodos = 0;
  auxnodos(hoja, &nodos);
  return nodos;
}

void auxnodos(arbol *hoja, int *cont)
{
  if (!hoja)
    return;

  (*cont)++;
  auxnodos(hoja->izq, cont);
  auxnodos(hoja->der, cont);
}

arbol *borrarx(arbol *hoja, int num)
{
  if (hoja->dato == num)
  {
    arbol *p, *p2;

    if (vacio(hoja))
    {
      free(hoja);
      hoja = NULL;
      return hoja;
    }
    else if (hoja->izq == NULL)
    {
      p = hoja->der;
      free(hoja);
      return p;
    }
    else if (hoja->der == NULL)
    {
      p = hoja->izq;
      free(hoja);
      return p;
    }
    else
    {
      p = hoja->der;
      p2 = hoja->der;
      while (p->izq)
        p = p->izq;
      p->izq = hoja->izq;
      free(hoja);
      return p2;
    }
  }
  else if (num < hoja->dato)
    hoja->izq = borrarx(hoja->izq, num);
  else
    hoja->der = borrarx(hoja->der, num);
  return hoja;
}

arbol *podar(arbol *hoja)
{
  if (!hoja)
    return hoja;

  podar(hoja->izq);
  podar(hoja->der);
  free(hoja);
  hoja = NULL;
  return hoja;
}

/*Recorridos*/

void preorden(arbol *hoja)
{
  // Método preorden:
  // Este método realiza un recorrido en preorden de un árbol binario. Comienza en la raíz del árbol y luego visita primero el nodo actual, después el subárbol izquierdo y finalmente el subárbol derecho. Si el nodo actual es nulo, la función termina. Imprime el valor almacenado en el nodo actual (hoja->dato) y luego realiza un recorrido preorden en el subárbol izquierdo y en el subárbol derecho de manera recursiva.

  if (!hoja)
    return;

  printf("%d ", hoja->dato);
  preorden(hoja->izq);
  preorden(hoja->der);
}

void inorden(arbol *hoja)
{
  // Método inorden : El método inorden realiza un recorrido inorden en un árbol binario.Comienza en la raíz del árbol y visita primero el subárbol izquierdo, luego el nodo actual y finalmente el subárbol derecho.Si el nodo actual es nulo, la función termina.Realiza un recorrido inorden en el subárbol izquierdo, imprime el valor del nodo actual y luego realiza un recorrido inorden en el subárbol derecho de manera recursiva.if (!hoja) return;
  if (!hoja)
    return;
  inorden(hoja->izq);
  printf("%d ", hoja->dato);
  inorden(hoja->der);
}

void posorden(arbol *hoja)
{
  // Método posorden : Este método realiza un recorrido en posorden de un árbol binario.Comienza en la raíz del árbol y visita primero los subárboles izquierdo y derecho, y finalmente el nodo actual.Si el nodo actual es nulo, la función termina.Realiza un recorrido posorden en el subárbol izquierdo, en el subárbol derecho y finalmente imprime el valor del nodo actual de manera recursiva.b if (!hoja) return;
  if (!hoja)
    return;

  posorden(hoja->izq);
  posorden(hoja->der);
  printf("%d ", hoja->dato);
}

/*Menus del Arbol*/
void menu_recorridos(void)
{
  /*Llamando al metodo menu_recorridos
  se accede al menu para luego limpiar el buffer con fflush
  optenemos la opcio con _op*/
  char _op = '1';

  while (_op != '4')
  {
    printf("1. PreOrden.");
    printf("\n2. InOrden.");
    printf("\n3. PosOrden.");
    printf("\n4. Salir.");
    printf("\n\n:: ");
    fflush(stdin);
    scanf("%c", &_op);
    switch (_op)
    {
    case '1':
      preorden(raiz);

      break;
    case '2':
      inorden(raiz);

      break;
    case '3':
      posorden(raiz);

      break;
    }
    system("pause");
  }
}

void menu_busquedas(void)
{
  /*se accede al menu de busquedas. para preguntar al usuario el numero a buscar
  se llama al metodo busqueda donde le pasamos la raiz y el valor a buscar*/
  int val;

  printf("\n\nNumero: ");
  scanf("%d", &val);
  if (busqueda(raiz, val))
    printf("\n\nEncontrado..");
  else
    printf("\n\nError, No se encuentra.");
  system("pause");
}

void menu_alturas(void)
{
  char _op = '1';
  int val, altura;

  while (_op != '3')
  {
    system("cls");
    printf("1. Altura de Un Nodo - Profundidad . ");
    printf("\n2. Altura de Todo el Arbol.");
    printf("\n3. Salir.");
    printf("\n\n:: ");
    fflush(stdin);
    scanf("%c", &_op);

    switch (_op)
    {
    case '1':
      printf("\n\nNumero: ");
      scanf("%d", &val);
      altura = alturax(raiz, val);
      if (!altura)
        printf("\n\nImposible, numero inexistente.");
      else
        printf("\n\nLa Altura es: %i", altura);

      break;
    case '2':
      altura = 0;
      printf("\n\nLa Altura del Arbol es: %i", alturafull(raiz, &altura));

      break;
    default:
      printf("Error\n");
      break;
    }
    system("pause");
  }
}

void menu_nodos(void)
{
  printf("\n\nEl Numero de Nodos es: %i", nodos(raiz));
  system("pause");
}

void menu_podar(void)
{
  char _op = '1';
  int val;

  while (_op != '3')
  {

    printf("1. Podar Un Nodos del Arbol.");
    printf("\n2. Podar Todo el Arbol.");
    printf("\n3. Salir.");
    fflush(stdin);
    scanf("%c", &_op);
    switch (_op)
    {
    case '1':
      printf("\n\nNumero: ");
      scanf("%d", &val);
      raiz = borrarx(raiz, val);
      printf("\n\n.... Borrado ....");
      break;
    case '2':
      raiz = podar(raiz);
      printf("\n\nArbol Borrado por Completo.");

      break;
    }
    system("pause");
  }
  return;
}

int main()
{
  char _op = 'A';
  int val;

  inicializar();

  while (_op != '7')
  {
    system("cls");
    printf("1. Insertar.");
    printf("\n2.Recorridos.");
    printf("\n3.Busquedas.");
    printf("\n4.Alturas.");
    printf("\n5.Nodos.");
    printf("\n6.Podar.");
    printf("\n7.Salir.");
    printf("\n\n:: ");
    fflush(stdin);
    scanf("%c", &_op);

    switch (_op)
    {
    case '1':
      printf("\n\nNumero: ");
      scanf("%d", &val);
      if (busqueda(raiz, val))
      {
        printf("\n\nEste numero ya ha sido insertado.");

        break;
      }
      raiz = insertar(raiz, raiz, val);
      break;
    case '2':
      if (vacio(raiz))
      {
        printf("\n\nEl Arbol Aun esta Vacio.");

        break;
      }
      menu_recorridos();
      break;
    case '3':
      if (vacio(raiz))
      {

        break;
      }
      menu_busquedas();
      break;
    case '4':
      if (vacio(raiz))
      {
        printf("\n\nEl Arbol Aun esta Vacio.");

        break;
      }
      menu_alturas();
      break;
    case '5':
      if (vacio(raiz))
      {
        printf("\n\nEl Arbol Aun esta Vacio.");

        break;
      }
      menu_nodos();
      break;
    case '6':
      if (vacio(raiz))
      {
        printf("\n\nEl Arbol Aun esta Vacio.");

        break;
      }
      menu_podar();
      break;
    }
    system("pause");
  }

  return 0;
}
