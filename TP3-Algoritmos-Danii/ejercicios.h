#include <iostream>
#include <math.h>
using namespace std;

// PUNTO 2
int inversoR(int n) {
    if (n <= 0) {
        return 0;
    } else {
        int pos = (int)round(pow(10, (int)log10(n) + 1)); // Obtengo el próximo número de la base 10
        // cout << (int)log10(n) + 1 << pos << endl; // Comentado para depuración
        // cout << n % 10 << endl; // Comentado para depuración
        return ((n % 10) * pos) + inversoR(n / 10); // retorno con el último dígito multiplicado por el próximo y sumando los demás recursivamente
    }
}


// PUNTO 3
int iterativo (int n) {
    int max=0, mod=0;

    if (n <= 0) {
        return 0;
    } else {
        while (n > 0) {
            mod = n%10;
            if (max < mod) {
                max = mod;
            }
            n = n/10;  
        }
    }
    return max;
}

int recursiva (int n) {
    if (n <= 0) {
        return 0;
    } else {
        if (n%10 > recursiva(n/10)) {
            return n%10;
        } else {
            return recursiva(n/10);
        }
        
    }
    
}

// PUNTO 4
bool palindromo (char v[], int i, int n) {
    if (i <= n/2) {
        if (v[i] != v[n]) {
            return false;
        } else {
            return palindromo(v, i+1, n-1);
        }
    } else {
        return true;
    }
}

// PUNTO 5
bool ordenR (int v[], int n) {
    if (n <= 0) {
        return true;
    } else {
        if (!(v[n] >= v[n-1])) {
            return false;
        } else {
            return ordenR(v, n-1);
        }
    }
}

