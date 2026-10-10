#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

/*https://cses.fi/problemset/task/1716*/
 
const int MOD = 1e9 + 7;
vector<int> fact, invFact;
 
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
 
int modDiv(int a, int b) {
    return mul(a, fpow(b, MOD - 2));
}
 
void init_fact (int n) {
    fact.assign (n+1, 1);
    invFact.assign (n+1, 1);
    for (int i=1; i <= n; i++)
        fact[i] = mul (fact[i-1], i);
    invFact[n] = modDiv (1, fact[n]);
    for (int i=n; i>0; i--)
        invFact[i-1] = mul (invFact[i], i);
}
 
int comb (int n, int k) {
    if (k < 0 || k > n) return 0;
    return mul (fact[n], mul (invFact[k], invFact[n-k]));
}
 
int main () {
    FIN;

    init_fact(2000000);
 
    int n, m;
    cin >> n >> m;
 
    cout << comb(((m+n)-1),(n-1)) << "\n";
    
    return 0;
}