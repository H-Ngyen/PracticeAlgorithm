#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
// #pragma GCC target("avx2,tune=native")
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);
using ll = long long;

void solve() {
    int T; cin >> T;
    while(T--) {
        int n, k; cin >> n >> k;
        if (n > k) {
            cout << -1 << endl;
            continue;
        } 
        for(int i = 0 ; i < n - 1; i++) cout << 1 << ' ';
        cout << k - (n - 1) << endl;
    }
}

signed main() {
    fast_io
    solve();
}