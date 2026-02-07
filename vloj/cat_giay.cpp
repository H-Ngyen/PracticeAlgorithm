#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
// #pragma GCC target("avx2,tune=native")
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);
using ll = long long;

const int MOD = (int)1e9+7;
ll powll(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void solve() {
    int T; cin >> T;
    while (T--) {
        ll n; cin >> n;
        cout << powll(2, n) << endl;
    }
}

signed main() {
    fast_io
    solve();
}