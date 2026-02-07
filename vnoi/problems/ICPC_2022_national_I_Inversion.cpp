#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);
using ll = long long;

ll fac(ll n) {
    ll res = 1;
    for (int i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

ll C(ll n, ll k) {
    if(n < k) return 0;
    return fac(n) / (fac(k) * fac(n - k));
}

void solve() {
    int T; cin >> T;
    const int MAXN = (int)(1LL * T * (T - 1)) / 2;
    vector<int> a(MAXN);
    while (T--) {
        for (int i = 0; i < MAXN; i++) {
            for (int j = 0; j < MAXN; j++) {
                cin >> a[i];
            }
        }

    }
}

signed main() {
    fast_io
    // solve();
    cout << C(4,3) << endl;
    cout << C(2,2);
    // cout << fac(2);
}