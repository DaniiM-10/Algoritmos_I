#include <iostream>
#include "Fila.h";
#include "LC.h";

using namespace std;

Fila invertirFila (Fila* _fila);
Fila invertirFilaIt (Fila* _fila, LC* _lc_aux);

int main () {
    // INICIALIZO UNA FILA
    Fila fila = filaVacia();

    // INSERTO 5 DATOS A LA FILA
    fila = enfila(fila, 1);
    fila = enfila(fila, 2);
    fila = enfila(fila, 3);
    fila = enfila(fila, 4);
    fila = enfila(fila, 5);

    // MUESTRO LA FILA ANTES DE INVERTIRLA
    cout << "\nMostramos la fila: " << endl;
    Fila fila_aux = fila;
    while (fila_aux.frente != nullptr) {
        cout << frente(fila_aux) << endl;
        fila_aux.frente = fila_aux.frente->siguiente;
    }

    // INVIERTO LA FILA (REVISAAAAAAAAAAAAAR)
    cout << "\nInvierto la fila!" << endl;
    Fila fila_inv = invertirFila(&fila);
    cout << frente(fila_inv) << endl;

    // MUESTRO LA FILA ANTES DE INVERTIRLA
    cout << "\nMostramos la fila 3: " << endl;
    fila_aux = fila_inv;
    while (fila_aux.frente != nullptr) {
        cout << frente(fila_aux) << endl;
        fila_aux.frente = fila_aux.frente->siguiente;
    }

    return 0;
}

// PUNTO 5 - TP6 | NO FUNCA, NOSE PORQUE :{
/*
    Como usuario de los ADT LC y ADT FILA diseñe una función iterativa 
    INVERTIRFILA que utilice una LC para invertir una fila.
*/
Fila invertirFila (Fila* _fila) {
    LC lc_aux = lcVacia();
    Fila fila_inv = filaVacia();

    fila_inv = invertirFilaIt(_fila, &lc_aux);

    return fila_inv;
}

Fila invertirFilaIt (Fila* _fila, LC* _lc_aux) {
    while (!esFilaVacia(*_fila)) {
        *_lc_aux = lcInsertar(*_lc_aux, frente(*_fila));
        *_fila = defila(*_fila);
    }
    while (!esLcVacia(*_lc_aux)) {
        *_fila = enfila(*_fila, lcValor(*_lc_aux));
        *_lc_aux = lcBorrar(*_lc_aux);
    }

    return *_fila;
}