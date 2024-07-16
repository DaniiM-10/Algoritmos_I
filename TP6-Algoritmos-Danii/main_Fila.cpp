#include <iostream>
#include "Fila.h"

using namespace std;

Fila mezclar(Fila* _fila1, Fila* _fila2);
Fila mezclarR(Fila* _fila_1, Fila* _fila_2, Fila _fila_aux);

int main () {
    // CREAMOS UNA FILA VACIA
    /*cout << "Creamos una fila vacia" << endl;
    Fila fila;
    fila = filaVacia();

    // VERIFICAMOS SI LA FILA ESTA VACIA O NO
    cout << "\nLa fila esta vacia? " << (esFilaVacia(fila) ? "Si" : "No") << endl;

    // ENFILAMOS ALGUNOS DATOS
    cout << "\nEnfilamos algunos datos!" << endl;
    fila = enfila(fila, 1);
    fila = enfila(fila, 2);
    fila = enfila(fila, 3);
    fila = enfila(fila, 4);
    fila = enfila(fila, 5);

    // VERIFICAMOS SI LA FILA ESTA VACIA O NO
    cout << "\nLa fila esta vacia? " << (esFilaVacia(fila) ? "Si" : "No") << endl;

    // OBTENEMOS EL FRENTE DE LA FILA
    cout << "\nEl frente de la fila es: " << frente(fila) << endl;

    // PEDIMOS LA LONGITUD DE LA FILA
    cout << "\nLa longitud de la fila es: " << longitud(fila) << endl;

    // VERIFICAMOS SI EL NUMERO 3 PERTENECE A LA FILA
    cout << "\nEl numero 3 pertenece a la fila? " << (pertenece(fila, 3) ? "Si" : "No") << endl;

    // MOSTRAMOS LA FILA
    cout << "\nMostramos la fila: " << endl;
    Fila fila_aux = fila;
    while (fila_aux.frente != nullptr) {
        cout << frente(fila_aux) << endl;
        fila_aux.frente = fila_aux.frente->siguiente;
    }
    
    // DEFILAMOS UN NODO
    cout << "\nDefilamos un nodo!" << endl;
    fila = defila(fila);

    // MOSTRAMOS LA FILA
    cout << "\nMostramos la fila: " << endl;
    fila_aux = fila;
    while (fila_aux.frente != nullptr) {
        cout << frente(fila_aux) << endl;
        fila_aux.frente = fila_aux.frente->siguiente;
    }

    // OBTENEMOS EL FRENTE DE LA FILA
    cout << "\nEl frente de la fila es: " << frente(fila) << endl;

    // CREAMOS UNA FILA 2 VACIA
    cout << "\nCreamos una fila 2 vacia" << endl;
    Fila fila_2;
    fila_2 = filaVacia();

    // ENFILAMOS ALGUNOS DATOS
    cout << "\nEnfilamos algunos datos!" << endl;
    fila_2 = enfila(fila_2, 2);
    fila_2 = enfila(fila_2, 3);
    fila_2 = enfila(fila_2, 4);
    fila_2 = enfila(fila_2, 5);

    // MOSTRAMOS LA FILA 2
    cout << "\nMostramos la fila 2: " << endl;
    fila_aux = fila_2;
    while (fila_aux.frente != nullptr) {
        cout << frente(fila_aux) << endl;
        fila_aux.frente = fila_aux.frente->siguiente;
    }

    // OBTENEMOS EL FRENTE DE LA FILA
    cout << "\nEl frente de la fila 2 es: " << frente(fila_2) << endl;

    // DEFILAMOS UN NODO
    cout << "\nDefilamos un nodo de la fila 2!" << endl;
    fila_2 = defila(fila_2);

    // OBTENEMOS EL FRENTE DE LA FILA
    cout << "\nEl frente de la fila 2 es: " << frente(fila_2) << endl;

    // COMPARO LAS 2 FILAS
    cout << "\nLa fila 1 es igual a la fila 2? " << (igualF(fila, fila_2) ? "Si" : "No") << endl;

    // MOSTRAMOS LA FILA
    cout << "\nMostramos la fila: " << endl;
    fila_aux = fila;
    while (fila_aux.frente != nullptr) {
        cout << frente(fila_aux) << endl;
        fila_aux.frente = fila_aux.frente->siguiente;
    }

    // MOSTRAMOS LA FILA 2
    cout << "\nMostramos la fila 2: " << endl;
    fila_aux = fila_2;
    while (fila_aux.frente != nullptr) {
        cout << frente(fila_aux) << endl;
        fila_aux.frente = fila_aux.frente->siguiente;
    }

    // CREAMOS UNA FILA 3 VACIA
    cout << "\nCreamos una fila 2 vacia" << endl;
    Fila fila_3;
    fila_3 = filaVacia();

    // CONCATENAMOS LA FILA 1 Y FILA 2
    cout << "\nConcatenamos la fila 1 y la fila 2!" << endl;
    fila_3 = concat(fila, fila_2);

    // MOSTRAMOS LA FILA 3
    cout << "\nMostramos la fila 3: " << endl;
    fila_aux = fila_3;
    while (fila_aux.frente != nullptr) {
        cout << frente(fila_aux) << endl;
        fila_aux.frente = fila_aux.frente->siguiente;
    }

    // INVERTIMOS LA FILA 3
    cout << "\nInvertimos la fila 3!" << endl;
    fila_3 = invertir(fila_3);

    // MOSTRAMOS LA FILA 3
    cout << "\nMostramos la fila 3: " << endl;
    fila_aux = fila_3;
    while (fila_aux.frente != nullptr) {
        cout << frente(fila_aux) << endl;
        fila_aux.frente = fila_aux.frente->siguiente;
    }*/

    // CREAMOS 2 FILAS ORDENADAS PARA MEZCLARLAS ENTRE SI
    cout << "\nCreamos 2 filas ordenadas para mezclarlas entre si!" << endl;
    Fila fila_1, fila_2;
    fila_1 = filaVacia();
    fila_2 = filaVacia();

    // ENFILAMOS DATOS EN AMBAS FILAS DE MANERA ORDENADA
    cout << "\nEnfilamos datos en ambas filas de manera ordenada!" << endl;
    fila_1 = enfila(fila_1, 1);
    fila_1 = enfila(fila_1, 3);
    fila_1 = enfila(fila_1, 5);
    fila_1 = enfila(fila_1, 7);
    fila_1 = enfila(fila_1, 9);

    fila_2 = enfila(fila_2, 0);
    fila_2 = enfila(fila_2, 2);
    fila_2 = enfila(fila_2, 4);
    fila_2 = enfila(fila_2, 6);
    fila_2 = enfila(fila_2, 8);

    // MEZCLAMOS AMBAS FILAS
    /*cout << "\nMezclamos ambas filas!" << endl;
    Fila fila_aux = filaVacia();
    fila_aux = mezclar(&fila_1, &fila_2);

    // MUESTRO LA FILA MEZCLADA
    cout << "\nMostramos la fila mezclada: " << endl;
    while (fila_aux.frente != nullptr) {
        cout << frente(fila_aux) << endl;
        fila_aux.frente = fila_aux.frente->siguiente;
    }*/

    // CREAMOS UNA FILA CONCAT VACIA
    cout << "\nCreamos una fila concat vacia" << endl;
    Fila fila_concat;
    fila_concat = filaVacia();

    // CONCATENAMOS LA FILA 1 Y FILA 2
    cout << "\nConcatenamos la fila 1 y la fila 2!" << endl;
    fila_concat = concat(fila_1, fila_2);

    // MOSTRAMOS LA FILA CONCAT
    cout << "\nMostramos la fila concat: " << endl;
    Fila fila_mostrar = fila_concat;
    while (fila_mostrar.frente != nullptr) {
        cout << frente(fila_mostrar) << endl;
        fila_mostrar.frente = fila_mostrar.frente->siguiente;
    }

    // LIBERAR MEMORIA CON LA FUNCION defila :P 
    cout << "\nLibero la memoria reservada en forma dinamica" << endl;
    /*while(!esFilaVacia(fila)) {
        fila = defila(fila);
    }*/
    /*while(!esFilaVacia(fila_aux)) {
        fila_aux = defila(fila_aux);
    }*/
    while(!esFilaVacia(fila_2)) {
        fila_2 = defila(fila_2);
    }
    /*while(!esFilaVacia(fila_3)) {
        fila_3 = defila(fila_3);
    }*/
    while(!esFilaVacia(fila_concat)) {
        fila_concat = defila(fila_concat);
    }
    while(!esFilaVacia(fila_mostrar)) {
        fila_mostrar = defila(fila_mostrar);
    }

    return 0;
}

