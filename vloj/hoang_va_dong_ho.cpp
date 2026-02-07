#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
// #pragma GCC target("avx2,tune=native")
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);

const int MAXN = (int)1e5 + 5;
int H[MAXN];
bool c;
void solve() {
    int T; cin >> T;
    while(T--) {
        int n, h; 
        char C;
        cin >> n >> h >> C;
        
        c = (C == 'A' ? 1 : 0);
        for(int i = 0; i < n; i++) cin >> H[i];
        
        if(!c && h < 12) h += 12;
        if(c && h == 12) h = 0;

        bool check = 1;
        for (int i = 0; i < n; i++) {
            if(H[i] == 0) {
                check ^= 1;
                continue;
            } 
            // cout << h << (c ? " A" : " P") << endl;
            h += (check ? H[i] : -H[i]);
            h %= 24;
            if(h < 0) h += 24;
        }
        if(h == 0) {
            h += 12; c = 1;
        }
        else if (h < 12) c = 1;
        else if (h == 12) c = 0;
        else {
            h -= 12; c = 0;
        }
        cout << h << ' ' << (c ? "A" : "P") << endl;
    }
}

signed main() {
    fast_io
    solve();
}