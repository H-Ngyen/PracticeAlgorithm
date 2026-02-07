#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
// #pragma GCC target("avx2,tune=native")
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);
using ll = long long;

void solve() {
    int T; cin >> T;
    while (T--) {
        int n, k;
        string s;
        cin >> n >> k >> s;

        int d = 0, i = 0;
        while (i < n) {
            if (i + 1 < n && s[i] == '-' && s[i+1] == '-') {
                d += 1;
                i += 2;
            } 
            else {
                if (s[i] == '+') d += 1;
                else d -= 1;
                i += 1;
            }
        }
        cout << k + d << endl;
    }
}

signed main() {
    fast_io
    solve();
}