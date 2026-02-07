#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
// #pragma GCC target("avx2,tune=native")
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);

const int MAXN = (int) 1e3;
int a[MAXN][MAXN];
bool rowConst[MAXN], colConst[MAXN];
int rows[MAXN], cols[MAXN];

void solve2() {
    int T; cin >> T;
    while(T--) {
        int n, m; cin >> n >> m;
        fill(rowConst, rowConst + n, 1);
        fill(colConst, colConst + m, 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        
        //row check
        for (int i = 0; i < n; i++) {
            rows[i] = a[i][0];
            for (int j = 1; j < m; j++) {
                if(a[i][j] != rows[i]) {
                    rowConst[i] = 0;
                    break;
                }
            }
        }
        
        //cols check
        for (int j = 0; j < m; j++) {
            cols[j] = a[0][j];
            for (int i = 1; i < n; i++) {
                if(a[i][j] != cols[j]) {
                    colConst[j] = 0;
                    break;
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if(!rowConst[i]) continue;
            for (int j = 0; j < m; j++) {
                if(colConst[j]) cnt++; 
            }
        }
        cout << cnt << endl;
    }
}

void solve() {
    int T; cin >> T;
    while(T--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> rows(n), cols(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x; cin >> x;
                rows[i].push_back(x);
                cols[j].push_back(x);
            }
        }
        for (int i = 0; i < n; i++) sort(rows[i].begin(), rows[i].end());
        for (int i = 0; i < m; i++) sort(cols[i].begin(), cols[i].end());
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(rows[i][0] == rows[i].back() && cols[j][0] == cols[j].back()) cnt++;
            }   
        }
        cout << cnt << endl;
    }
}

signed main() {
    fast_io
    solve();
}