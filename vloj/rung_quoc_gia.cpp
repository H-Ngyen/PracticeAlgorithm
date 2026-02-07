#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);
using ll = long long;

void solve() {
    int tt; cin >> tt;
    while (tt--) {
        ll n, k, m; cin >> n >> k >> m;
        ll res1 = n/k;
        ll res2 = n/lcm(m,k);
        cout << res1 << ' ' << res2 << endl;
    } 
}

signed main() {
    fast_io
    solve();
}