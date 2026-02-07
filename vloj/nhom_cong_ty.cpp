#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);
using ll = long long;

void solve() {
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        ll res = 0;
        for (ll i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                res += i;
                if (n / i != i) res += n / i;
            }
        }
        cout << res << endl;
    }    
}

signed main() {
    fast_io
    solve();
}