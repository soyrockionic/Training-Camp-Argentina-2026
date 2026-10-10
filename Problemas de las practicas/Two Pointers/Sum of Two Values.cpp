#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

/*https://cses.fi/problemset/task/1640*/

bool twoSum(vector<pair<int, int>>& a, int x, int &li, int &ri) {
    sort(a.begin(), a.end());
    int i = 0, j = (int)a.size()-1;
    while (i < j) {
        int s = a[i].first + a[j].first;
        if (s == x) {
           li = a[i].second;
           ri = a[j].second;
            return true;
        } else if (s < x) {
            i++;
        } else {
            j--;
        }
    }
    return false;
}
 
int main() {
    FIN;

    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i].first;
        a[i].second = i+1;
    }

    int ini, fin = 0;

    if(twoSum(a,x,ini,fin))
        cout << ini << " " << fin << "\n";
    else
        cout << "IMPOSSIBLE" << "\n";

    return 0;
}
