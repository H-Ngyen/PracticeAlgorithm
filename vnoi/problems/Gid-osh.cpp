#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
// #pragma GCC optimize("O2,unroll-loops,no-stack-protector")
// #pragma GCC target("avx2,tune=native")
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);

const int INF = (int)1e9;
const int MAXN = (int)100;
int a[MAXN];

//O(n^2)
void solve(){
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i]; 
        
        int res = INF;
        for (int i = 0; i < n; i++) {
            int e_max = 0, e_min = INF;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    e_max = max(e_max, a[j]);
                    e_min = min(e_min, a[j]);
                }
            }
            res = min(res, e_max - e_min);
        }
        cout << res << endl;
    }
}

// O(nlogn)
void solve2() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        sort(arr.begin(), arr.end());
        int res = min(arr[n - 2] - arr[0], arr[n - 1] - arr[1]);
        cout << res << endl;
    }  
}

signed main() {
    fast_io;
    solve2();
}