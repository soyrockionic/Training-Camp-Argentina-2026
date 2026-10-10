#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

/*Subarray Sums I => https://cses.fi/problemset/task/1660*/

int subarregloSuma(vector<int> &a, long long x) {
    int n = (int)a.size(), i = 0;
    long long suma = 0;
    int cont = 0;
    for (int j = 0; j < n; j++) {
        suma += a[j];
        while (suma > x && i <= j) {
            suma-= a[i];
            i++;
        }
        if (suma == x) {
            cont++;
         }
    }
    return cont;
}

int main() {
    FIN;

    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    cout << subarregloSuma(a,x) << "\n";

    return 0;
}