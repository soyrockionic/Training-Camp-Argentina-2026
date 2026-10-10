#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

/*https://cses.fi/problemset/task/1713*/
 
vector<int> min_prime;
 
void criba(int n) { 
    vector<bool> prime(n+1, true);
    min_prime.resize(n+1, 1); 
    for(int p = 2; p * p <= n; p++){
        if(!prime[p]) continue;
        min_prime[p] = p;
        for(int i = p * p; i <= n; i += p) {
            prime[i] = false;
            if(min_prime[i] == 1) min_prime[i] = p;
        }
    }
    for(int i = 2; i <= n; i++) {
        if(min_prime[i] == 1) min_prime[i] = i;
    }
}
 
vector<pair<int,int>> factorizar(int n) { // O(log n)
    vector<pair<int,int>> fact;
    while(n > 1) {
        int p = min_prime[n], cnt = 0;
        while(n % p == 0) n /= p, cnt++;
        fact.push_back({p, cnt});
    }
    return fact;
}
 
vector<int> findDivisors(int n) { // O(sqrt(n))
    vector<pair<int,int>> fact = factorizar(n);
    vector<int> divisors = {1};
    for(auto [p, cnt] : fact) {
        int sz = divisors.size();
        int x = 1;
        for(int j=0; j<cnt; j++) {
            x *= p;
            for(int i=0; i<sz; i++) {
                divisors.push_back(divisors[i] * x);
            }
        }
    }
    return divisors;
}
 
int main () {
    FIN;
 
    int n; cin >> n;
 
    criba(1000005);
 
    while (n--) {
        int x;
        cin >> x;
        cout << findDivisors(x).size() << "\n";
        /*for (int d : findDivisors(x))
            cout << d << " ";
        cout << "\n";*/
    }
    
    return 0;
}