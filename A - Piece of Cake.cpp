/*
UTPC Contest 10-14-2026

Problema: A - Piece of Cake -- https://codeforces.com/gym/106764/problem/A

Alice tiene un pastel gigante para su cumpleaños, cortado en n porciones. Como no se le da muy bien
cortar el pastel en partes iguales, cada porcion tiene un tamaño si.

Ademas, Alice tiene m amigos en su fiesta. Cada porcion puede entregarse, como maximo, a un solo amigo,
sin necesidad de dividirla ni combinarla con otra porcion. El amigo i-esimo queda satisfecho si recibe una
porcion con un tamaño de al menos ai.

Alice desea que la mayor cantidad posible de sus amigos queden satisfechos. Determina el numero maximo
de amigos a los que Alice puede dejar satisfechos.

Input
La primera linea contendra los enteros n y m (1 <= n,m <= 10^5).

La segunda linea contiene n enteros s1, s2, …, sn (1 <= si <= 10^9), que representan los tamaños de los trozos.

La tercera linea contiene m enteros a1, a2, …, am (1 <= aj <= 10^9), que representan el tamaño minimo de
trozo que cada amigo esta dispuesto a aceptar.

Ouput
Imprime un unico numero entero: la cantidad maxima de amigos a los que se puede hacer felices.

Ejemplo
Entrada
3 2
10 5 20
15 15
Salida
1
Entrada
3 5
2 2 2
1 1 1 1 1
Salida
3
Entrada
4 1
10 20 30 40
101
Salida
0

Nota
En el primer ejemplo, solo un trozo tiene un tamaño de al menos 15; por lo tanto, solo se puede hacer
feliz a un amigo.

En el segundo ejemplo, solo hay tres trozos, asi que, como maximo, se puede hacer felices a tres amigos.
Dado que cada trozo tiene un tamaño de 2 y cada amigo solo necesita 1, es posible hacer felices a tres
amigos.

En el tercer ejemplo, el trozo mas grande tiene un tamaño de 40, lo cual es menor que el requisito de 101
que necesita el amigo. Por consiguiente, no es posible hacer feliz a ningun amigo.
*/

#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

int main() {
    FIN;

    int n, m;
    cin >> n >> m;
        
    vector<int> s(n);
    vector<int> a(m);

    for (int i = 0; i < n; i++)
        cin >> s[i];

    for (int i = 0; i < m; i++)
        cin >> a[i];

    sort(s.begin(), s.end());
    sort(a.begin(), a.end());

    int r = 0;

    for (int i = 0; i < n; i++) {
        for (int j = r; j < m; j++) {
            if (s[i] >= a[j]) {
                r++;
                break;
            } else
                break;
        }          
        if(r >= m)
            break;                
    }

    cout << r << "\n";
    
    return 0;
}