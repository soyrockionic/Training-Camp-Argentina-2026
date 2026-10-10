/*
Problema I del contest 4 del Training Camp Argentina 2026

https://codeforces.com/group/GHvtTrfZFd/contest/706595/problem/I

I - Coder

A Iahub le gusta mucho el ajedrez. Incluso invento una nueva pieza de ajedrez llamada Coder.
Un Coder puede moverse (y atacar) una casilla en sentido horizontal o vertical. Mas concretamente,
si el Coder se encuentra en la posicion (x, y), puede moverse a (o atacar) las posiciones (x+1, y),
(x–1, y), (x, y+1) y (x, y–1).

Iahub quiere saber el numero maximo de Coders que se pueden colocar en un tablero de ajedrez
de n×n, de modo que ningún Coder ataque a otro.

Input
La primera linea contiene un entero n (1 <= n <= 1000).

Ouput
En la primera linea, imprime un numero entero: el numero maximo de Coders que se pueden colocar
en el tablero de ajedrez.

En cada una de las siguientes n lineas, imprime n caracteres que describan la configuracion de los
Coders. Para una celda vacia imprime un '.', y para un Coder imprime una 'C'.

Si hay varias respuestas correctas, puedes imprimir cualquiera de ellas.

Ejemplos
Entrada
2
Salida
2
C.
.C
*/

#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
 
int main() {
    FIN;  
    int n;
    cin >> n;
    
    if (n % 2 == 0)
        cout << (n*n) / 2 << "\n";
    else
        cout << ((n*n) / 2) + 1 << "\n";
        
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i % 2 == 0)
                if (j % 2 == 0)
                    cout << "C";
                else
                    cout << ".";
            else
                if (j % 2 == 0)
                    cout << ".";
                else
                    cout << "C";
        }
        cout << "\n";
    }
    
    return 0;
}