// PUNTO 2 - TP6
/*
    Como usuario del ADT Fila diseñe una función recursiva MEZCLAR que, dadas 
    dos filas de enteros ordenadas retorne una fila ordenada que resulta de la 
    combinación de ambas filas. 
*/
Fila mezclar(Fila* _fila_1, Fila* _fila_2) {
    Fila fila_aux = filaVacia();
    fila_aux = mezclarR(_fila_1, _fila_2, fila_aux);
    return fila_aux;
}
Fila mezclarR(Fila* _fila_1, Fila* _fila_2, Fila _fila_aux) {
    if (longitud(*_fila_1) == 0 && longitud(*_fila_2) == 0) {
        return _fila_aux;
    } else {
        if (longitud(*_fila_1) == 0 && longitud(*_fila_2) != 0) {
            return concat(_fila_aux, *_fila_2);
        } else {
            if (longitud(*_fila_1) != 0 && longitud(*_fila_2) == 0) {
                return concat(_fila_aux, *_fila_1);
            } else {
                if (frente(*_fila_1) <= frente(*_fila_2)) {
                    _fila_aux = enfila(_fila_aux, frente(*_fila_1));
                    *_fila_1 = defila(*_fila_1);
                    return mezclarR(_fila_1, _fila_2, _fila_aux);
                } else {
                    _fila_aux = enfila(_fila_aux, frente(*_fila_2));
                    *_fila_2 = defila(*_fila_2);
                    return mezclarR(_fila_1, _fila_2, _fila_aux);
                }   
            }
        }
    }
}