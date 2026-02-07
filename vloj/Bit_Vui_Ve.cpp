#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);
using ll = long long;

void solve() {
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        cout << (unsigned long long)powl(2LL,n) << endl;
    }
}

signed main() {
    fast_io
    solve();
}