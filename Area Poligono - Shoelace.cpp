#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

/*https://cses.fi/problemset/task/2191*/

int main() {
    FIN;

    int n; cin >> n;

    vector<double> X(n);
    vector<double> Y(n); 

    for (int i=0; i<n; i++) {
        cin >> X[i];
        cin >> Y[i];
    }

    double suma = 0.0;
    for (int i=0; i < n; i++){
        suma = suma + (X[i] * Y[(i+1)%n]) - (X[(i+1)%n] * Y[i]);
    }

    cout << fixed << setprecision(2) << 0.5 * abs(suma) << "\n";

    return 0;
}