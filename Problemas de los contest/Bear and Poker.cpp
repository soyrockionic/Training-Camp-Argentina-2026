/*
Problema C del contest 5 del Training Camp Argentina 2026

https://codeforces.com/group/GHvtTrfZFd/contest/707082/problem/C

C - Bear and Poker

Limak es un viejo oso pardo. A menudo juega al poquer con sus amigos. Hoy han ido a un casino.
Hay n jugadores (incluido el propio Limak) y, en este momento, todos tienen apuestas sobre la mesa.
El jugador i-esimo ha apostado una cantidad de ai dolares.

Cada jugador puede duplicar su apuesta tantas veces como quiera y triplicar su apuesta tantas veces
como quiera. El casino ofrece un gran premio acumulado por igualar todas las apuestas. ¿Es posible
que Limak y sus amigos ganen el premio acumulado?

Input
La primera linea de la entrada contiene un entero n (2 <= n <= 10^5), el numero de jugadores.

La segunda linea contiene n numeros enteros a1, a2, ..., an (1 <= ai <= 10^9): las ofertas de los
jugadores.

Output
Imprime "Yes" (sin las comillas) si los jugadores pueden igualar sus apuestas, o "No" en caso contrario.

Ejemplo
Entrada
4
75 150 75 50
Salida
Yes

Entrada
3
100 150 250

Nota
En la primera prueba de muestra, el primer y el tercer jugador deben duplicar sus pujas dos veces,
el segundo jugador debe duplicar la suya una vez y el cuarto jugador debe duplicarla y triplicarla.

Se puede demostrar que en la segunda prueba de muestra no hay manera de que todas las pujas
sean iguales.
*/

#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
 
int quitarDosYTres(int n) {
    while (n % 2 == 0)
        n /= 2;
    while (n % 3 == 0)
        n /= 3;
    return n;
}
 
int main() {
    FIN;
    
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int base = quitarDosYTres(a[0]);
    bool posible = true;
    
    for (int i = 1; i < n; i++) {
        if (quitarDosYTres(a[i]) != base) {
            posible = false;
            break;
        }
    }
    
    if (posible)
        cout << "YES" << "\n";
    else
        cout << "NO" << "\n";
        
    return 0;
}