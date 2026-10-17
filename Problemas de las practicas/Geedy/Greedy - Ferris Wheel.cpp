/*
Problema: Ferris Wheel

Enunciado
- Hay n personas con pesos wi.
- Cada gondola soporta como maximo x kilos.
- En cada gondola pueden viajar una o dos personas.

Objetivo
Minimizar la cantidad de gondolas utilizadas.

Idea Greedy
1 - Ordenar los pesos.
2 - Mantener dos punteros.
3 - Intentar emparejar el mas liviano con el mas pesado.

Entrada:
4 10
7 2 3 9
Salida:
3
*/

#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

int main() {
    FIN;

    int n, x;
    cin >> n >> x;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    int l = 0;
    int r = n - 1;
    int ans = 0;

    while (l <= r) {
        if (v[l] + v[r] <= x)
            l++;
        r--;
        ans++;
    }

    cout << ans << "\n";

    return 0;
}