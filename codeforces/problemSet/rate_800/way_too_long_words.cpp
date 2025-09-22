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
    int T;
    cin >> T;
    while (T--)
    {
        string s; cin >> s;
        if(sz(s) <= 10) cel(s);
        else{
            char first = s[0];
            char last = s[sz(s) - 1];
            int abb = sz(s) - 2;
            string res = string(1, first) + to_string(abb) + string(1, last);
            cel(res);
        }
    }
}
 
void sol(){
    int k, n, w; cin >> k >> n >> w;    
    for (int i = 1; i <= w; i++) n -= i*k;
    cel((n < 0? -n : 0));
}   
 
void sol2(){
    int k, n, w; cin >> k >> n >> w;    
    ll total_cost = k * w * (w + 1) / 2;
    cel((n < total_cost ? total_cost - n : 0));
}   
 
int main()
{
    fast_io;
    solve();
 
    return 0;
}