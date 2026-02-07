#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);
using ll = long long;

void solve() {
    int tt; cin >> tt;
    while (tt--) {
        int n,m,k; cin >> n >> m >> k;
        cout << (n/k) * (m/k) << endl;
    } 
}

signed main() {
    fast_io
    solve();
}