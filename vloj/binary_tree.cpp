#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);
using ll = long long;

void solve() {
    int T; cin >> T;
    while(T--) {
        int x; cin >> x;
        string res = "";
        while (x > 1) {
            if(x & 1) res += "R";
            else res += "L";
            x >>= 1;
        }    
        reverse(res.begin(), res.end());
        cout << res << endl;
    }
}

signed main() {
    fast_io
    solve();
}