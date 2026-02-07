#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
// #pragma GCC optimize("O2,unroll-loops,no-stack-protector")
// #pragma GCC target("avx2,tune=native")
#define fast_io ios_base::sync_with_stdio(0); cout.tie(nullptr); cin.tie(nullptr);
using ll = long long;

struct Dog {
    int w, iq, v;
};

bool cmp (const Dog &a, const Dog &b) {
    if(a.w != b.w) return a.w < b.w;
    return a.iq < b.iq;
}

void solve() {
    int n; cin >> n;
    vector<Dog> a(n); 
    for (int i = 0; i < n; i++) {
        int w, iq, v; cin >> w >> iq >> v;
        a[i] = {w, iq, v};
    }
    
    vector<ll> f(n);
    ll res = 0;
    sort(a.begin(), a.end(), cmp);
    
    for (int i = 0; i < n; i++) {
        int v = a[i].v;
        f[i] = v;
        for (int j = 0; j < i; j++) {
            if (a[i].iq >= a[j].iq) f[i] = max(f[i], f[j] + v);
        }
        res = max(res, f[i]);
    }   
    cout << res << endl;
}

signed main() {
    fast_io
    solve();
}