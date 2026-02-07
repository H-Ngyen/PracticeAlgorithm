#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
// #pragma GCC target("avx2,tune=native")
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);
using ll = long long;

void solve() {
    int T; cin >> T;
    while (T--) {
        int n, m, cnt = 0; cin >> n >> m;
        while(n && m) {
            if(n < m) {
                m = (m + 1) / 2;
                n--;
            }
            else if (n > m) {
                n = (n + 1) / 2 ;
                m--;
            }
            else {
                n--;
                m = (m + 1) / 2;
            }
            cnt++;
        }
        cout << cnt + n + m << endl;
    }
}

signed main() {
    fast_io
    solve();
    // cout << (1 >> 1) << endl;
}
