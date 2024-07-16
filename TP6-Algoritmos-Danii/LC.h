#include <iostream>

using namespace std;

typedef int item;
const item INDEF = -99999;

typedef struct NodoLC {
    item dato;
    NodoLC *siguiente;
} NodoLC;

typedef struct LC {
    NodoLC* cabecera;
    int longitud;
} LC;

LC lcVacia () {
    LC lc;
    lc.cabecera = nullptr;
    lc.longitud = 0;
    return lc;
}

bool esLcVacia (LC _lc) {
    return _lc.cabecera == nullptr;
}

LC lcInsertar (LC _lc, item _dato) {
    NodoLC* nuevo_nodo = new NodoLC;
    nuevo_nodo->dato = _dato;
    
    if (esLcVacia(_lc)) {
        nuevo_nodo->siguiente = _lc.cabecera;
        _lc.cabecera = nuevo_nodo;
    } else {
        nuevo_nodo->siguiente = _lc.cabecera->siguiente;
        _lc.cabecera->siguiente = nuevo_nodo;
    }
    _lc.longitud++;
    return _lc;
}

LC lcBorrar (LC _lc) {
    if (esLcVacia(_lc)) return _lc;

    NodoLC* nodo_borrar = new NodoLC;
    nodo_borrar = _lc.cabecera->siguiente;
    _lc.cabecera->siguiente = nodo_borrar->siguiente;
    delete nodo_borrar;
    _lc.longitud--;
    return _lc;
}

item lcValor (LC _lc) {
    if (esLcVacia(_lc)) return INDEF;
    return _lc.cabecera->siguiente->dato;
}

LC lcRotar (LC _lc) {
    if (esLcVacia(_lc) || _lc.longitud == 1) return _lc;
    
    _lc.cabecera = _lc.cabecera->siguiente;
    return _lc;
}

// MAAAAAAAAAAAAAAAAL (consultar en el periodo de recuperacion)
/*LC lcUnir (LC _lc_1, LC _lc_2, int lon) {
    if (esLcVacia(_lc_2) || lon == 0) return _lc_1;

    item insertar = _lc_2.cabecera->dato;
    _lc_2.cabecera = _lc_2.cabecera->siguiente;
    _lc_1.longitud += 1;
    return lcInsertar(lcUnir(_lc_1, _lc_2, lon-1), insertar);
}*/

LC lcRotarN (LC _lc, int _n) {
    if (esLcVacia(_lc) || _n == 0 || _lc.longitud == 1) return _lc;

    _lc.cabecera = _lc.cabecera->siguiente;
    return lcRotarN(_lc, _n-1);
}

int lcContarK (LC _lc, item _dato) {
    int cont = 0;

    for (int i = 0; i < _lc.longitud; i++) {
        if (_lc.cabecera->dato == _dato) cont++;
        _lc.cabecera = _lc.cabecera->siguiente;
    }
    
    return cont;
}

