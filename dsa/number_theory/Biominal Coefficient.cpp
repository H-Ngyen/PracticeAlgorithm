#include <bits/stdc++.h>
using namespace std;

long long fac(int n) {
    long long res = 1;
    for(int i = 2; i <= n; i++) res *= i;
    return res;
}

long long toHop(long long n, long long k) {
    return fac(n) / (fac(k) * fac(n - k));
}

long long test(long long n) {
    long long res = 0;
    for (int i = 0; i <= n; i++)  res += toHop(n, i);
    return res;
}

void solve() {
    // int n, k; cin >> n;
    // cout << test(n) << endl;
    cout << toHop(5,3) << endl;
    // cout << (1LL << n) << endl;
}

signed main() {
    solve();
}