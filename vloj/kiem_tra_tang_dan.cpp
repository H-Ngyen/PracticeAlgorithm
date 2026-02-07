#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);
using ll = long long;

void solve() {
    int tt; cin >> tt;
    while (tt--) {
        string s; cin >> s;
        int curr = 1, max_s = 1;
        for (int i = 1; i < s.size(); i++) {
            if(s[i - 1] < s[i]) curr++;
            else {
                max_s = max(curr,max_s);
                curr = 1;
            }
        }    
        max_s = max(max_s, curr);
        cout << max_s << endl;    
    }
}

signed main() {
    fast_io
    solve();
}