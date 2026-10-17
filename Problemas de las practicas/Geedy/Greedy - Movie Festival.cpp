/*
Problema: Movie Festival

Patron clasico: Planificacion de Intervalos (Interval Scheduling)

Enunciado
- Tienes varias tareas o eventos con un tiempo de inicio y un tiempo de fin.
- Quieres realizar la mayor cantidad de tareas posible sin que se superpongan.

Idea Gredy
- Ordenar las tareas por su tiempo de finalizacion (de menor a mayor).
- Tomar siempre la primera que este disponible.

Entrada:
3
3 5
4 9
5 8
Salida:
2
*/

#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

int main() {
    FIN;

    int n; 
    cin >> n;
    
    vector<pair<int,int>> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i].first >> a[i].second;
    }
        
    sort(a.begin(), a.end(), [](const pair<int,int> &p1, const pair<int,int> &p2){
        return p1.second < p2.second;
    });

    int ans=0;
    int finAct=0;
    for(int i=0; i<n; i++) {
        if (a[i].first >= finAct) {
            ans++;
            finAct = a[i].second;
        }
    }

    cout << ans << "\n";

    return 0;
}