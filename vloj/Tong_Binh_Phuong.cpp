#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
// #pragma GCC target("avx2,tune=native")
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);
using ll = long long;

void solve() {
    int T; cin >> T;
    while(T--) {
        int a, b; cin >> a >> b;
        ll ans = 0;
        for (int i = a; i <= b; i++) ans += powl(i , 2); 
        cout << ans << endl;
    }
}

signed main() {
    fast_io
    solve();
}
