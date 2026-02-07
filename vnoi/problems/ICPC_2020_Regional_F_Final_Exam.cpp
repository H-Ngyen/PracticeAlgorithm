#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
// #pragma GCC optimize("O2,unroll-loops,no-stack-protector")
#pragma GCC target("avx2,tune=native")
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);

const int MAXN = (int)1e3;
char a[MAXN];

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
        if(a[i] == a[i + 1]) cnt++;
    cout << cnt << endl;
}

signed main() {
    fast_io
    solve();
}
