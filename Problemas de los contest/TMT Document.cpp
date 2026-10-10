/*
Problema C del contest 6 del Training Camp Argentina 2026

https://codeforces.com/group/GHvtTrfZFd/contest/707360/problem/C

C - TMT Document

El consejo estudiantil tiene un archivo de documento compartido. Diariamente, algunos miembros
del consejo escriben la secuencia TMT (abreviatura de Towa Maji Tenshi).

Sin embargo, un dia, los miembros introdujeron la secuencia en el documento simultaneamente,
creando un desorden total. Por lo tanto, Suguru Doujima tiene la tarea de averiguar si el documento
ha sufrido algun fallo. Especificamente, se le proporciona una cadena de longitud n

cuyos caracteres son todos T o M, y debe determinar si es posible dividirla en varias subsecuencias 
disjuntas, todas iguales a TMT. Es decir, cada caracter de la cadena debe pertenecer a una unica
subsecuencia.

Una cadena a es una subsecuencia de una cadena b si a se puede obtener de b eliminando varios
caracteres (posiblemente, ninguno).

Input
La primera linea contiene un entero t (1 <= t <= 5000) -> el numero de casos de prueba.

La primera linea de cada caso de prueba contiene un entero n (3 <= n < 10^5), el numero de caracteres
de la cadena introducida en el documento. Se garantiza que n es divisible por 3.

La segunda linea de cada caso de prueba contiene una cadena de longitud n compuesta unicamente
por los caracteres T y M.

Se garantiza que la suma de n en todos los casos de prueba no supera 10^5.

Output
Para cada caso de prueba, imprima una unica linea que contenga YES si existe la particion descrita,
y una unica linea que contenga NO en caso contrario.

Ejemplo
Entrada
5
3
TMT
3
MTT
6
TMTMTT
6
TMTTTT
6
TTMMTT
Salida
YES
NO
YES
NO
YES

Nota
En el primer caso de prueba, la propia cadena ya es una secuencia igual a TMT.

En el 3er caso de prueba, podemos dividir la cadena en las subsecuencias TM TMT T. Tanto la subsecuencia
en negrita como la que no lo esta son iguales a TMT.
*/

#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

int main() {
    FIN;
    
    int t;
    cin >> t;
    
    while (t--) {
        
        int n;
        cin >> n;
        
        string cadena;
        cin >> cadena;

        int T = 0, M = 0;
        bool existe = true;

        for (int i = 0; i < n; i++) {
            if (cadena[i] == 'T')
                T++;
            else
                M++;
                
            if (M > T) {
                existe = false;
                break;
            }
        }
        
        if (T != M * 2) {
            existe = false;
        }
        
        int revT = 0, revM = 0;
        
        for (int i = n - 1; i >= 0; i--) {
            if (cadena[i] == 'T')
                revT++;
            else
                revM++;
         
            if (revM > revT) {
                existe = false;
                break;
            }
        }

        if (existe) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}