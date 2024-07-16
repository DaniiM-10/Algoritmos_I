#include <iostream>
#include <string.h>
#include "LC.h"

using namespace std;

int main () {
    // CREAMOS UNA LC VACIA
    cout << "\nCreamos una LC vacia!" << endl;
    LC lc = lcVacia();

    // VERIFICAMOS QUE LA LC ESTE VACIA
    cout << "\nLa LC esta vacia? " << (esLcVacia(lc) ? "Si" : "No") << endl;

    // INSERTAMOS 3 NODOS A LA LC
    cout << "\nInsertamos 3 nodos a la LC!" << endl;
    lc = lcInsertar(lc, 1);
    lc = lcInsertar(lc, 2);
    lc = lcInsertar(lc, 3);

    // VERIFICAMOS QUE LA LC ESTE VACIA
    cout << "\nLa LC esta vacia? " << (esLcVacia(lc) ? "Si" : "No") << endl;

    // MOSTRAMOS EL VALOR QUE ESTA EN LA VENTANA DE LA LC
    cout << "\nEl valor que esta en la ventana de la LC es: " << lcValor(lc) << endl;

    // BORRAMOS UN NODO DE LA LC
    //cout << "\nBorramos un nodo de la LC!" << endl;
    //lc = lcBorrar(lc);

    // MOSTRAMOS EL VALOR QUE ESTA EN LA VENTANA DE LA LC
    cout << "\nEl valor que esta en la ventana de la LC es: " << lcValor(lc) << endl;

    // INSERTAMOS 3 NODOS A LA LC
    cout << "\nInsertamos 3 nodos a la LC!" << endl;
    lc = lcInsertar(lc, 4);
    lc = lcInsertar(lc, 5);
    lc = lcInsertar(lc, 6);
    lc = lcInsertar(lc, 4);
    lc = lcInsertar(lc, 2);

    // MOSTRAMOS EL VALOR QUE ESTA EN LA VENTANA DE LA LC
    cout << "\nEl valor que esta en la ventana de la LC es: " << lcValor(lc) << endl;

    // ROTAMOS LA LC UNA VEZ
    //cout << "\nRotamos la LC una vez!" << endl;
    //lc = lcRotar(lc);

    // MOSTRAMOS EL VALOR QUE ESTA EN LA VENTANA DE LA LC
    cout << "\nEl valor que esta en la ventana de la LC es: " << lcValor(lc) << endl;

    // UNIMOS 2 LC
    /*cout << "\nUnimos 2 LC!" << endl;
    LC lc_2 = lcVacia();
    lc_2 = lcInsertar(lc_2, 7);
    lc_2 = lcInsertar(lc_2, 8);
    lc_2 = lcInsertar(lc_2, 9);

    LC lc_aux = lcVacia();
    //lc_aux = lcUnir(lc, lc_2, lc_2.longitud);*/

    // ROTAMOS n LUGARES LA LC
    //cout << "\nRotamos 3 lugares la LC!" << endl;
    //lc = lcRotarN(lc, 3);
    
    // MOSTRAMOS EL VALOR QUE ESTA EN LA VENTANA DE LA LC
    //cout << "\nEl valor que esta en la ventana de la LC es (3): " << lcValor(lc) << endl;

    // CONTAMOS LA CANTIDAD DE 2 QUE HAY EN LA LC
    cout << "\nLa cantidad de 2 que hay en la LC es: " << to_string(lcContarK(lc, 4)) << endl;

    return 0;
}