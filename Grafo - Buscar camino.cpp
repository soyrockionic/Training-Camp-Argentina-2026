/*
Dado un grafo, encontra un camino desde L hasta R, imprimi su longitud y los nodos que lo componen.

Ejemplo
Entrada
6 5 -> nodos y aristas
1 2
2 3
1 4
5 6
3 2
2 4 -> L y R
Salida
3
2 1 4
*/

#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

const int MAX=200007;

vector<int> adj[MAX];
bool visited[MAX];
int cont=0;

bool dfs (int current, int r, vector<int>& a) {
    if (visited[current])
        return false;
    
    //cout << current << "\n";  

    if (current == r) {
        a.push_back(current);
        return true;
    }

    visited[current] = true;
    a.push_back(current);
    
    for (int nb : adj[current]) {
        if (dfs(nb,r,a))
            return true;
    }

    visited[current] = false;
    a.pop_back();

    return false;
}

int main() {
    FIN;

    int n, m;
    cin >> n >> m;
    
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int l, r;
    cin >> l >> r;
    vector<int>a;
    //dfs(l,r,a);
    
    if (dfs(l,r,a)) {
        cout << a.size() << "\n";
        for (int nb : a)
            cout << nb << " ";
    }
    else
        cout << "No hay camino";
            
    cout << "\n";

    return 0;
}