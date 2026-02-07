#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);

void solve() {
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        cout << n * (n + 1) / 2 << endl;
    }    
}

signed main() {
    fast_io
    solve();
}