#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
// #pragma GCC optimize("O2,unroll-loops,no-stack-protector")
#pragma GCC target("avx2,tune=native")
#define fast_io ios::sync_with_stdio(0); cout.tie(NULL); cin.tie(NULL);
using ll = long long;

void solve2() {
    int m, n, p, q; cin >> m >> n >> p >> q;

    int cnt = 0;
    for (int i = p - 1; i <= p + 1; i++) {
        for (int j = q - 1; j <= q + 1; j++) {
            if(i == p && j == q) continue;
            if(i >= 1 && i <= m && j >= 1 && j <= n) cnt++;
        }
    }
    cout << cnt << endl;
}
 
void solve() {
    int m, n ,p ,q; cin >> m >> n >> p >> q;
    int ans;
    if((p == 1 && q == 1) || (p == 1 && q == n) || (p == m && q == 1) || (p == m && q == n)) ans = 3;
    else if ((q == 1) || (q == n) || (p == 1) || (p == m)) ans = 5; 
    else ans = 8;
    cout << ans << endl;
}

signed main() {
    fast_io
    solve2();
}