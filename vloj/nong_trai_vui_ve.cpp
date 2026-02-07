#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
// #pragma GCC target("avx2,tune=native")
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);
using ll = long long;

void solve() {
    int T; cin >> T;
    while (T--) {
        int n, m, p, c; cin >> n >> m;
        if(m & 1 || m < 2 * n || m > 4 * n || (m - 2 * n) & 1) {
            cout << -1 << endl;
            continue;
        } 
        int f = ((m - 2 * n) >> 1);
        int t = n - f;
        if(t < 0) cout << -1 << endl;
        else cout << --f << ' ' << t << ' ' << 1 << endl; 
    }
}

signed main() {
    fast_io
    solve();
    // cout << 14 % 5 << endl;
}