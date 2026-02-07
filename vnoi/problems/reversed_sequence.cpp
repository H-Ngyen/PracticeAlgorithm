#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
// #pragma GCC target("avx2,tune=native")
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);

const int MAXN = (int)6 * 1e4;

// solution: fenwick tree
// O(nlogn)
int f[MAXN + 5];
void solve2() {
    int n, u, ans = 0;
    cin >> n;
    while (n--) {
        cin >> u;
        for (int i = u + 1; i <= MAXN; i += i &-i) ans += f[i];
        for (int i = u ; i ; i -= i&-i) f[i]++;
    }
    cout << ans << endl;
}

// solution: brute forces
// O(n^2)
int a[MAXN];
void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if(a[i] > a[j]) cnt++;        
        }
    }
    
    cout << cnt << endl;
}

signed main() {
    fast_io
    solve2();
}