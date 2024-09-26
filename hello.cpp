#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};


void insertarAlFinal(Nodo*& cabeza, int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->siguiente = NULL;
    
    if (cabeza == NULL) {
        cabeza = nuevo;
    } else {
        Nodo* actual = cabeza;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }
}

void imprimirLista(Nodo* cabeza) {
    Nodo* actual = cabeza;
    while (actual != NULL) {
        cout << actual->dato << " ";
        actual = actual->siguiente;
    }
    cout << endl;
}


Nodo* combinarListas(Nodo* L1, Nodo* L2) {
    Nodo* combinada = NULL;
    Nodo* actual1 = L1;
    Nodo* actual2 = L2;

    while (actual1 != NULL || actual2 != NULL) {
        if (actual1 != NULL) {
            insertarAlFinal(combinada, actual1->dato);
            actual1 = actual1->siguiente;
        }
        if (actual2 != NULL) {
            insertarAlFinal(combinada, actual2->dato);
            actual2 = actual2->siguiente;
        }
    }

    return combinada;
}

int main() {
    Nodo* L1 = NULL;
    Nodo* L2 = NULL;

    insertarAlFinal(L1, 4);
    insertarAlFinal(L1, 7);
    insertarAlFinal(L1, 9);
    insertarAlFinal(L1, 12);
    insertarAlFinal(L1, 16);

    insertarAlFinal(L2, -101);
    insertarAlFinal(L2, -127);
    insertarAlFinal(L2, -198);
    insertarAlFinal(L2, -108);


    cout << "Lista 1: ";
    imprimirLista(L1);

    cout << "Lista 2: ";
    imprimirLista(L2);

    Nodo* combinada = combinarListas(L1, L2);

    cout << "Lista combinada: ";
    imprimirLista(combinada);

    return 0;
}
