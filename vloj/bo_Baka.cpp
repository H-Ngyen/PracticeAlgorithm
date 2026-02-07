#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);
#define int long long
using ll = long long;

const int MAXN = 2000;
int a[MAXN];
void solve() {
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        for(int i = 0; i < n; i++) cin >> a[i];
        
        ll count = 0;
        unordered_map<int,int> hm;
        hm[a[0]]++;
        for (int i = 1; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int target = k - a[i] - a[j];
                if(hm.count(target)) count += hm[target];
            }
            hm[a[i]]++;
        }
        cout << count << endl;
    } 
}

signed main() {
    fast_io
    solve();
    // cout << (int)1e9 - INT32_MAX << endl;
    // cout << INT32_MAX - pow(MAXN,3) << endl;
}