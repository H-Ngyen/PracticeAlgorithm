//WA T-T

#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("unroll-loops,no-stack-protector")
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sor(x) sort(all(x))
#define rsor(x) sort(rall(x))
#define vt vector
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define cel(x) cout << x << '\n'
#define cht(x) cout << x << ' '
using ll = long long;
using ull = unsigned long long;

const int MOD = 1e7 + 7;
const int INT = 1e9 + 7;

void solve() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vt<vt<int>> arr(n, vt<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                arr[i][j] = j + 1;

        vt<vt<int>> opts;
        for (int i = 1; i < n; i++) {
            opts.push_back({i + 1, 1, min(i + 1, n)});
            reverse(arr[i].begin(), arr[i].begin() + min(i + 1, n));
            opts.push_back({i + 1, i, n}); 
            reverse(arr[i].begin() + i, arr[i].end());
        }
        cel(sz(opts));
        for (auto o : opts) cel(o[0] << " " << o[1] << " " << o[2]);
    }
}

int main()
{
    fast_io;
    solve();

    return 0;
}