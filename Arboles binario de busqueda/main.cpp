#include <iostream>

using namespace std;

struct nodo
{
    char inf;
    nodo *izq = nullptr;
    nodo *der = nullptr;
};

void insertar(nodo *&, char);
void preorden(const nodo *);
void inorden(const nodo *);
void postorden(const nodo *);

int main()
{
    nodo *raiz = nullptr;

    char caracter;
    cout << "Ingrese caracteres para construir el árbol (ingrese '.' para terminar): ";
    while (cin >> caracter && caracter != '.')
    {
        insertar(raiz, caracter);
    }

    cout << "\nRecorrido preorden: ";
    preorden(raiz);

    cout << "\n\nRecorrido inorden: ";
    inorden(raiz);

    cout << "\n\nRecorrido postorden: ";
    postorden(raiz);

    delete raiz;
    return 0;
}

void insertar(nodo *&raiz, char valor)
{
    if (raiz == nullptr)
    {
        raiz = new nodo;
        raiz->inf = valor;
    }
    else if (valor < raiz->inf)
    {
        insertar(raiz->izq, valor);
    }
    else if (valor > raiz->inf)
    {
        insertar(raiz->der, valor);
    }
}

void preorden(const nodo *raiz)
{
    if (raiz != nullptr)
    {
        cout << raiz->inf << " ";
        preorden(raiz->izq);
        preorden(raiz->der);
    }
}

void inorden(const nodo *raiz)
{
    if (raiz != nullptr)
    {
        inorden(raiz->izq);
        cout << raiz->inf << " ";
        inorden(raiz->der);
    }
}

void postorden(const nodo *raiz)
{
    if (raiz != nullptr)
    {
        postorden(raiz->izq);
        postorden(raiz->der);
        cout << raiz->inf << " ";
    }
}