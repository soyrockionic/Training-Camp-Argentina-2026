/*
https://codeforces.com/gym/105321/problem/F => Torneo Argentino de Programacion 2024

F - Fixture

Mati tiene los resultados de los N partidos que jugo durante la ultima liga de tenis virtual, un deporte
individual en el que no existen los empates, lo que significa que en cada partido un jugador gana o
pierde.

La organizacion de la liga siente cierta fascinacion por las rachas, y la forma de obtener la puntuacion
final de un jugador es algo peculiar. Un jugador gana 1 punto por cada partido ganado y pierde 1 punto
por cada partido perdido. Ademas, si tras finalizar un partido el jugador acumula al menos 3 victorias
consecutivas (incluyendo el ultimo partido), recibe un punto adicional.

Puedes ayudar a Mati a calcular cuantos puntos obtuvo?

Input
Una linea con un numero entero N (1 <= N <= 100), que representa la cantidad de partidos que Mati jugo
en la liga de tenis virtual.

Luego, una linea con N numeros R1,R2,…,RN (Ri pertenece {0,1}), donde Ri=0 si Mati perdio el i-esimo
partido en orden cronologico y Ri=1 si Mati gano el i-esimo partido.

Output
Una linea con un numero entero que indica los puntos que Mati obtuvo al finalizar sus partidos en la liga.

Ejemplos

Entrada
8
1 0 1 0 1 0 1 0
Salida
0

Entrada
5
0 0 0 0 0
Salida
-5

Entrada
5
1 1 1 1 1
Salida
8

Entrada
7
1 1 1 0 1 1 1
Salida
7

Nota
En el primer ejemplo, no hay ninguna racha de 3 o mas partidos, y Mati gana y pierde el mismo numero
de partidos, obteniendo 0 puntos.

En el segundo ejemplo, Mati pierde todos los partidos, obteniendo -5 puntos.

En el tercer ejemplo, Mati gana todos los partidos, obteniendo 8 puntos.

En el cuarto ejemplo, Mati obtiene 7 puntos, ya que gana 2 puntos adicionales por los partidos consecutivos
ganados al finalizar el tercer y el septimo partido.
*/

#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
 
int main () {
    FIN;
    
    int n;
    cin >> n;
    
    int puntos=0, cantSeg=0;
    
    for (int i=0; i<n; i++) {
        int res;
        cin >> res;
        if (res == 1) {
            puntos++;
            cantSeg++;
            if (cantSeg == 3) {
                cantSeg--;
                puntos++;
            }
        }
        else {
            puntos--;
            cantSeg = 0;
        }
    }
    
    cout << puntos << "\n";
    
    return 0;
}