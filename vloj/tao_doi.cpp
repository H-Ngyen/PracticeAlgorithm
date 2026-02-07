#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
// #pragma GCC target("avx2,tune=native")
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);
using ll = long long;

void solve() {
    int T; cin >> T;
    while (T--) {
        int n, ans = 0; cin >> n;
        unordered_map<int, int> hm;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            hm[x]++;
        } 
        for(auto &[x, cnt]:hm) ans += cnt / 3;
        cout << ans << endl;
    }
}

signed main() {
    fast_io
    solve();
}