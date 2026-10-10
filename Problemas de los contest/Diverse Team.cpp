/*
Problema C del contest 1 del Training Camp Argentina 2026

https://codeforces.com/group/GHvtTrfZFd/contest/705664/problem/C

C - Diverse Team

Hay n estudiantes en una clase; la puntuacion del i-esimo estudiante en Codehorses es *aᵢ*. Debes
formar un equipo de k estudiantes (1 <= k <= n) de manera que las puntuaciones de todos los
miembros del equipo sean distintas.

Si es imposible formar un equipo adecuado, imprime "NO" (sin comillas). De lo contrario, imprime "YES" y,
a continuacion, imprime k numeros distintos que correspondan a los indices de los estudiantes del equipo
que formes. Si existen varias respuestas posibles, imprime cualquiera de ellas.

Input
La primera linea contiene dos enteros n y k (1 <= k <= n <= 100): el numero de estudiantes y el tamaño del
equipo que debes formar.

La segunda linea contiene n enteros a1, a2, …, an (1 <= ai <= 100), donde ai es la puntuacion del i-esimo
estudiante.

Output
Si es imposible formar un equipo adecuado, imprime "NO" (sin comillas). De lo contrario, imprime "YES" y,
a continuacion, imprime k enteros distintos del 1 al n que correspondan a los indices de los estudiantes
del equipo que formes. Todas las calificaciones de los estudiantes del equipo deben ser distintas. Puedes
imprimir los indices en cualquier orden. Si existen varias respuestas posibles, imprime cualquiera de ellas.

Supon que los estudiantes estan numerados del 1 al n.

Ejemplo
Entrada
5 3
15 13 15 15 12
Salida
YES
1 2 5

Entrada
5 4
15 13 15 15 12
Salida
NO

Entrada
4 4
20 10 40 30
Salida
YES
1 2 3 4

Nota
Todas las posibles respuestas para el primer ejemplo:

- {1 2 5}
- {2 3 5}
- {2 4 5}

Tenga en cuenta que el orden no importa.
*/

#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

int main() {
    FIN;
    
    int n, k;
    cin >> n >> k;
    
    /*
    set<int> a;
    */
    unordered_set<int> a;
    vector<int> posiciones;
    
    for (int i=0; i<n; i++) {
        
        int e;
        cin >> e;
        
        if (a.insert(e).second) {
            posiciones.push_back(i+1);
            if (posiciones.size() == k) 
                break;
        }
            
    }
    
    if (a.size() >= k) {
        cout << "YES" << "\n";
        for (int i=0; i<k; i++)
            cout << posiciones[i] << " ";
        cout << "\n";
        /*
        for (const auto& e : a) {
            cout << e << " ";
        }
        */
    }
    else
        cout << "NO" << "\n";
    
    return 0;
}