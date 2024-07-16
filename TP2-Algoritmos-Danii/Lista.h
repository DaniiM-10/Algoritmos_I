#include <iostream>

using namespace std;

typedef int item; // O(1)
const item INDEFINIDO = -99999; // O(1)

// Escriba una tipificación adecuada que defina LISTA como una lista enlazada.
typedef struct Nodo { // O(1)
    item dato; // O(1)
    Nodo* siguiente; // O(1)
}Nodo;

typedef struct Lista {
    Nodo* cabecera; // O(1)
    int longitud; // O(1)
}Lista;

Lista crearLista () { // Crea una lista vacia | O(1)
    Lista nueva_lista; // O(1)
    nueva_lista.cabecera = nullptr; // O(1)
    nueva_lista.longitud = 0; // O(1)
    return nueva_lista; // O(1)
}

bool esListaVacia (Lista _lista) { // Determina si la lista está vacía | O(1)
    return _lista.cabecera == nullptr; // O(1)
}

void mostrar (Lista _lista) { // Muestra por pantalla el contenido de los nodos de la lista | O(n)
    if (esListaVacia(_lista)) { // O(1)
        cout << "La lista esta vacia" << endl; // O(1)
    } else {
        Nodo* actual = _lista.cabecera; // Asignamos la cabecera de la lista a un nodo auxiliar | O(1)
        // n = longitud(_lista)
        while (actual != nullptr) { // Mientras la cabecera actual no sea nulo | it.(n)
            cout << actual->dato << endl; // O(1)
            actual = actual->siguiente; // Avanzo al proximo nodo | O(1)
        }
    }
}

item primerElemento (Lista _lista) { // Retorna el valor del primer nodo de la lista | O(1)
    return (esListaVacia(_lista)) ? INDEFINIDO : _lista.cabecera->dato; // O(1)
}

Lista insertar (Lista _lista, item _dato) { // Inserta un valor dado al comienzo de la lista | O(1)
    Nodo* nuevo_nodo = new Nodo; // O(1)
    nuevo_nodo->dato = _dato; // O(1)

    if (esListaVacia(_lista)) { // O(1)
        nuevo_nodo->siguiente = nullptr; // O(1)
        _lista.cabecera = nuevo_nodo; // O(1)
    } else { // O(1)
        Nodo* actual = _lista.cabecera; // O(1)
        nuevo_nodo->siguiente = actual; // O(1)
        _lista.cabecera = nuevo_nodo; // O(1)
    }

    _lista.longitud += 1; // O(1)
    return _lista; // O(1)
}

Lista borrar (Lista _lista) { // Borra el nodo del comienzo de la lista | O(1)
    Nodo* nodo_borrar = _lista.cabecera; // O(1)

    if (!esListaVacia(_lista)) { // O(1)
        _lista.cabecera = nodo_borrar->siguiente; // O(1)
        _lista.longitud -= 1; // O(1)
    }
    
    delete nodo_borrar; // O(1)
    return _lista; // O(1)
}

int longitud (Lista _lista) { // Retorna la cantidad de nodos que tiene la lista | O(1)
    return _lista.longitud; // O(1)
}

bool pertenece (Lista _lista, item _dato) { // Determina si un valor dado pertenece a la lista | O(n)
    if (esListaVacia(_lista)) { // O(1)
        return false; // O(1)
    }

    Nodo* actual = _lista.cabecera; // O(1)
    while (actual != nullptr) { // it.(n)
        if (actual->dato == _dato) { // O(1)
            return true; // O(1)
        }
        actual = actual->siguiente; // O(1)
    }

    return false; // O(1)
}

Lista insertarK (Lista _lista, item _dato, int _pos) { // Inserta un nodo en la posicion dada | O(n)
    if (esListaVacia(_lista) || _pos == 1) { // Insertamos al incio | O(1)
        return insertar(_lista, _dato); // O(1)
    }

    Nodo* nuevo_nodo = new Nodo; // O(1)
    nuevo_nodo->dato = _dato; // O(1)

    Nodo* actual = _lista.cabecera; // O(1)

    
    if (_pos <= 0 || _pos >= _lista.longitud) { // Insertamos al final | O(n)
        nuevo_nodo->siguiente = nullptr; // O(1)

        while (actual->siguiente != nullptr) { // Avanzamos hasta el ultimo nodo de la lista | it.(n)
            actual = actual->siguiente; // O(1)
        }
    } else { // Insertamos en la posicion dada | O(n) (peor de los casos)
        for (int i = 1; i < _pos-1; i++) { // Avanzamos hasta la posicion-1 de donde queremos insertar el nodo | it.(n) (peor de los casos)
            actual = actual->siguiente; // O(1)
        }
        nuevo_nodo->siguiente = actual->siguiente; // O(1)
    }

    actual->siguiente = nuevo_nodo; // O(1)
    return _lista; // O(1)
}