#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);
using ll = long long;

const int MAXN = 5000;
int a[MAXN], dp[MAXN];
void solve() {
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    
    int ans = -1;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if(a[i] > a[j]) {
                dp[i] = max(dp[i], dp[j]+ 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}

void solve2() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    vector<int> res;
    for(int &i:a) {
        auto pos = lower_bound(res.begin(), res.end(), i);
        if(pos == res.end()) res.push_back(i);
        else *pos = i;
    }
    cout << res.size() << endl;
}

signed main() {
    fast_io
    solve2();
}