#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O2")
#define fast_io ios::sync_with_stdio(false); cout.tie(nullptr); cin.tie(nullptr);

void pushZerosToEnd(vector<int>& arr) {
    for(int i = arr.size() - 1; i >= 0; i--) {
        if(arr[i] == 0) {
            arr.erase(arr.begin() + i);
            arr.push_back(0);
        } 
    }
}
//optimize handle by array
void pushZerosToEnd_2(vector<int>& arr) {
    int t = arr.size();
    arr.erase(remove(arr.begin(), arr.end(), 0), arr.end());
    t -= arr.size();
    while (t--) arr.push_back(0);
}

// two pointer
void pushZerosToEnd_2p(vector<int>& arr) {
    int j = 0, n = arr.size();
    for(int i = 0; i < n; i++) {
        if(arr[i] != 0) {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for(int &x:arr) cin >> x;
    pushZerosToEnd_2p(arr);
    for(int &x:arr) cout << x << ' ';
}

signed main() {
    fast_io
    solve();
}