#include <iostream>
using namespace std;

#include "Cochera.h"  //Include del archivo de cabecera Cochera.h

bool moverAutos (Cochera* _cochera1, Cochera* _cochera2, int _n);

int main() {
    // Variables Aux
    int libr = 0;
    Cochera cocheraAux;
    Coche ulti;
    bool verific;

    Cochera cochera; // Defino una cochera
    cout << "\nCREO UNA COCHERA VACIA:" << endl;
    cochera = cocheraVacia(12); // Creo una cochera vacia

    cout << cochera.coches << endl;

    // Controlamos si la cochera está vacia y cuanto espacio libre tiene
    cout << "\nCONTROLO SI ESTA VACIA Y LA CANTIDAD DE ESPACIO LIBRE:" << endl;
    cout << (estaVacia(cochera) ? "Esta vacia" : "No esta vacia") << endl;

    libr = libre(cochera);
    cout << ((libr > 0) ? "Tiene espacio libre: "+to_string(libr) : "No tiene espacio libre") << endl;


    // Estacionamos un auto
    cout << "\nESTACIONO UN AUTO!" << endl;
    cochera = estacionar(cochera, 2947);
    cout << cochera.coches->coche << endl;

    // Controlamos si la cochera está vacia y cuanto espacio libre tiene
    cout << "\nCONTROLO SI ESTA VACIA Y LA CANTIDAD DE ESPACIO LIBRE:" << endl;
    cout << (estaVacia(cochera) ? "Esta vacia" : "No esta vacia") << endl;

    libr = libre(cochera);
    (libr > 0) ? cout << "Tiene espacio libre: " << libr << endl : cout << "No tiene espacio libre" << endl;

    // Estacionamos un auto
    cout << "\nESTACIONO UN AUTO!" << endl;
    cochera = estacionar(cochera, 4825);
    cout << cochera.coches->coche << endl;

    cout << "\nMUESTRO LA COCHERA:" << endl;
    cocheraAux = cochera;
    while (cocheraAux.coches != NULL)
    {
        cout << cocheraAux.coches->coche << endl;
        cocheraAux.coches = cocheraAux.coches->siguiente;
    }

    // Controlamos si la cochera está vacia y cuanto espacio libre tiene
    cout << "\nCONTROLO SI ESTA VACIA Y LA CANTIDAD DE ESPACIO LIBRE:" << endl;
    cout << (estaVacia(cochera) ? "Esta vacia" : "No esta vacia") << endl;

    libr = libre(cochera);
    cout << ((libr > 0) ? "Tiene espacio libre: "+to_string(libr) : "No tiene espacio libre") << endl;

    // Quitamos el ultimo auto
    cout << "\nQUITO EL ULTIMO AUTO!" << endl;
    cochera = quitarUltimo(cochera);
    
    cout << "\nMUESTRO LA COCHERA:" << endl;
    cocheraAux = cochera;
    while (cocheraAux.coches != NULL)
    {
        cout << cocheraAux.coches->coche << endl;
        cocheraAux.coches = cocheraAux.coches->siguiente;
    }
    
    // Controlamos si la cochera está vacia y cuanto espacio libre tiene
    cout << "\nCONTROLO SI ESTA VACIA Y LA CANTIDAD DE ESPACIO LIBRE:" << endl;
    cout << (estaVacia(cochera) ? "Esta vacia" : "No esta vacia") << endl;

    libr = libre(cochera);
    cout << ((libr > 0) ? "Tiene espacio libre: "+to_string(libr) : "No tiene espacio libre") << endl;

    // Estacionamos un auto
    cout << "\nESTACIONAMOS ALGUNOS AUTOS!" << endl;
    cochera = estacionar(cochera, 1010);
    cochera = estacionar(cochera, 7531);
    cochera = estacionar(cochera, 5873);
    cochera = estacionar(cochera, 3243);

    cout << "\nMUESTRO LA COCHERA:" << endl;
    cocheraAux = cochera;
    while (cocheraAux.coches != NULL)
    {
        cout << cocheraAux.coches->coche << endl;
        cocheraAux.coches = cocheraAux.coches->siguiente;
    }

    // Controlamos si la cochera está vacia y cuanto espacio libre tiene
    cout << "\nCONTROLO SI ESTA VACIA Y LA CANTIDAD DE ESPACIO LIBRE:" << endl;
    cout << (estaVacia(cochera) ? "Esta vacia" : "No esta vacia") << endl;

    libr = libre(cochera);
    cout << ((libr > 0) ? "Tiene espacio libre: "+to_string(libr) : "No tiene espacio libre") << endl;

    // SACAMOS EL AUTO: 7531
    cout << "\nSALE EL AUTO 7531:" << endl;
    cochera = salir(cochera, 7531);

    cout << "\nMUESTRO LA COCHERA:" << endl;
    cocheraAux = cochera;
    while (cocheraAux.coches != NULL)
    {
        cout << cocheraAux.coches->coche << endl;
        cocheraAux.coches = cocheraAux.coches->siguiente;
    }

    // Controlamos si la cochera está vacia y cuanto espacio libre tiene
    cout << "\nCONTROLO SI ESTA VACIA Y LA CANTIDAD DE ESPACIO LIBRE:" << endl;
    cout << (estaVacia(cochera) ? "Esta vacia" : "No esta vacia") << endl;

    libr = libre(cochera);
    cout << ((libr > 0) ? "Tiene espacio libre: "+to_string(libr) : "No tiene espacio libre") << endl;

    // MUESTRO EL ULTIMO AUTO INGRESADO
    cout << "\nULTIMO AUTO QUE INGRESÓ:" << endl;
    ulti = ultimo(cochera);
    cout << ulti << endl;

    // SACAMOS EL AUTO: 3243
    cout << "\nSALE EL AUTO 3243:" << endl;
    cochera = salir(cochera, 3243);

    // MUESTRO EL ULTIMO AUTO INGRESADO
    cout << "\nULTIMO AUTO QUE INGRESÓ:" << endl;
    ulti = ultimo(cochera);
    cout << ulti << endl;

    // VERIFICO SI UN AUTO ESTÁ EN LA COCHERA
    cout << "\nVERIFICO SI EXISTEN AUTOS EN LA COCHERA:" << endl;
    verific = estacionado(cochera, 1010);
    cout << (verific ? "El auto 1010 está en la cochera" : "El auto 1010 NO está en la cochera") << endl;
    verific = estacionado(cochera, 1011);
    cout << (verific ? "El auto 1011 está en la cochera" : "El auto 1011 NO está en la cochera") << endl;
    verific = estacionado(cochera, 3243);
    cout << (verific ? "El auto 3243 está en la cochera" : "El auto 3243 NO está en la cochera") << endl;

    // MUESTRO LA CAPACIDAD DE LA COCHERA
    cout << "\nLA CAPACIDAD DE LA COCHERA ES DE: " << capacidad(cochera) << " AUTOS." << endl;

    cout << "\nMUESTRO LA COCHERA:" << endl;
    cocheraAux = cochera;
    while (cocheraAux.coches != NULL)
    {
        cout << cocheraAux.coches->coche << endl;
        cocheraAux.coches = cocheraAux.coches->siguiente;
    }

    // ESTACIONAMOS ALGUNOS AUTOS
    cout << "\nESTACIONAMOS ALGUNOS AUTOS!" << endl;
    cochera = estacionar(cochera, 6835);
    cochera = estacionar(cochera, 9483);

    cout << "\nMUESTRO LA COCHERA:" << endl;
    cocheraAux = cochera;
    while (cocheraAux.coches != NULL)
    {
        cout << cocheraAux.coches->coche << endl;
        cocheraAux.coches = cocheraAux.coches->siguiente;
    }

    // MUEVO 3 AUTOS DE UNA COCHERA A OTRA
    Cochera cochera2; // Defino una cochera
    cochera2 = cocheraVacia(15);
    cochera2 = estacionar(cochera2, 1180);
    cochera2 = estacionar(cochera2, 5375);
    cochera2 = estacionar(cochera2, 1274);

    cout << "\nMUESTRO LA COCHERA 2:" << endl;
    cocheraAux = cochera2;
    while (cocheraAux.coches != NULL)
    {
        cout << cocheraAux.coches->coche << endl;
        cocheraAux.coches = cocheraAux.coches->siguiente;
    }

    cout << "\nMUEVO 3 AUTOS DE UNA COCHERA A OTRA: " << (moverAutos(&cochera, &cochera2, 8) ? "Si se movieron" : "No se movieron") << endl;

    cout << "\nMUESTRO LA COCHERA:" << endl;
    cocheraAux = cochera;
    while (cocheraAux.coches != NULL)
    {
        cout << cocheraAux.coches->coche << endl;
        cocheraAux.coches = cocheraAux.coches->siguiente;
    }

    cout << "\nMUESTRO LA COCHERA 2:" << endl;
    cocheraAux = cochera2;
    while (cocheraAux.coches != NULL)
    {
        cout << cocheraAux.coches->coche << endl;
        cocheraAux.coches = cocheraAux.coches->siguiente;
    }
    
    return 0;
}

// PUNTO 2-b) - TP4
/*
    Como usuario del ADT COCHERA escriba una función MOVERAUTOS que, dadas dos 
    cocheras y una cantidad n, mueva los n últimos autos estacionados desde la primera 
    cochera a la segunda si es que la misma tiene espacio disponible. La función debe retornar 
    true se pudo mover los n autos de la primera cochera a la segunda, caso contrario debe 
    retornar falso. 
*/
bool moverAutos (Cochera* _cochera1, Cochera* _cochera2, int _n) {
    if (_n == 0) {
        return true;
    } else {
        if (libre(*_cochera2) == 0 || estaVacia(*_cochera1)) {
            return false;
        } else {
            *_cochera2 = estacionar(*_cochera2, ultimo(*_cochera1));
            *_cochera1 = quitarUltimo(*_cochera1);
            return (moverAutos(_cochera1, _cochera2, _n-1));
        }
    }
}