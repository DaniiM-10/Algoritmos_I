#include <iostream>
using namespace std;
#include "ejercicios.h"  //Include del archivo de cabecera Lista.h - Tipificacion de lista y funciones 

int main(){ 
    int p1 = inversoR(6803);
    cout << p1 << endl;

    int p3a = iterativo(176);
    cout << "iterarivo: " << p3a << endl;
    int p3b = recursiva(149256);
    cout << "recursivo: " << p3b << endl;

    int tam4 = 9;
    char v4[tam4] = {'r', 'e', 'c', 'o', 'n', 'o', 'c', 'e', 'r'};
    bool p4 = palindromo(v4, 0, tam4-1);
    cout << "Palindromo: " << (p4 ? "True" : "False") << endl;

    int tam5 = 5;
    int  v5[]= {1, 2, 7, 6, 9};
    bool p5 = ordenR(v5, tam5-1);
    cout << "nordenR : " << (p5 ? "True" : "False") << endl;

    return 0;
}