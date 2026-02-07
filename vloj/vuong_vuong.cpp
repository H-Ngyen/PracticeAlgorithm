#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
// #pragma GCC target("avx2,tune=native")
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);
using ll = long long;

void solve() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        if(n == 0) cout << 0 << endl;
        else if(n <= 4) cout << (n == 4 ? 4 : 1) << endl;
        else {
            n = n / 4 + 1;
            cout << 1LL * n * n << endl;
        }
    }
}

signed main() {
    fast_io
    solve();
    // cout << 12 / 4 << endl;
}