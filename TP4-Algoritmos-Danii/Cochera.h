#include <iostream>

using namespace std;

typedef int Coche;
const Coche INDEFINIDO = -99999;

typedef struct Nodo {
    Coche coche;
    Nodo *siguiente;
} Nodo;

typedef struct Cochera {
    Nodo *coches;
    int tam;
} Cochera;

Cochera cocheraVacia (int _tam) {
    Cochera cochera_vacia;
    cochera_vacia.coches = nullptr;
    cochera_vacia.tam = _tam;

    return cochera_vacia;
}

bool estaVacia (Cochera _cochera) {
    return _cochera.coches == nullptr;
}

int libre (Cochera _cochera) {
    if (estaVacia(_cochera)) {
        return _cochera.tam;
    } else {
        Cochera aux = _cochera;
        aux.coches = _cochera.coches->siguiente;
        return libre(aux) - 1;
    }
}

Cochera estacionar (Cochera _cochera, Coche _coche) {
    Nodo* nuevo_coche = new Nodo;
    nuevo_coche->coche = _coche;

    if (estaVacia(_cochera)) {
        nuevo_coche->siguiente = nullptr;
    } else {
        if (libre(_cochera) > 0) nuevo_coche->siguiente = _cochera.coches;
    }
    _cochera.coches = nuevo_coche;

    return _cochera;
}

Cochera quitarUltimo (Cochera _cochera) {
    if (estaVacia(_cochera)) return _cochera;

    Nodo* ultimo_auto = new Nodo;
    ultimo_auto = _cochera.coches;
    _cochera.coches = _cochera.coches->siguiente;

    delete ultimo_auto;

    return _cochera;
}

Cochera salir (Cochera _cochera, Coche _coche) {
    if (estaVacia(_cochera)) return _cochera;

    Cochera aux = _cochera;

    Nodo* actual = new Nodo;
    actual = _cochera.coches;

    if (actual->coche == _coche) {
        aux.coches = aux.coches->siguiente;
        delete actual;
        return aux;
    } else {
        aux.coches = aux.coches->siguiente;
        return estacionar(salir(aux, _coche), actual->coche);
    }
}

Coche ultimo (Cochera _cochera) {
    return estaVacia(_cochera) ? INDEFINIDO : _cochera.coches->coche;
}

bool estacionado (Cochera _cochera, Coche _coche) {
    if (estaVacia(_cochera)) return false;

    Cochera aux = _cochera;

    if (aux.coches->coche == _coche) {
        aux.coches = aux.coches->siguiente;
        return true;
    } else {
        aux.coches = aux.coches->siguiente;
        return estacionado(aux, _coche);
    }
}

int capacidad (Cochera _cochera) {
    return _cochera.tam;
}