#include<bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);

void solve() {
    long long n, result = 0; cin >> n;
    vector<long long> arr(n); 
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        arr[i] = x;
    }

    for (int i = 1; i < n; i++) {
        if (arr[i] <= arr[i - 1]) {
            result += abs(arr[i - 1] - arr[i]); 
            arr[i] = arr[i - 1];
        } 
    }
    cout << result << endl;
}

signed main() {
    fast_io
    solve();
    // cout << 1000000000 - INT32_MAX << endl;
}