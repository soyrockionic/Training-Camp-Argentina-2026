/*
Problema L del contest 3 del Training Camp Argentina 2026

L - Kefa and First Steps

https://codeforces.com/group/GHvtTrfZFd/contest/706413/problem/L

Kefa decidio ganar dinero haciendo negocios en Internet durante exactamente n dias. Sabe que
en el dia i (1 <= i <= n) gana ai dinero. A Kefa le encanta el progreso, por lo que quiere conocer
la longitud del subsegmento no decreciente mas largo de la secuencia ai. Recordemos que un
subsegmento de una secuencia es un fragmento continuo de la misma. Se dice que un subsegmento
de numeros es no decreciente si todos los numeros que lo componen siguen un orden no decreciente.

Ayuda a Kefa a afrontar esta tarea!

Input
La primera linea contiene el entero n (1 <= n <= 10^5).

La segunda linea contiene n enteros a1, a2, ..., an (1 <= ai <= 10^9).

Output
Imprime un unico entero: la longitud del subsegmento no decreciente maximo de la secuencia a.

Ejemplo
Entrada
6
2 2 1 3 4 1
Salida
3

Entrada
3
2 2 9
Salida
3

Nota:
En la primera prueba, el subsegmento no decreciente maximo esta formado por los numeros desde
el tercero hasta el quinto.

En la segunda prueba, el subsegmento no decreciente maximo esta formado por los numeros desde
el primero hasta el tercero.
*/

#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
 
void ventanaDeslizante (vector <int> &a, int &iR, int &jR) {
    int n = a.size();
    if (n == 0) return;
 
    int lon_max = 1;
    int lon_actual = 1;
    int inicio_actual = 0;
    
    for (int i = 1; i < n; i++) {
        if (a[i] >= a[i-1]) {
            lon_actual++;
        } else {
            lon_actual = 1;
            inicio_actual = i;
        }
 
        if (lon_actual > lon_max) {
            lon_max = lon_actual;
            iR = inicio_actual;
            jR = i;             
        }
    }
}
 
int main() {
    FIN;
 
    int n;
    cin >> n;
 
    vector<int> a(n);
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    
    int ini = 0;
    int fin = 0;
 
    ventanaDeslizante(a, ini, fin);
    
    /*for (int i=ini; i<=fin; i++) {
       cout << a[i] << " ";
    }
    
    cout << "\n";*/
 
    cout << fin - ini + 1 << "\n";
 
    return 0;
}