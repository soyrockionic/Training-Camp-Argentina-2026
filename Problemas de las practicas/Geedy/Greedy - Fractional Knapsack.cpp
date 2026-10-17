/*
Problema: Fractional Knapsack

Disponemos de una mochila de capacidad W .
Cada objeto posee
- peso
- valor
A diferencia del problema clasico,
podemos partir los objetos.

Objetivo:
Maximizar el valor total.

Supongamos
Objeto Peso Valor
    A 10 60
    B 20 100
    C 30 120
Capacidad:
    W = 50

Idea Greedy
Ordenar por: "valor, peso" de mayor a menor.

Mientras haya espacio:
    - Tomar el objeto completo.
    - Si no entra, tomar unicamente la fraccion restante.
*/

#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

int main() {
    FIN;

    int n; 
    cin >> n;

    double cap;
    cin >> cap;
    
    vector<pair<int,int>> items(n);
    for(int i=0; i<n; i++) {
        cin >> items[i].first >> items[i].second;
    }

    sort(items.begin(), items.end()
         ,[](const pair<int,int> &a, const pair<int,int> &b){
        return (long long)a.second * b.first > (long long)b.second * a.first;
    });
    
    double ans=0;
    for(auto x: items){
        if(cap >= x.first){
            ans += x.second;
            cap -= x.first;
        }else{
            ans += cap * x.second / x.first;
            break;
        }
    }

    cout << fixed << setprecision(2) << ans << "\n";

    return 0;
}