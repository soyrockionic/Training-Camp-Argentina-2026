/*
Educational Codeforces Round 188 (Rated for Div. 2)

https://codeforces.com/contest/2204/problem/B

Problema: B - Right Maximum

Se te da un arreglo a que consta de n numeros enteros.

Mientras el arreglo no este vacio, se realiza una operacion que consta de dos pasos:

- primero, se elige el elemento maximo del arreglo (si hay varios elementos maximos, se elige el que
  esta mas a la derecha)
- luego, se eliminan del arreglo todos los elementos situados despues del elemento elegido, incluyendolo
  a el mismo.

Tu tarea consiste en calcular el numero de operaciones que se realizaran antes de que el arreglo quede
vacio.

Input
La primera linea contiene un entero t (1 <= t <= 10^4) — el numero de casos de prueba.

Cada caso de prueba consta de dos lineas:

- la primera linea contiene un entero n (2 <= n <= 2*10^5);
- la ​​segunda linea contiene n enteros a1,a2,…,an (1 <= ai <= n).

Restriccion adicional sobre la entrada: la suma de n en todos los casos de prueba no supera 2*10^5.

Output
Para cada caso de prueba, imprime un numero entero: el numero de operaciones que se realizaran.

Ejemplo
Entrada
4
5
2 1 2 3 1
6
1 2 3 4 5 6
3
3 2 1
4
1 3 3 1
Salida
3
6
1
3

Nota
En el primer ejemplo, el arreglo es [2, 1, 2, 3, 1]. Se realizan las siguientes operaciones sobre el:

- primero, se elige el cuarto elemento. Se eliminan los dos ultimos elementos y el arreglo queda
  como [2, 1, 2];
- luego, se elige el tercer elemento. Se elimina el ultimo elemento y el arreglo queda como [2, 1];
- despues, se elige el primer elemento. Se eliminan ambos elementos, por lo que el arreglo queda
  vacio tras 3 operaciones.
*/

#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

int main() {
    FIN;
    
    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int ops = 0;
        int max = -1;

        for (int i = 0; i < n; i++) {
            if (a[i] >= max) {
                max = a[i];
                ops++;
            }
        }
        cout << ops << "\n";
    }
    
    return 0;
}