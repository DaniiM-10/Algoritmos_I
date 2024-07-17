#include <iostream>
#include "Lista.h"

using namespace std;

Lista mezclarLista(Lista _lista);
void dividirLista(Lista _lista, Lista* _a, Lista* _b);
Lista combinarLista(Lista _a, Lista _b);

int main() {
    Lista lista = crearLista();

    // INSERTAMOS NODOS EN LA LISTA
    lista = insertar(lista, 61);
    lista = insertar(lista, 10);
    lista = insertar(lista, 87);
    lista = insertar(lista, 25);
    lista = insertar(lista, 0);
    lista = insertar(lista, 15);
    lista = insertar(lista, 3);

    // APLICO MERGE SORT
    lista = mezclarLista(lista);

    // MUESTRO LA LISTA
    mostrar(lista);

    return 0;
}

Lista mezclarLista(Lista _lista) {
    if (esListaVacia(_lista) || _lista.cabecera->siguiente == nullptr) {
        return _lista;
    } else {
        Lista a, b;
        // Dividimos las listas por referencia
        dividirLista(_lista, &a, &b);
        // Por ultimo las mezclamos y combinamos
        return combinarLista(mezclarLista(a), mezclarLista(b));
    }

}

void dividirLista(Lista _lista, Lista* _a, Lista* _b) {
    Nodo* rapido;
    Nodo* lento;
    lento = _lista.cabecera;
    rapido = _lista.cabecera->siguiente;

    // Usamos dos punteros, rápido (avanza de 2 posiciones) y lento (avanza de a 1 posicion), para encontrar la mitad de la lista
    while (rapido != nullptr) {
        rapido = rapido->siguiente; // Avanza 1 posicion el rapido
        if (rapido != nullptr) { // Si no es nulo donde está parado
            lento = lento->siguiente; // Avanza 1 posicion el lento
            rapido = rapido->siguiente; // Avanza la 2da posicion el rapido
        }
    }

    // Inicializamos las listas
    *_a = crearLista();
    *_b = crearLista();

    // Asignamos a cada lista una mitad
    _a->cabecera = _lista.cabecera;
    _b->cabecera = lento->siguiente;
    lento->siguiente = nullptr; // Desconecto la primera mitad de la segunda, para que _a no tengo la otra mitad de la lista original
}

Lista combinarLista(Lista a, Lista b) {
    Lista resultado = crearLista();
    Nodo* punteroResultado = nullptr;  // Puntero al último nodo añadido a la lista resultante

    // Inicializamos la cabecera de la lista resultado con el menor valor entre a y b
    if (a.cabecera != nullptr && b.cabecera != nullptr) {
        if (a.cabecera->dato <= b.cabecera->dato) {
            resultado.cabecera = a.cabecera;
            a.cabecera = a.cabecera->siguiente;
        } else {
            resultado.cabecera = b.cabecera;
            b.cabecera = b.cabecera->siguiente;
        }
        punteroResultado = resultado.cabecera;
    }

    // Combinar listas mientras ambas no estén vacías
    while (a.cabecera != nullptr && b.cabecera != nullptr) {
        if (a.cabecera->dato <= b.cabecera->dato) {
            punteroResultado->siguiente = a.cabecera;
            a.cabecera = a.cabecera->siguiente;
        } else {
            punteroResultado->siguiente = b.cabecera;
            b.cabecera = b.cabecera->siguiente;
        }
        punteroResultado = punteroResultado->siguiente;
    }

    // Agregar los nodos restantes de la lista no vacía
    if (a.cabecera != nullptr) {
        punteroResultado->siguiente = a.cabecera;
    } else {
        punteroResultado->siguiente = b.cabecera;
    }

    return resultado;
}
