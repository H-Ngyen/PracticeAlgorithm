#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);
using ll = long long;

void solve() {
    int tt; cin >> tt;
    while(tt--) {
        ll n, r; cin >> n >> r;
        ll res = 0;
        if(n >= 2 && r >=1 ) {
            ll c = n * (n - 1) / 2;
            res += c * r;
        }
        if(n >= 1 && r >= 2) {
            ll c = r * (r - 1) / 2;
            res += c * n;
        }
        cout << res << endl;
    }
}

signed main() {
    fast_io
    solve();
}