#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

/*https://cses.fi/problemset/task/1095*/

const int MOD = 1e9 + 7;

int add (int a, int b) { return (a + b) % MOD; }
int sub (int a, int b) { return ((a - b) % MOD + MOD) % MOD; }
int mul (long long a, long long b) { return a * b % MOD; }

int fpow (int a, int b) {
    long long r = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) r = mul (r, a);
        a = mul(a, a);
        b /= 2;
    }
    return r;
}

int main () {
    FIN;

    int n; cin >> n;

    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << fpow(a, b) << "\n";
    }
    
    return 0;
}