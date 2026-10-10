/*
Problema N del contest 3 del Training Camp Argentina 2026

https://codeforces.com/group/GHvtTrfZFd/contest/706413/problem/N

N - Little Elephant and Problem

El Pequeño Elefante tiene un problema: alguien ha manipulado su arreglo a de longitud n (que estaba
ordenado de forma no decreciente) y posiblemente ha intercambiado algunos de sus elementos.

El Pequeño Elefante no quiere llamar a la policia hasta averiguar si el mismo pudo haber modificado
el arreglo accidentalmente. Considera que solo pudo haber alterado el arreglo a por error si este puede
ordenarse mediante, a lo sumo, una operacion de intercambio de elementos (no necesariamente
adyacentes). Es decir, el Pequeño Elefante podria haber intercambiado accidentalmente dos elementos
cualesquiera.

Ayuda al Pequeño Elefante a determinar si el mismo pudo haber modificado accidentalmente el arreglo a
(que estaba ordenado de forma no decreciente).

Input
La primera linea contiene un unico numero entero n (2 <= n <= 10^5), que representa el tamaño del arreglo a.
La siguiente linea contiene n numeros enteros positivos, separados por espacios y que no superan los 10^9,
que representan el arreglo a.

Cabe destacar que los elementos del arreglo no son necesariamente numeros distintos.

Output
Imprime en una sola linea "YES" (sin las comillas) si el Pequeño Elefante podria haber modificado
accidentalmente el arreglo por sí mismo, y "NO" (sin las comillas) en caso contrario.

Ejemplo
Entrada
2
1 2
Salida
YES

Entrada
3
3 2 1
Salida
YES

Entrada
4
4 3 2 1
Salida
NO

Nota
En el primer ejemplo, el array ya esta ordenado, por lo que para ordenarlo, necesitamos 0 operaciones
de intercambio, es decir, no mas de 1. Por lo tanto, la respuesta es "YES".

En el segundo ejemplo, podemos ordenar el array intercambiando los elementos 1 y 3, por lo que
necesitamos 1 operacion de intercambio para ordenarlo. Por lo tanto, la respuesta es "YES".

En el tercer ejemplo, no podemos ordenar el array con mas de una operacion de intercambio, por lo que
la respuesta es "NO".
*/

#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

int main() {
    FIN;
    
    int n;
    cin >> n;
    
    vector<int> a(n);
    
    for (int i=0; i<n; i++)
        cin >> a[i];
        
    vector<int> aux = a;
    
    sort(aux.begin(), aux.end());
    
    int diferencias = 0;
    
    for (int j=0; j<n; j++) {
        if (a[j] != aux[j]) {
            diferencias++;
            if (diferencias > 2)
                break;
        }
    }
    
    if (diferencias > 2)
        cout << "NO" << "\n";
    else
        cout << "YES" << "\n";
    
    return 0;
}