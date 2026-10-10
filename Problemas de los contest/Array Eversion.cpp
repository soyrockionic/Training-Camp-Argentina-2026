Problema A del contest 4 Training Camp Argentina 2026

https://codeforces.com/group/GHvtTrfZFd/contest/706595/problem/A

A - Array Eversion

Se te da un arreglo a de longitud n.

Definamos la operacion de inversion "eversion". Sea x = an. Entonces, el arreglo a se divide en dos
partes: izquierda y derecha. La parte izquierda contiene los elementos de a que no son mayores que
x (<= x). La parte derecha contiene los elementos de a que son estrictamente mayores que x (> x).
El orden de los elementos en cada parte se mantiene igual que antes de la operacion; es decir, la
particion es estable. Luego, el arreglo se reemplaza por la concatenacion de las partes izquierda y
derecha.

Por ejemplo, si el arreglo a es [2,4,1,5,3], la inversion se realiza asi: [2,4,1,5,3]->[2,1,3],[4,5]->[2,1,3,4,5].

Partimos del arreglo a y realizamos inversiones en el. Podemos demostrar que, tras varias inversiones,
el arreglo a deja de cambiar. Devuelve el numero minimo k tal que el arreglo deja de cambiar despues
de k inversiones.

Input
Cada prueba contiene multiples casos de prueba. La primera linea contiene el numero de casos de
prueba t (1 <= t <= 100). A continuacion, se describen los casos de prueba.

La primera linea contiene un único entero n (1 <= n <= 2*10^5).

La segunda linea contiene n enteros a1, a2, ..., an (1 <= ai <= 10^9).

Se garantiza que la suma de n en todos los casos de prueba no supera 2 * 10^9.

Output
Para cada caso de prueba, imprime un unico entero k — el numero de inversiones tras el cual el arreglo
deja de cambiar.

Ejemplo
Entrada
3
5
2 4 1 5 3
5
5 3 2 4 1
4
1 1 1 1
Salida
1
2
0

Nota
Considera el primer ejemplo.

- La primera inversion: a=[1,4,2,5,3], x=3. [2,4,1,5,3]->[2,1,3],[4,5]->[2,1,3,4,5].
- La segunda inversion y las siguientes: a=[2,1,3,4,5], x=5. [2,1,3,4,5]->[2,1,3,4,5],[]->[2,1,3,4,5]. Esta
  inversion no modifica el arreglo, por lo que la respuesta es 1.

Considera el segundo ejemplo.

- La primera inversion: a=[5,3,2,4,1], x=1. [5,3,2,4,1]->[1],[5,3,2,4]->[1,5,3,2,4].
- La segunda inversion: a=[1,5,3,2,4], x=4. [1,5,3,2,4]->[1,3,2,4],[5]->[1,3,2,4,5].
- La tercera inversion y las siguientes: a=[1,3,2,4,5], x=5. [1,3,2,4,5]->[1,3,2,4,5],[]->[1,3,2,4,5]. Esta inversion
  no modifica el arreglo, por lo que la respuesta es 2.


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
        for (int i = 0; i < n; i++)
            cin >> a[i];
    
        int op = 0;
        int maximo = a[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (a[i] > maximo) {
                op++;
                maximo = a[i];
            }
        }
    
        cout << op << "\n";
    
    }
    
    return 0;
}