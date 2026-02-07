#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);
using ll = long long;

void solve() {
    int tt; cin >> tt;
    while (tt--) {
        int x, n; cin >> x >> n;
        ll res = 0;
        for (int i = 1; i <= n; i++) res += powl(x,i);
        cout << res << endl;
    } 
}

signed main() {
    fast_io
    solve();
}