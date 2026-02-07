#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);
using ll = long long;

const ll MOD = 998'244'353;
vector<ll> a;
void solve() {
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<pair<int,int>> p;
        a.assign(n + 1, 0);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        for (int i = 0; i < n - 1; i++) {
            if(abs(a[i] - a[i + 1]) <= 1) p.push_back(make_pair(a[i], a[i + 1]));
        }
        ll k = p.size();
        ll ans;
        if(k <= 1) {
            ans = 1;
        }
        else {
            int cnt = 0;
            for (int i = 0; i < k - 1; i++) {
                if (p[i].second == p[i + 1].first) cnt++;
            }
            ans = ((1LL * k * (k - 1) / 2) - cnt) % MOD;
        }
        cout << ans << endl;

    }
}

signed main() {
    fast_io
    solve();
}