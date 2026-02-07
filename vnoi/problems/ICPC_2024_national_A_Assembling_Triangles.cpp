#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
// #pragma GCC target("avx2,tune=native")
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);
using ll = long long;

void solve() {
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        map<int,int> tria;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            tria[x]++;
        }

        ll res = 0, sum = 0;
        for (auto &[x, cnt] : tria) {
            if(cnt >= 3) res += 1LL * cnt * (cnt - 1) * (cnt - 2) / 6;
            if(cnt >= 2) res += 1LL * cnt * (cnt - 1) / 2 * sum;
            sum += cnt;
        }
        cout << res << endl;
    }
}

signed main() {
    fast_io
    solve();
}