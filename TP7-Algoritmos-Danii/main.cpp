#include <iostream>
#include "AB.h" // Asegúrate de incluir tu archivo AB.h

int main() {
    AB arbol_prueba = ABVacio();

    // Utilizar la función ESABVACIO
    std::cout << "El arbol esta vacio? " << (esABVacio(arbol_prueba) ? "Si" : "No") << std::endl;

    // Utilizar la función RAIZ
    std::cout << "\nRaiz del arbol: " << raiz(arbol_prueba) << std::endl;

    // Crear los nodos hoja del nivel más bajo
    AB hoja1 = armarAB(NULL, 4, NULL); // Nodo con valor 4
    AB hoja2 = armarAB(NULL, 5, NULL); // Nodo con valor 5
    AB hoja3 = armarAB(NULL, 6, NULL); // Nodo con valor 6
    AB hoja4 = armarAB(NULL, 7, NULL); // Nodo con valor 7

    // Crear los nodos del segundo nivel
    AB nodo2_1 = armarAB(hoja1, 2, hoja2); // Nodo con valor 2 y hojas 4, 5
    AB nodo2_2 = armarAB(hoja3, 3, hoja4); // Nodo con valor 3 y hojas 6, 7

    // Crear el nodo raíz del árbol con valor 1 y subárboles nodo2_1 y nodo2_2
    AB arbol = armarAB(nodo2_1, 1, nodo2_2);

    // Ahora tienes un árbol binario de 3 niveles con la estructura:
    //        1
    //       / \
    //      2   3
    //     /\   /\
    //    4  5 6  7


    // Utilizar la función ESABVACIO
    std::cout << "\nEl arbol esta vacio? " << (esABVacio(arbol) ? "Si" : "No") << std::endl;

    // Utilizar la función IZQUIERDO
    AB subarbolIzquierdo = izquierdo(arbol);
    std::cout << "\nRaiz del subarbol izquierdo: " << raiz(subarbolIzquierdo) << std::endl;

    // Utilizar la función RAIZ
    std::cout << "\nRaiz del arbol: " << raiz(arbol) << std::endl;

    // Utilizar la función DERECHO
    AB subarbolDerecho = derecho(arbol);
    std::cout << "\nRaiz del subarbol derecho: " << raiz(subarbolDerecho) << std::endl;

    // Utilizar la función PERTENECE
    item valorBuscado = 8;
    std::cout << "\nEl valor " << valorBuscado << " pertenece al arbol? " << (pertenece(arbol, valorBuscado) ? "Si" : "No") << std::endl;
    valorBuscado = 4;
    std::cout << "\nEl valor " << valorBuscado << " pertenece al arbol? " << (pertenece(arbol, valorBuscado) ? "Si" : "No") << std::endl;

    return 0;
}