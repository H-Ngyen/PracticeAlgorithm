#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
// #pragma GCC target("avx2,tune=native")
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);
using ll = long long;

const int MAXN = (int)1e5;
bool isPrime[MAXN];
void init() {
    fill(isPrime, isPrime + MAXN, 1);
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i * i <= MAXN; i++) {
        if(isPrime[i]) {
            for (int j = i * i; j <= MAXN; j+=i) {
                isPrime[j] = 0;
            }
        }
    }
}

bool check;
void solve() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        check = 1;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            if(check && !isPrime[x]) check = 0;
        }
        cout << (check ? "YES" : "NO") << endl;
    }
}

signed main() {
    fast_io
    init();
    solve();
}
