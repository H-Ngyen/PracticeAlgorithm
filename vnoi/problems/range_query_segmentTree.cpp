#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);
using ll = long long;

const int MAXN = (int)2 * 1e5 + 5;
ll seg[MAXN * 4], a[MAXN]; 
void build(int u, int l, int r) {
    if(l == r) seg[u] = a[l];
    else {
        int m = l + (r - l) / 2;
        build(2 * u, l, m);
        build(2 * u + 1, m + 1, r);
        seg[u] = seg[2 * u] + seg[2 * u + 1];
    }
}

void update(int u, int l, int r, int pos, int val) {
    if(l == r) seg[u] = val;
    else {
        int m = l + (r - l) / 2;
        if(pos <= m) update(2 * u, l, m, pos, val);
        else update(2 * u + 1, m + 1, r, pos, val);
        seg[u] = seg[2 * u] + seg[2 * u + 1];
    }
}

ll query(int u, int )

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    build(1, 0, n - 1);
    for(int i = 1; i <= 15; i++) cout << seg[i] << ' ';
}

signed main() {
    fast_io
    solve();
}