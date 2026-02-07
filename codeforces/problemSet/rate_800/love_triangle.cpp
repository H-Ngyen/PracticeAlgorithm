#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O2")
#define fast_io ios::sync_with_stdio(false); cout.tie(nullptr); cin.tie(nullptr);

const int MAXN = 5000;
int f[MAXN];

void solve() {
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        f[i] = x; 
    }
    for(int i = 1; i <= n; i++) {
        if(f[f[f[i]]] == i) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

signed main() {
    fast_io
    solve();
}