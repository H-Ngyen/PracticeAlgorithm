#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);
using ll = long long;

const int MAXN = (int)1e6;
int a[MAXN];
void solve() {
    int T; cin >> T;
    while(T--) {
        int n, k; cin >>n >> k;
        for (int i = 0; i < n; i++) cin >> a[i];
        int ans = 0;
        for (int i = 0; i < k; i++) ans += a[i];
        int sum = ans;
        for (int i = k; i < n; i++) {
            sum += a[i] - a[i - k];
            ans = max(ans, sum); 
        }
        cout << (ans > 0 ? ans : -1) << endl;        
    }
}

signed main() {
    fast_io
    solve();
}