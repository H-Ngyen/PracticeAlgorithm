#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
// #pragma GCC target("avx2,tune=native")
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);

const int MAXN = (int)1e5;
int a[MAXN], n;
void solve() {
    cin >> n; 
    for (int i = 0; i < n; i++) cin >> a[i];
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++) {
        if(i < n / 2) sum1 += a[i];
        else sum2 += a[i];
    }
    cout << abs(sum1 - sum2) << endl;
}

signed main() {
    fast_io
    solve();
}