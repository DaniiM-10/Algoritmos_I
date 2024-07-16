#include <iostream>
#include <string.h>
#include "Pila.h"

using namespace std;

Pila eliminarNegativos(Pila* _pila);
void convertir (char _infija[]);
int prioridad (char _c);

int main () {
    // CREO UNA PILA VACIA
    /*Pila pila;
    pila = pilaVacia();
    cout << "Creo una pila vacia!" << endl;

    // CONSULTO SI LA PILA ESTA VACIA O NO
    cout << "\nLa pila esta vacia?: " << (esPilaVacia(pila) ? "Si, está vacia" : "No, no está vacia") << endl;

    // CARGO DATOS A LA PILA
    cout << "\nCargo datos a la pila!" << endl;
    pila = push(pila, 1);
    pila = push(pila, 2);
    pila = push(pila, 3);
    pila = push(pila, 4);

    // CONSULTO SI LA PILA ESTA VACIA O NO
    cout << "\nLa pila esta vacia?: " << (esPilaVacia(pila) ? "Si, está vacia" : "No, no está vacia") << endl;

    // PIDO EL TOPE DE LA PILA
    cout << "\nEl tope de la pila es: " << top(pila) << endl;

    // MUESTRO TODA LA PILA
    cout << "\nMuestro la pila: " << endl;
    Pila pila_aux = pila;
    while (!esPilaVacia(pila_aux)) {
        cout << top(pila_aux) << endl;
        pila_aux.cabecera = pila_aux.cabecera->siguiente;
    }

    // ELIMINO EL TOPE DE LA PILA
    cout << "\nElimino el tope de la pila!" << endl;
    pila = pop(pila);

    // MUESTRO TODA LA PILA
    cout << "\nMuestro la pila: " << endl;
    pila_aux = pila;
    while (!esPilaVacia(pila_aux)) {
        cout << top(pila_aux) << endl;
        pila_aux.cabecera = pila_aux.cabecera->siguiente;
    }

    // CONSULTO LA ALTURA DE LA PILA
    cout << "\nLa altura de la pila es: " << altura(pila) << endl;

    // CREO UNA PILA 2 VACIA
    Pila pila_2;
    pila_2 = pilaVacia();
    cout << "\nCreo una pila 2 vacia!" << endl;

    // CONSULTO SI LA PILA 2 ESTA VACIA O NO
    cout << "\nLa pila 2 esta vacia?: " << (esPilaVacia(pila_2) ? "Si, está vacia" : "No, no está vacia") << endl;

    // CARGO DATOS A LA PILA 2
    cout << "\nCargo datos a la pila 2!" << endl;
    pila_2 = push(pila_2, 1);
    pila_2 = push(pila_2, 2);
    pila_2 = push(pila_2, 3);

    // MUESTRO TODA LA PILA 2
    cout << "\nMuestro la pila 2: " << endl;
    pila_aux = pila_2;
    while (!esPilaVacia(pila_aux)) {
        cout << top(pila_aux) << endl;
        pila_aux.cabecera = pila_aux.cabecera->siguiente;
    }    

    // COMPARO 2 PILAS
    cout << "\nLa pila 1 y pila 2 son iguales? " << (igualP(pila, pila_2) ? "Si, son iguales" : "No, no son iguales") << endl;

    // MUESTRO TODA LA PILA
    cout << "\nMuestro la pila: " << endl;
    pila_aux = pila;
    while (!esPilaVacia(pila_aux)) {
        cout << top(pila_aux) << endl;
        pila_aux.cabecera = pila_aux.cabecera->siguiente;
    }   

    // MUESTRO TODA LA PILA 2 Y BORRO TODOS SUS NODOS
    cout << "\nMuestro la pila 2 y borro todos los nodos: " << endl;
    while (!esPilaVacia(pila_2)) {
        cout << top(pila_2) << endl;
        pila_2 = pop(pila_2);
    }

    // CARGO DATOS A LA PILA 2
    cout << "\nCargo datos a la pila 2!" << endl;
    pila_2 = push(pila_2, 4);
    pila_2 = push(pila_2, 5);
    pila_2 = push(pila_2, 6);

    // MUESTRO TODA LA PILA 2
    cout << "\nMuestro la pila 2: " << endl;
    pila_aux = pila_2;
    while (!esPilaVacia(pila_aux)) {
        cout << top(pila_aux) << endl;
        pila_aux.cabecera = pila_aux.cabecera->siguiente;
    } 

    // APILO LA PILA 2 SOBRE LA PILA 1
    cout << "\nApilo la pila 2 sobre la pila 1!" << endl;
    Pila pila_apilada = pilaVacia();
    pila_apilada = apila(pila, pila_2);

    // MUESTRO TODA LA PILA APILADA
    cout << "\nMuestro la pila apilada: " << endl;
    pila_aux = pila_apilada;
    while (!esPilaVacia(pila_aux)) {
        cout << top(pila_aux) << endl;
        pila_aux.cabecera = pila_aux.cabecera->siguiente;
    } 

    // MUESTRO TODA LA PILA
    cout << "\nMuestro la pila: " << endl;
    pila_aux = pila;
    while (!esPilaVacia(pila_aux)) {
        cout << top(pila_aux) << endl;
        pila_aux.cabecera = pila_aux.cabecera->siguiente;
    }   

    // MUESTRO TODA LA PILA 2
    cout << "\nMuestro la pila 2: " << endl;
    pila_aux = pila_2;
    while (!esPilaVacia(pila_aux)) {
        cout << top(pila_aux) << endl;
        pila_aux.cabecera = pila_aux.cabecera->siguiente;
    }
    
    // CARGO DATOS A LA PILA
    cout << "\nCargo datos a la pila!" << endl;
    pila = pilaVacia();
    pila = push(pila, -41);
    pila = push(pila, -1);
    pila = push(pila, 87);
    pila = push(pila, -3);
    pila = push(pila, 0);
    pila = push(pila, 1);

    // MUESTRO TODA LA PILA
    cout << "\nMuestro la pila: " << endl;
    pila_aux = pila;
    while (!esPilaVacia(pila_aux)) {
        cout << top(pila_aux) << endl;
        pila_aux.cabecera = pila_aux.cabecera->siguiente;
    }  

    // ELIMINO LOS NUMEROS NEGATIVOS QUE SE ENCUENTREN EN LA PILA
    cout << "\nElimino los numeros negativos que se encuentren en la pila!" << endl;
    pila = eliminarNegativos(&pila);

    // MUESTRO TODA LA PILA
    cout << "\nMuestro la pila: " << endl;
    pila_aux = pila;
    while (!esPilaVacia(pila_aux)) {
        cout << top(pila_aux) << endl;
        pila_aux.cabecera = pila_aux.cabecera->siguiente;
    }  

    // LIBERO MEMORIA
    cout << "\nLibero la memoria reservada en forma dinamica" << endl;
    while(!esPilaVacia(pila)) {
        pila = pop(pila);
    }
    while(!esPilaVacia(pila_2)) {
        pila_2 = pop(pila_2);
    }
    while(!esPilaVacia(pila_aux)) {
        pila_aux = pop(pila_aux);
    }
    while(!esPilaVacia(pila_apilada)) {
        pila_apilada = pop(pila_apilada);
    }
    */
    // --------------------------------------- INFIJA A POSFIJA ---------------------------------------------
    char infija[] = "(a+(~b-c))";
    strcat(infija, "=");
    convertir(infija);

    return 0;
}

