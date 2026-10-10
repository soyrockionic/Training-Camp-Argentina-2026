#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

/*https://cses.fi/problemset/task/1647*/

int n;
vector<long long> tree;

long long queryMin(int a, int b) {
    a += n; b += n;
    long long s = LLONG_MAX;
    while (a <= b) {
        if (a % 2 == 1)
            s = min(s, tree[a++]);
        if (b % 2 == 0)
            s = min(s, tree[b--]);
        a /= 2;
        b /= 2;
    }
    return s;
}

void actualizar(int k, int x) {
    k += n;
    tree[k] = x;
    for (k /= 2; k >= 1; k /= 2)
        tree[k] = min(tree[2 * k], tree[2 * k + 1]);
}

int main() {
    FIN;

    int q;
    cin >> n >> q;

    int sz = 1;
    while (sz < n) sz *= 2;

    tree.assign(2 * sz, LLONG_MAX);

    for (int i = 0; i < n; i++)
        cin >> tree[sz + i];

    for (int k = sz - 1; k >= 1; k--)
        tree[k] = min(tree[2 * k], tree[2 * k + 1]);

    n = sz;

    while (q--) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        cout << queryMin(a, b) << "\n";
    }

    return 0;
}