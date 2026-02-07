#include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")

const long long MAXN = 1e18;

// time : O(sqrt(n))
// space: O(1) 
int divCount(long long n) {
    int cnt = 0;
    for (int i = 1; 1LL * i * i <= n; i++)
        if(n % i == 0) cnt += (1LL * i * i == n ? 1 : 2);     
    return cnt;
}

void solve() {
    cout << divCount(MAXN) << endl;
}

signed main () {
    solve();
}