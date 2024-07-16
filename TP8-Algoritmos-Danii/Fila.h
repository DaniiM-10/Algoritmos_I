#include <iostream>

using namespace std;

typedef int item;
const item INDEFINIDO = -99999;

typedef struct Nodo {
    item dato;
    Nodo *siguiente;
}Nodo;

typedef struct Fila {
    Nodo* frente;
    Nodo* final;
    int longitud;
}Fila;

Fila filaVacia () {
    Fila nueva_fila;
    nueva_fila.frente = nullptr;
    nueva_fila.final = nullptr;
    nueva_fila.longitud = 0;
    return nueva_fila;
}

bool esFilaVacia (Fila _fila) {
    return _fila.frente == nullptr;
}

item frente (Fila _fila) {
    if (esFilaVacia(_fila)) return INDEFINIDO;

    return _fila.frente->dato;
}

Fila enfila (Fila _fila, item _dato) {
    Nodo* nuevo_nodo = new Nodo;
    nuevo_nodo->dato = _dato;
    nuevo_nodo->siguiente = nullptr;

    if (esFilaVacia(_fila)) {
        _fila.frente = nuevo_nodo;
        _fila.final = nuevo_nodo;
    } else {
        _fila.final->siguiente = nuevo_nodo;
        _fila.final = nuevo_nodo;
    }
    _fila.longitud++;
    return _fila;
}

Fila defila (Fila _fila) {
    if (esFilaVacia(_fila)) return _fila;

    Nodo* nodo_borrar = _fila.frente;
    _fila.frente = _fila.frente->siguiente;
    delete nodo_borrar;
    _fila.longitud--;
    return _fila;
}

int longitud (Fila _fila) {
    return _fila.longitud;
}

bool pertenece (Fila _fila, item _dato) {
    if (esFilaVacia(_fila)) {
        return false;
    } else {
        bool comp = _fila.frente->dato == _dato; // Armo un booleano para comparar el frente con el dato dado
        _fila.frente = _fila.frente->siguiente; // Avanzo la fila 
        return comp || pertenece(_fila, _dato);
    }
}

bool igualF (Fila _fila_1, Fila _fila_2) {
    if (esFilaVacia(_fila_1) && esFilaVacia(_fila_2)) {
        return true;
    } else if (esFilaVacia(_fila_1) || esFilaVacia(_fila_2)) {
        return false;
    } else {
        bool comp = (_fila_1.frente->dato == _fila_1.frente->dato); // Armo un booleano para comparar el frente de f1 y f2
        _fila_1.frente = _fila_1.frente->siguiente; // Avanzo la fila 1
        _fila_2.frente = _fila_2.frente->siguiente; // Avanzo la fila 2
        return comp && igualF(_fila_1, _fila_2);
    }
}

Fila concat (Fila _fila_1, Fila _fila_2) {
    if (esFilaVacia(_fila_2)) return _fila_1;
    if (esFilaVacia(_fila_1)) return _fila_2;

    _fila_1.final->siguiente = _fila_2.frente;
    return _fila_1;
}

Fila invertir (Fila _fila) {
    if (esFilaVacia(_fila)) {
        return _fila;
    } else {
        item insertar = _fila.frente->dato;
        _fila.frente = _fila.frente->siguiente;
        return enfila(invertir(_fila), insertar);
    }
}