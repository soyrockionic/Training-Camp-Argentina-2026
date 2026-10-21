/*
Sum of Three Values

Se te proporciona un arreglo de n numeros enteros, y tu tarea consiste en encontrar tres valores
(en posiciones distintas) cuya suma sea x.

Input
La primera linea de entrada contiene dos enteros, n y x: el tamaño del arreglo y la suma objetivo.

La segunda linea contiene n enteros, a1, a2, ..., an: los valores del arreglo.

Output
Imprime tres numeros enteros: las posiciones de los valores. Si existen varias soluciones, puedes
imprimir cualquiera de ellas. Si no hay ninguna solucion, imprime IMPOSSIBLE.

Restricciones
- 1 <= n <= 5000
- 1 <= xi, ai <= 10^9

Ejemplo

Entrada:
4 8
2 7 5 1
Salida:
1 3 4
*/

#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

int main() {
    FIN;

    int n;
    long long x;
    cin >> n >> x;

    vector<pair<long long, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {     
        long long falta = x - a[i].first;    
        int l = i + 1;
        int r = n - 1;
        while (l < r) {
            long long sum = a[l].first + a[r].first;
            if (sum == falta) {
                cout << a[i].second << " " << a[l].second << " " << a[r].second << "\n";
                return 0;
            } else if (sum < falta) {
                l++;
            } else {
                r--;
            }
        }
    }

    cout << "IMPOSSIBLE" << "\n";

    return 0;
}