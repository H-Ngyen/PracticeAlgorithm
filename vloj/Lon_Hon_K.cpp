#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("avx2,tune=native")
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);
using ll = long long;

void solve() {
    int T; cin >> T;
    while (T--) {
        ll n, k, cnt = 0; cin >> n >> k;
        if(n == 0) cnt = (0 >= k);
        while(n) {
            if(n % 10 >= k) cnt++;
            n /= 10;
        }
        cout << cnt << endl;
    }
}

signed main() {
    fast_io
    solve();
}
