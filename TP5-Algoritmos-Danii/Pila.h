#include <iostream>

using namespace std;

typedef int item;
const item INDEFINIDO = -99999;

typedef struct Nodo {
    item dato;
    Nodo *siguiente;
} Nodo;

typedef struct Pila {
    Nodo* cabecera;
    int longitud;
} Pila;

Pila pilaVacia () {
    Pila nueva_pila;
    nueva_pila.cabecera = nullptr;
    nueva_pila.longitud = 0;
    return nueva_pila;
}

bool esPilaVacia (Pila _pila) {
    return _pila.cabecera == nullptr;
}

item top (Pila _pila) {
    if (esPilaVacia(_pila)) return INDEFINIDO;

    return _pila.cabecera->dato;
}

Pila pop (Pila _pila) {
    if (esPilaVacia(_pila)) return _pila;

    Nodo* nodo_borrar = _pila.cabecera;
    _pila.cabecera = _pila.cabecera->siguiente;
    _pila.longitud--;
    delete nodo_borrar;
    return _pila;
}

Pila push (Pila _pila, item _dato) {
    Nodo* nuevo_nodo = new Nodo;
    nuevo_nodo->dato = _dato;
    nuevo_nodo->siguiente = _pila.cabecera;
    _pila.cabecera = nuevo_nodo;
    _pila.longitud++;
    return _pila;
}

int altura (Pila _pila) {
    return _pila.longitud;
}

bool igualP (Pila _pila_1, Pila _pila_2) {
    if (esPilaVacia(_pila_1) && esPilaVacia(_pila_2)) {
        return true;
    } else {
        if (_pila_1.cabecera->dato != _pila_2.cabecera->dato) {
            return false;
        } else {
            _pila_1.cabecera = _pila_1.cabecera->siguiente;
            _pila_2.cabecera = _pila_2.cabecera->siguiente;
            return igualP(_pila_1, _pila_2);
        }
    }
}

Pila apila (Pila _pila_1, Pila _pila_2) {
    return (esPilaVacia(_pila_2)) ? _pila_1 : push(apila(_pila_1, pop(_pila_2)), top(_pila_2));
}