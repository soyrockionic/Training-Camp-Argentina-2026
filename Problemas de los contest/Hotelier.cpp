/*
Problema B del contest 5 del Training Camp Argentina 2026

https://codeforces.com/group/GHvtTrfZFd/contest/707082/problem/B

B - Hotelier

Amugae tiene un hotel que consta de 10 habitaciones. Las habitaciones estan numeradas del 0 al 9,
de izquierda a derecha.

El hotel tiene dos entradas: una en el extremo izquierdo y otra en el extremo derecho. Cuando un cliente
llega al hotel por la entrada izquierda, se le asigna la habitacion vacia mas cercana a dicha entrada. Del
mismo modo, cuando un cliente llega por la entrada derecha, se le asigna la habitacion vacia mas cercana
a esa entrada.

Un dia, Amugae perdio la lista de asignacion de habitaciones. Afortunadamente, su memoria es perfecta
y recuerda todos los detalles sobre los clientes: cuando llegaron, por que entrada lo hicieron y cuando se
marcharon. Inicialmente, el hotel estaba vacio. Escribe un programa que reconstruya la lista de asignacion
de habitaciones a partir de la memoria de Amugae.

Input
La primera linea contiene un entero n (1 <= n <= 10^5), que representa el numero de eventos en la memoria
de Amugae.

La segunda linea contiene una cadena de longitud n que describe los eventos en orden cronologico. Cada
caracter representa lo siguiente:

- 'L': Un cliente llega por la entrada izquierda.
- 'R': Un cliente llega por la entrada derecha.
- '0', '1', ..., '9': El cliente de la habitacion x (0, 1, ..., 9, respectivamente) se marcha.

Se garantiza que hay al menos una habitacion vacia cuando llega un cliente, y que hay un cliente en la
habitacion x cuando se indica x (0, 1, ..., 9). Ademas, todas las habitaciones estan vacias inicialmente.

Output
En la unica linea, muestra el estado de asignacion de las habitaciones del hotel, de la habitacion 0 a la 9.
Representa una habitacion vacia con 0 y una ocupada con 1, sin espacios.

Ejemplos
Entrada
8
LLRL1RL1
Salida
1010000011

Entrada
9
L0L0LLRR9
Salida
1100000010

Nota
En el primer ejemplo, el estado de asignacion de las habitaciones del hotel tras cada accion es el 
siguiente:

- En primer lugar, todas las habitaciones estan vacias. El estado de asignacion es 0000000000.
- L: un cliente llega al hotel por la entrada izquierda. El estado de asignacion es 1000000000.
- L: otro cliente llega por la entrada izquierda. El estado de asignacion es 1100000000.
- R: otro cliente llega por la entrada derecha. El estado de asignacion es 1100000001.
- L: otro cliente llega por la entrada izquierda. El estado de asignacion es 1110000001.
- 1: el cliente de la habitacion 1 se marcha. El estado de asignacion es 1010000001.
- R: otro cliente llega por la entrada derecha. El estado de asignacion es 1010000011.
- L: otro cliente llega por la entrada izquierda. El estado de asignacion es 1110000011.
- 1: el cliente de la habitacion 1 se marcha. El estado de asignacion es 1010000011.

Por tanto, el estado final de asignacion de las habitaciones del hotel es 1010000011.

En el segundo ejemplo, el estado de asignacion de las habitaciones del hotel tras cada accion es el
siguiente:

- L: un cliente llega al hotel por la entrada izquierda. El estado de asignacion es 1000000000.
- 0: el cliente de la habitacion 0 se marcha. El estado de asignacion es 0000000000.
- L: un cliente llega al hotel por la entrada izquierda. El estado de asignacion vuelve a ser 1000000000.
- 0: el cliente de la habitacion 0 se marcha. El estado de asignacion es 0000000000.
- L: un cliente llega al hotel por la entrada izquierda. El estado de asignacion es 1000000000.
- L: otro cliente llega por la entrada izquierda. El estado de asignacion es 1100000000.
- R: otro cliente llega por la entrada derecha. El estado de asignacion es 1100000001.
- R: otro cliente llega por la entrada derecha. El estado de asignacion es 1100000011.
- 9: el cliente de la habitacion 9 se marcha. El estado de asignacion es 1100000010.

Por tanto, el estado final de asignacion de las habitaciones del hotel es 1100000010.
*/

#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
 
int main() {
    FIN;
    
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    vector<int> x(10);
    
    for (int i=0; i<(int)s.length(); i++) {
        if (s[i] == 'L') {
            for (int i=0; i<10; i++) {
                if (x[i] == 0) {
                    x[i] = 1;
                    break;
                }
            }
        }
        else if (s[i] == 'R') {
            for (int i=9; i>=0; i--) {
                if (x[i] == 0) {
                    x[i] =1;
                    break;
                }
            }
        }
        else {
            int room = s[i] - '0';
            x[room] = 0;
        }
    }
    
    for (int i=0; i<10; i++)
        cout << x[i];
        
    cout << "\n";
 
    return 0;
}