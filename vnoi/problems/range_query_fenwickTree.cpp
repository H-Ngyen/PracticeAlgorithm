#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
// #pragma GCC target("avx2,tune=native")
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);
using ll = long long;

int n;
// const int MAXN = (int)1e8;
vector<ll> bit;
vector<int> a;

void update(int i, int v) { 
    for(; i <= n; i += i & -i) bit[i] += v;
}

ll get(int i) {
    ll res = 0;
    for (; i ; i -= i & -i) res += bit[i];
    return res;
}

ll getSum(int l, int r) {
    return get(r) - get(l - 1);
}

void solve() {
    int T;
    cin >> n >> T;  
    a.assign(n + 5, 0);
    bit.assign(n + 5, 0);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        update(i, a[i]);
    }

    while (T--) {
        int type;
        ll x, y;
        cin >> type >> x >> y;
        if (type == 1) {
            update(x, y - a[x]);
            a[x] = y;
        }
        else cout << getSum(x, y) << '\n';
    }
}

signed main() {
    fast_io
    solve();
    // cout << log(MAXN) << endl;
}