#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O2")
#define fast_io ios_base::sync_with_stdio(0); cout.tie(NULL); cin.tie(NULL);
using ll = long long;

const int MOD =  (int)1e9 + 7;
const int MAXN = (int)1e4 + 5;
unordered_map<int, int> m;

ll C(ll n) { return 1LL * n * (n - 1) / 2; }

void solve() {
    int n; cin >> n;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        m[x]++;
    } 

    for(auto &p:m) 
        if(p.second >= 2) ans = (1LL * ans + C(p.second)) % MOD;
    
    cout << ans << endl;
}

signed main() {
    fast_io
    solve();
}