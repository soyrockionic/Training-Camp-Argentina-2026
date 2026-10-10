#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

/*https://cses.fi/problemset/task/1646*/

int main () {
    FIN;

    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    vector<long long> b(n+1);

    for (int i=0; i<n; i++)
        cin >> a[i];

    b[0] = 0;
    for (int i=1; i<=n; i++)
        b[i] = b[i-1] + a[i-1];

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << b[r] - b[l-1] << "\n";
    }
    
    return 0;
}