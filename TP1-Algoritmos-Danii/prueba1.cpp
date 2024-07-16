//============================================================================
// Name        : TP1-2024.cpp
// Author      : Cristina Werenitzky
// Version     :
// Copyright   : Your copyright notice
// Description : Programa de prueba de Lista Enlazada
//============================================================================

#include <iostream>
#include "Lista.h"  //Include del archivo de cabecera Lista.h - Tipificacion de lista y funciones 

using namespace std;

item posicionK(Lista *_lista, int _k); // Funcion externa - Punto 3) - IMPLEMENTADO

int main(){
    // -- PROGRAMA DE PRUEBA DE LISTA CON FUNCIONES QUE RETORNAN LA LISTA MODIFICADA

    cout << "\nINICIO DEL PROGRAMA DE PRUEBA DE LISTA CON FUNCIONES QUE RETORNAN LA LISTA MODIFICADA" << endl;

    cout << "\n1.Creo una lista, la inicializo en lista vacia y muestro la lista vacia por pantalla: " << endl;
    Lista L;
    L = crearLista();
    mostrar(L);

    cout << "\n2.Pruebo la funcion esListaVacia. Mensaje esperado 'Lista Vacia': " << endl;
    if(esListaVacia(L)) {
        cout << "Lista Vacia" << endl;
    } else {
        cout << "Lista NO Vacia" << endl;
    }
    cout << "\n3.Escribo la cantidad de elementos de una lista vacia (= 0): " << longitud(L) << endl;

    cout << "\n4.Escribo el valor del primer elemento de una lista vacia (= -99999): " << primerElemento(L) << endl;

    cout << "\n5.Inserto el valor 500 en la lista y muestro la lista por pantalla: " << endl;
    L = insertar(L,500);
    mostrar(L);

    cout << "\n6.Pruebo la funci�n esListaVacia. Mensaje esperado 'Lista NO Vacia': " << endl;
    if(esListaVacia(L)) {
        cout << "Lista Vacia" << endl;
    } else {
        cout << "Lista NO Vacia" << endl;
    }

    cout << "\n7.Borro un elemento de la lista y muestro por pantala. Se espera lista vacia: " << endl;
    L = borrar(L);
    mostrar(L);

    cout << "\n8.Inserto 5 elementos (10,17,22,45,74) en la lista y muestro la lista por pantalla: " << endl;
    L = insertar(L,10);
    L = insertar(L,17);
    L = insertar(L,22);
    L = insertar(L,45);
    L = insertar(L,74);
    mostrar(L);

    cout << "\n9.Escribo la cantidad de elementos de la lista (= 5): " << longitud(L) << endl;

    cout << "\n10.Escribo el valor del primer elemento de la lista vacia (= 74): " << primerElemento(L) << endl;

    cout << "\n11.Borro un elemento de la lista y muestro la lista por pantalla: " << endl;
    L = borrar(L);
    mostrar(L);

    cout << "\n12.Busco si pertenece el valor 100 en la lista. Mensaje esperado 'NO Pertenece': " << endl;
    if(pertenece(L, 100)) {
        cout << "Pertenece" << endl;
    } else {
        cout << "NO Pertenece" << endl;
    }

    cout << "\n13.Busco si pertenece el valor 22 en la lista. Mensaje esperado: 'Pertenece': " << endl;

    if(pertenece(L, 22)) {
        cout << "Pertenece" << endl;
    } else {
        cout << "NO Pertenece" << endl;
    }

    cout << "\n14.Inserto el valor 88  en la posici�n 3 y muestro la lista por pantalla: " << endl;
    L = insertarK(L, 88, 3);
    mostrar(L);

    cout << "\n15.Inserto el valor 99  en la posici�n 50 y muestro la lista por pantalla: " << endl;
    L = insertarK(L, 99, 50);
    mostrar(L);

    cout << "\n16.Inserto el valor 0  en la posici�n -10 y muestro la lista por pantalla: " << endl;
    L = insertarK(L, 0, -10);
    mostrar(L);

    cout << "\n17.Inserto el valor 1  en la posici�n 1 y muestro la lista por pantalla: " << endl;
    L = insertarK(L, 1, 1);
    mostrar(L);

    cout << "\n18.Busco el elemento que se encuentra en la posic�n 4 de la lista (= 88):" << posicionK(&L, 4) << endl;

    cout << "\n19.Muestro la lista luego de invocar a la funci�n externa posicionK: " << endl;
    mostrar(L);

    cout << "\n20.Busco el elemento que se encuentra en la posic�n 50 de la lista (= -99999): " << posicionK(&L, 50) << endl;

    cout << "\n21.Muestro la lista luego de invocar a la funci�n externa posicionK: " << endl;
    mostrar(L);

    cout << "\n22.Libero la memoria reservada en forma din�mica\n" << endl;
    while(!esListaVacia(L)) {
        L = borrar(L);
    }

    cout << "\nFIN DEL PROGRAMA DE PRUEBA DE LISTA CON FUNCIONES QUE RETORNA LA LISTA QUE RETORNAN LA LISTA MODIFICADA\n" << endl;

    // -----------------------------------------------------------------------------------------------------------------------

    return 0;
}

// Punto 3 - TP1
/*
  Como usuario de la lista enlazada, implemente una función posiciónK que, dada una lista enlazada de números enteros y 
  un número natural k, retorne el valor del elemento que se encuentra en la posición K de la lista, 
  caso contrario retorna -99999.
*/
// Opcion 1
item posicionK (Lista* _lista, int _k) {
    if (esListaVacia(*_lista) || longitud(*_lista) < _k) {
        return INDEFINIDO;
    }

    for (int i = 1; i < _k; i++) {
        *_lista = borrar(*_lista);
    }

    return primerElemento(*_lista);
}

// Opcion 2
/*item posicionK (Lista* _lista, int _k) {
    for (int i = 1; i < _k; i++) {
        if (esListaVacia(*_lista)) {
          return INDEFINIDO;
        }
        *_lista = borrar(*_lista);
    }

    return primerElemento(*_lista);
}*/