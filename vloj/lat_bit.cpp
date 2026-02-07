#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);
using ll = long long;

const int MAXN = 1000;
int a[MAXN];
void solve() {
    int T; cin >> T;
    while(T--) {
        int n, ans = 0; cin >> n;
        // unordered_map<int, int> hm;
        bool check = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i]) check = 1;
        }
        
        if(!check) {
            if(n == 1) cout << 1 << endl;
            else if (n == 2) cout << 2 << endl;
            else cout << 3 << endl;
            continue;
        }

        for(int i = 0; i < n; i++) {
            if(a[i] == 0) {
                ans++;
                while (i < n && a[i] == 0) i++;
            }
            else i++;
        }
        cout << ans << endl;
    }
}

signed main() {
    fast_io
    solve();
}