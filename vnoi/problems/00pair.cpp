#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
// #pragma GCC optimize("O2,unroll-loops,no-stack-protector")
// #pragma GCC target("avx2,tune=native")
#define fast_io ios::sync_with_stdio(0); cin.tie(NULL);
using ll = long long;
using int64 = int64_t;

const int MAXN = (int)1e3;
int dp[MAXN];

int64 powll(int64 a, int64 b) {
    int64 res = 1;
    while(b) {
        if(b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n;
    while (cin >> n) {
        if(n <= 0) {
            cout << 0 << endl;
            continue;
        }
        int64 p = powll(2LL, n - 1);
        int64 res = (p + (n & 1 ? -1LL : 1LL)) / 3;
        cout << res << endl;
    }
}


signed main() {
    fast_io
    solve();
}