#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
// #pragma GCC target("avx2,tune=native")
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);
using ll = long long;

const int MOD = (int)1e9 + 7;

ll powll(ll a, ll b) {
    ll res = 1;
    while(b){
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

ll inv(ll n) { return powll(n, MOD - 2); }

void solve() {
    // cout << 7 * powl(1, MOD - 2) << endl;
    // cout << (1 * inv(2) + 1 * inv(4) + 1 * inv(8) + 7 * inv(8)) % MOD << endl;
    // cout << 77LL * powll(8, MOD - 2) % MOD << endl;
    // cout << isPrime(77);
    cout << 77 % 7 << endl;
}

signed main() {
    fast_io
    solve();
}