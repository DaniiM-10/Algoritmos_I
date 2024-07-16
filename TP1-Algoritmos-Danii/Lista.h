#include <iostream>

using namespace std;

typedef int item;
const item INDEFINIDO = -99999;

// Escriba una tipificación adecuada que defina LISTA como una lista enlazada.
typedef struct Nodo {
    item dato;
    Nodo* siguiente;
}Nodo;

typedef struct Lista {
    Nodo* cabecera;
    int longitud;
}Lista;

Lista crearLista () { // Crea una lista vacia
    Lista nueva_lista;
    nueva_lista.cabecera = nullptr;
    nueva_lista.longitud = 0;
    return nueva_lista;
}

bool esListaVacia (Lista _lista) { // Determina si la lista está vacía
    return _lista.cabecera == nullptr;
}

void mostrar (Lista _lista) { // Muestra por pantalla el contenido de los nodos de la lista
    if (esListaVacia(_lista)) {
        cout << "La lista esta vacia" << endl;
    } else {
        Nodo* actual = _lista.cabecera; // Asignamos la cabecera de la lista a un nodo auxiliar
        while (actual != nullptr) { // Mientras la cabecera actual no sea nulo
            cout << actual->dato << endl;
            actual = actual->siguiente; // Avanzo al proximo nodo
        }
    }
}

item primerElemento (Lista _lista) { // Retorna el valor del primer nodo de la lista
    return (esListaVacia(_lista)) ? INDEFINIDO : _lista.cabecera->dato;
}

Lista insertar (Lista _lista, item _dato) { // Inserta un valor dado al comienzo de la lista
    Nodo* nuevo_nodo = new Nodo;
    nuevo_nodo->dato = _dato;

    if (esListaVacia(_lista)) {
        nuevo_nodo->siguiente = nullptr;
        _lista.cabecera = nuevo_nodo;
    } else {
        Nodo* actual = _lista.cabecera;
        nuevo_nodo->siguiente = actual;
        _lista.cabecera = nuevo_nodo;   
    }

    _lista.longitud += 1;
    return _lista;
}

Lista borrar (Lista _lista) { // Borra el nodo del comienzo de la lista
    Nodo* nodo_borrar = _lista.cabecera;
    if (!esListaVacia(_lista)) {
        _lista.cabecera = nodo_borrar->siguiente;
        _lista.longitud -= 1;
    }
    
    delete nodo_borrar;
    return _lista;
}

int longitud (Lista _lista) { // Retorna la cantidad de nodos que tiene la lista
    return _lista.longitud;
}

bool pertenece (Lista _lista, item _dato) { // Determina si un valor dado pertenece a la lista
    if (esListaVacia(_lista)) {
        return false;
    }

    Nodo* actual = _lista.cabecera;
    while (actual != nullptr) {
        if (actual->dato == _dato) {
            return true;
        }
        actual = actual->siguiente;
    }

    return false;
}

Lista insertarK (Lista _lista, item _dato, int _pos) { // Inserta un nodo en la posicion dada
    if (esListaVacia(_lista) || _pos == 1) { // Insertamos al incio
        return insertar(_lista, _dato);
    }

    Nodo* nuevo_nodo = new Nodo;
    nuevo_nodo->dato = _dato;

    Nodo* actual = _lista.cabecera;

    if (_pos <= 0 || _pos >= _lista.longitud) { // Insertamos al final
        nuevo_nodo->siguiente = nullptr;

        while (actual->siguiente != nullptr) { // Avanzamos hasta el ultimo nodo de la lista
            actual = actual->siguiente;
        }
    } else { // Insertamos en la posicion dada
        for (int i = 1; i < _pos-1; i++) { // Avanzamos hasta la posicion-1 de donde queremos insertar el nodo
            actual = actual->siguiente;
        }
        nuevo_nodo->siguiente = actual->siguiente;
    }

    actual->siguiente = nuevo_nodo;
    return _lista;
}