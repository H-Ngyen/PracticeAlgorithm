#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;

const ll MOD = 1e9 + 7;

vector<long long> dp(2, 1);

int findCatalan(int n) {
    if(n <= 1) return 1;
    if((int)dp.size() <= n) dp.resize(n + 1);
    if(dp[n]) return dp[n];
    for (int i = 0; i < n ; i++)
        dp[n] +=  (1LL * findCatalan(i) * findCatalan(n - i - 1) % MOD) % MOD;
    return dp[n];
}

void solve() {
    int n; cin >> n;
    cout << findCatalan(n) << endl;
}

int main() {
    fast_io
    solve();

    return 0;
}