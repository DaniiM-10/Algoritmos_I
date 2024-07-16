#include <iostream>
#include "AB.h" // Asegúrate de incluir tu archivo AB.h
#include <string.h>
#include <string>
#include <conio.h>
#define MAX 26

using namespace std;

void posFrsMenores (double _afr[], int& _posI, int& _posD);
void arrABLetras (AB* _a, char _letras[]);
void recorrerPreorden(AB nodo);
string* listado(AB a);
void listadoAux(AB a, char arre[], int *cont, std::string codigos[]);

int main() {
    // ENTRADA
    AB a[MAX];
    double afr[MAX] ={0.110845, 0.010895, 0.048778, 0.049769, 0.133336, 
			  0.007965, 0.011638, 0.006108, 0.077790, 0.002889, 
       			  0.000083, 0.053524, 0.026494, 0.073580, 0.093925, 
			  0.026700, 0.008625, 0.061571, 0.079605, 0.051378, 
			  0.041887, 0.009698, 0.000041, 0.001940, 0.008336, 
			  0.002600};
    char letras[MAX] ={ 'a', 'b','c','d','e','f','g','h','i','j','k','l','m',
                    'n','o','p','q','r','s','t','u','v','w','x','y','z'};
    
    // VARIABLES
    AB izq, der;
    int posI=0, posD=0;

    // ARMAR ARREGLO DE ARBOLES CON LAS LETRAS
    arrABLetras(a, letras);

    for (int i = 0; i < MAX-1; i++) {
        posFrsMenores(afr, posI, posD);

        izq = a[posI];
        der = a[posD];
        a[posI] = armarAB(izq, '*', der);
        a[posD] = ABVacio();
        afr[posI] = afr[posI] + afr[posD];
        afr[posD] = 100;
    } 

    cout << "\nRecorremos en arbol en preorden: " << endl;
    recorrerPreorden(a[posI]);
    string* codigos = listado(a[posI]);
    
    cout << "\nMostramos los codigos para cada letra: " << endl;
    for (int i = 0; i < 26; ++i) {
        if (codigos[i] != "") { 
            cout << "Codigo para el caracter " << char(i + 97) << ": " << codigos[i] << endl;
        }
    }

    return 0;
}

void posFrsMenores (double _afr[], int& _posI, int& _posD) {
    // VARIABLES AUXILIARES
    int vAux = 0;

    _posD = 0;
    _posI = 1;

    if (_afr[_posI] > _afr[_posD]) {
        vAux = _posI;
        _posI = _posD;
        _posD = vAux;
    }

    for (int i = 2; i <= MAX-1; i++) {
        if (_afr[i] < _afr[_posI]) {
            _posD = _posI;
            _posI = i;
        } else {
            if (_afr[i] < _afr[_posD]) {
                _posD = i;
            }
        }
    }
}

void arrABLetras (AB* _a, char _letras[]) {
    for (int i = 0; i < MAX; i++) {
        _a[i] = armarAB(NULL, _letras[i], NULL);
    }
}

void recorrerPreorden(AB nodo) {
    if (esABVacio(nodo)) {
        return; // Caso base: si el nodo es nulo, no hay nada que recorrer
    }

    // Mostrar el valor del nodo
    string str(1, static_cast<char>(raiz(nodo)));
    cout << str << endl;

    // Recorrer el subárbol izquierdo
    recorrerPreorden(izquierdo(nodo));

    // Recorrer el subárbol derecho
    recorrerPreorden(derecho(nodo));
}

string* listado(AB a){
	char arre[20];
	int cont=0;
	string* codigos[26];
	*codigos = new string[26];
	listadoAux(a, arre, &cont, *codigos);

	return *codigos;
}

void listadoAux(AB a, char arre[], int *cont, string codigos[]){
	if(!esABVacio(a))
	{	if(!esABVacio(izquierdo(a))){
		    (*cont)++;
			arre[*cont]='0';
			listadoAux(izquierdo(a),arre, cont, &codigos[0]);
		}

		if(esHoja(a)){
			char car=raiz(a);
			arre[(*cont)+1]='\x0';
			codigos[car-97] = &arre[1];
		}

		if(!esABVacio(derecho(a))){
			(*cont)++;
			arre[*cont]='1';
			listadoAux(derecho(a),arre, cont, &codigos[0]);
		}
		(*cont)--;
	}
}
