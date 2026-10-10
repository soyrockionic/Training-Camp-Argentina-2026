/*
Problema A del contest 3 del Training Camp Argentina 2026

https://codeforces.com/group/GHvtTrfZFd/contest/706413/problem/A

A - Hexadecimal's theorem

Recientemente, un virus caotico llamado Hexadecimal ha propuesto un nuevo teorema que sacudira
el universo. Ella sostiene que cualquier numero de Fibonacci puede expresarse como la suma de tres
numeros de Fibonacci (no necesariamente distintos).

Recordemos como se calculan los numeros de Fibonacci: F0 = 0, F1 = 1, y todos los numeros siguientes
siguen la formula Fi = Fi-2 + Fi-1.

Asi, los numeros de Fibonacci forman la siguiente secuencia: 0, 1, 1, 2, 3, 5, 8, 13...

Si no has huido aterrorizado de tu ordenador, debes ayudar al virus. Tu tarea consiste en descomponer
un numero de Fibonacci dado, n, en la suma de tres numeros de Fibonacci (no necesariamente distintos)
o bien determinar que tal descomposicion es imposible.

Input
La entrada consta de un unico entero n (0 <= n < 10^9), el numero que debe representarse segun las reglas
descritas anteriormente. Se garantiza que n es un numero de Fibonacci.

Output
Imprime los tres numeros requeridos: a, b y c. Si no hay respuesta para la prueba, imprime "Soy demasiado
tonto para resolver este problema" (sin las comillas).

Si hay varias respuestas, imprime cualquiera de ellas.

Ejemplos
Entrada
3
Salida
1 1 1

Entrada
13
Salida
2 3 8
*/

#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

const int MAX = 45;

int main() {
    FIN;
    
    long long n;
    cin >> n;
    
    vector<long long> f(MAX);

    f[0]=0;
    f[1]=1;
        
    for (int i=2; i<MAX; i++) {
        f[i] = f[i-2] + f[i-1];
    }
    
    for (int i = 0; i<MAX; i++) {
        if (f[i] == n) {
            if (i == 0) {
                cout << 0 << " " << 0 << " " << 0 << "\n";
            } else if (i == 1) {
                cout << 1 << " " << 0 << " " << 0 << "\n";
            } else {
                cout << f[i-2] << " " << f[i-2] << " " << f[i-3] << "\n";
            }
            break;
        }
    }
    
    return 0;
}