// PUNTO 1-b) - TP5
/*
    Como usuario del ADT diseñe una función recursiva eliminarNegativos que dada una 
    pila de números enteros elimine de la pila todos los elementos negativos y retorne la 
    pila resultante. 
*/
Pila eliminarNegativos(Pila* _pila) {
    if (esPilaVacia(*_pila)) {
        return *_pila;
    } else {
        item tope = top(*_pila);
        Pila temp = pop(*_pila);
        return (tope < 0) 
            ? eliminarNegativos(&temp)
            : push(eliminarNegativos(&temp), tope);
    }
}

// PUNTO 3 - TP5
/*
    Como usuario del ADT PILA escriba el algoritmo para CONVERTIR una expresión 
    aritmética dada en notación infija a una expresión en notación posfija*. El proceso de convertir 
    acepta una expresión infija como entrada y produce una expresión posfija como salida. 
    Considere expresiones bien formadas que tengan variables (de la ‘a’ a la ‘z’), operadores 
    binarios (+, -, *, /), el operador unario (~) y paréntesis terminadas por la marca final '='. La idea 
    es utilizar una pila para almacenar los operadores a medida que son encontrados para más 
    tarde desapilar estos operadores de acuerdo a su precedencia.
*/
void convertir (char _infija[]) {
    int i = 0;
    Pila pila = pilaVacia();

    do {
        if ((_infija[i] >= 65 && _infija[i] <= 90) || (_infija[i] >= 97 && _infija[i] <= 122)) {
            cout << _infija[i];
        } else {
            if (_infija[i] == '(' || _infija[i] == '[' || _infija[i] == '{') {
                pila = push(pila, _infija[i]);
            } else {
                if (_infija[i] == ')' || _infija[i] == ']' || _infija[i] == '}') {
                    if (_infija[i] == ')') {
                        while (top(pila) != '(') {
                            string str(1, static_cast<char>(top(pila)));
                            cout << str;
                            pila = pop(pila);
                        }
                        pila = pop(pila);
                    }
                    if (_infija[i] == ']') {
                        while (top(pila) != '[') {
                            string str(1, static_cast<char>(top(pila)));
                            cout << str;
                            pila = pop(pila);
                        }
                        pila = pop(pila);
                    }
                    if (_infija[i] == '}') {
                        while (top(pila) != '{') {
                            string str(1, static_cast<char>(top(pila)));
                            cout << str;
                            pila = pop(pila);
                        }
                        pila = pop(pila);
                    }
                } else {
                    if (prioridad(_infija[i]) > prioridad(top(pila))) { 
                        pila = push(pila, _infija[i]);
                    } else {
                        while (prioridad(_infija[i]) <= prioridad(top(pila)) && !esPilaVacia(pila)) {
                            string str(1, static_cast<char>(top(pila))); // Pasa codigo ascii a char
                            cout << str;
                            pila = pop(pila);
                        }
                        i--;
                    }
                }
            }
        }

        i++;
    } while (_infija[i] != '=' || !esPilaVacia(pila));
}

int prioridad (char _c) {
    switch (_c){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '~':
            return 3;
        default:
            return -1;
    };
}