#include <bits/stdc++.h>
using namespace std;
#pragma optimize("O2")
#define int int64_t

const long long MOD = INT32_MAX;

long long fac(long long n, vector<long long> &dp) {
    if(n == 1 || n == 0) return 1;
    if(n >= dp.size()) dp.resize(n + 1, 0);
    if(dp[n]) return dp[n];
    return dp[n] = fac(n - 1, dp) * n % MOD;
}
 
long long powll(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int modInv(int x) {
    return powll(x, MOD - 2);
}

int nCr(int n, int r) {
    if (r > n) return 0;
    vector<long long> dp(n + 1);
    dp[1] = 1;
    int num = fac(1LL * n, dp) % MOD;
    int den = fac(1LL * n - r, dp) * fac(1LL * r, dp) % MOD;
    int ans = 1LL * num * modInv(den) % MOD;
    return ans;
}

signed main () {
    int n, r; cin >> n >> r;
    cout << nCr(n,r) << endl;
}