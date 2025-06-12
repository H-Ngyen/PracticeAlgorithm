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

void solve()
{
    int T; cin >> T;
    while (T--)
    {
        int n, k; cin >> n >> k; 
        string s(n, '0');
        for (int i = 0; i < k; i++) s[i] = '1';
        cel(s);
    }   
}

int main()
{
    fast_io;
    solve();

    return 0;
}