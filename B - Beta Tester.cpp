/*
https://codeforces.com/gym/106420/problem/B => UTPC Contest 3-11-26 (Beginner)

B - Beta Tester

Innersloth esa desarrollando un nuevo mapa para Among Us ¡y te ha invitado a participar como
beta tester! Este nuevo mapa cuenta con un sistema de conductos experimental. A diferencia de
las redes de conductos interconectados tradicionales, estos nuevos conductos son de sentido unico.
Una vez que un Impostor entra en un conducto en una sala, aparece en una sala de destino específica
y no puede regresar a traves del mismo conducto.

Juegas como el Impostor y comienzas la partida en la Sala 1. Teniendo en cuenta la disposicion de
las salas y los conductos de ventilacion, determina cuantas salas distintas (incluida aquella en la que
empiezas) puedes visitar utilizando alguna secuencia de conductos.

Input
La primera linea de entrada contendra 2 enteros, n y m (1 <= n <= 2 * 10^5, 0 <= m <= 2 * 10^5$),
separados por un espacio: el numero de habitaciones en el mapa y el numero de conductos de
ventilacion unidireccionales, respectivamente.

Las siguientes m lineas de entrada contendran cada una dos enteros, ui y vi (1 <= ui, vi <= n), separados
por un espacio, que representan un conducto de ventilacion unidireccional que permite desplazarse
desde la habitacion ui hasta la habitacin vi.

Output
Emite un unico numero entero: el numero total de habitaciones distintas accesibles desde la habitacion 1.

Ejemplo
Entrada
6 5
1 2
2 3
1 4
5 6
3 2
Salida
4

Nota
Explicacion: Partiendo de la Sala 1, puedes utilizar los conductos de ventilacion para desplazarte a la
Sala 2 y a la Sala 4. Desde la Sala 2, puedes ir a la Sala 3. Desde la Sala 3, puedes regresar a la Sala 2.
No existe ninguna secuencia de conductos que lleve a la Sala 5 o a la Sala 6 desde la Sala 1. Por lo tanto,
puedes llegar a 4 salas distintas: 1, 2, 3 y 4.
*/

#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

const int MAX=200007;

vector<int> adj[MAX];
bool visited[MAX];
int cont=0;

void dfs (int current) {
    if (visited[current])
        return;
        
    visited[current] = true;
    
    //cout << current << "\n";
    
    cont++;
    
    for (int nb : adj[current]) {
        dfs(nb);
    }
}

int main() {
    FIN;

    int n, m;
    cin >> n >> m;
    
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    dfs(1);
    
    cout << cont << "\n";

    return 0;
}


#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
 
const int MAXIMO = 200005;
 
vector<int> adj[MAXIMO];
bool visitados[MAXIMO];
 
/*
1 - Encolar al inicio
2 - Marcar visitado
3 - Mientras la cola no este vacia
    A - Sacar frente, recorrer vecinos
    B - Sino esta visitado: marcar y encolar
*/
 
void bfs(int current) {
    queue<int> nxt;
    nxt.push(current);
    visitados[current] = true;
    //cout << current << "\n";
    int cont = 1;
    
    while (!nxt.empty()) {
        current = nxt.front();
        nxt.pop();
        
        for (int nb : adj[current]) {
            if (!visitados[nb]) {
                visitados[nb] = true;
                nxt.push(nb);
                //cout << nb << "\n";
                cont ++;
            }
        }
    }
    cout << cont << "\n";
}
 
 
int main() {
    FIN;
    
    int n, m; cin >> n >> m;
    
    for (int i=0; i<m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        //adj[v].push_back(u);
    }
    
    bfs(1);
    
    return 0;
}