#include <iostream>

using namespace std;

typedef int item;
const item INDEFINIDO = -99999;

typedef struct NodoAB {
    item dato;
    NodoAB* izquierda;
    NodoAB* derecha;
} NodoAB;

typedef struct NodoAB* AB;

AB ABVacio () {
    return nullptr;
}

AB armarAB (AB _ab_i, item _dato, AB _ab_d) {
    NodoAB* nuevo_nodo = new NodoAB;

    nuevo_nodo->dato = _dato;
    nuevo_nodo->izquierda = _ab_i;
    nuevo_nodo->derecha = _ab_d;

    return nuevo_nodo;
}

bool esABVacio (AB _ab) {
    return _ab == nullptr;
}

AB izquierdo (AB _ab) {
    return _ab->izquierda;
}

item raiz (AB _ab) {
    if (esABVacio(_ab)) return INDEFINIDO;
    
    return _ab->dato;
}

AB derecho (AB _ab) {
    return _ab->derecha;
}

bool pertenece (AB _ab, item _dato) {
    if (esABVacio(_ab)) return false;

    return _ab->dato == _dato || pertenece(_ab->izquierda, _dato) || pertenece(_ab->derecha, _dato);
}

bool esHoja (AB AB) {
    return esABVacio(izquierdo(AB)) && esABVacio(derecho(AB));
}