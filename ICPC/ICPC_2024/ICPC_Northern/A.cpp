#include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
// #pragma GCC optimize("O2,unroll-loops,no-stack-protector")
// #pragma GCC target("avx2,tune=native")
#define fast_io ios::sync_with_stdio(0); cout.tie(NULL); cin.tie(NULL);
using ll = long long;

const int INF = (int)1e9;
const int MAXN = (int) 1e4 + 5;
int a[MAXN];
int f[MAXN];

void solve () {
    int n, d, h; cin >> n >> d >> h;
    for (int i = 0; i < n; i++) cin >> a[i];

    f[0] = a[0];
    for (int i = 1; i < n; i++) {
        f[i] = INF;
        for (int j = i - 1; j >= 0; j--) {
            if(i - j > d) break;
            if(abs(a[i] - a[j]) <= h) f[i] = min(f[i], f[j] + a[i]);      
        }
    }
    cout << (f[n - 1] == INF ? -1 : f[n - 1]) << endl;
}

signed main () {
    fast_io
    solve();
}