/*
Problema E del contest 7 del Training Camp Argentina 2026

https://codeforces.com/group/GHvtTrfZFd/contest/707556/problem/E

E - BerSU Ball

¡La Universidad Estatal de Berland organiza un baile de salon para celebrar su 100.500.º aniversario!
n chicos y m chicas ya estan ocupados ensayando pasos de vals, minueto, polonesa y cuadrilla.

Sabemos que varias parejas formadas por un chico y una chica seran invitadas al baile. Sin embargo,
la diferencia entre las habilidades de baile de los integrantes de cada pareja debe ser, como maximo,
de un punto.

Conocemos la habilidad de baile de cada chico y, de igual manera, la de cada chica. Escribe un codigo
que determine el mayor numero posible de parejas que se pueden formar a partir de n chicos y m chicas.

Input
La primera linea contiene un entero n (1 <= n <= 100): el numero de chicos. La segunda linea contiene
la secuencia a1, a2, ..., an (1 <= ai <= 100), donde ai es la habilidad de baile del i-esimo chico.

De manera similar, la tercera linea contiene un entero m (1 <= m <= 100): el numero de chicas. La cuarta
linea contiene la secuencia b1, b2, ..., bm (1 <= bj <= 100), donde bj es la habilidad de baile de la j-esima
chica.

Output
Imprime un unico numero: el numero maximo posible de pares requerido.

Ejemplo

Entrada
4
1 4 6 2
5
5 1 5 7 9
Salida
3

Entrada
4
1 2 3 4
4
10 11 12 13
Salida
0

Entrada
5
1 1 1 1 1
3
1 2 3
Salida
2
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
        
    int m;
    cin >> m;
    
    vector<int> b(m);
    for (int j=0; j<m; j++)
        cin >> b[j];
        
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int par=0, i=0, j=0;
 
    while (i<n && j<m) {
        if (abs(a[i] - b[j]) <= 1) {
            par++;
            i++;
            j++;
        }
        else if (a[i] > b[j])
            j++;
        else
            i++;
            
    }
    
    cout << par << "\n";
    
    return 0;
}