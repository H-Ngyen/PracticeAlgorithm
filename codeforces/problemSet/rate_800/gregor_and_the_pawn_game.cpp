#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O2")
#define fast_io ios::sync_with_stdio(0); cout.tie(NULL); cin.tie(NULL);
#define BIT(x, i) (((x) >> (i)) & 1)

void solve() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s1, s2; cin >> s1 >> s2;
        bool vs[n] = {0};
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if(s2[i] == '1') {
                for (int j = i - 1; j <= i + 1; j++) {
                    if (j >= 0 && j < n) {
                        if (!vs[j]) {
                            if(s1[j] == '1' && j != i || s1[j] == '0' && j == i) {
                                cnt++;
                                vs[j] = 1;
                            }
                        
                        }
                    }
                }
            }
        }
        cout << cnt << endl;
    }
}

signed main() {
    fast_io
    solve();
}