//tag: greedy, math, 
//desc: 
//  bài toán kiểm tra chuỗi có k cặp đối xứng hay không? 
//  nếu chuỗi ko có k cặp đối xứng thì kiểm tra xem có thể hoán vị trí của chuỗi để được k đối xứng không
//solve: 
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
        string s; cin >> s;
        int c0 = 0;
        for(char c:s){
            if(c == '0') c0++;
        }
        int c1 = n - c0;
        int min_k = abs(c0 - n / 2);
        bool possiable = (k >= min_k && k <= n/2);
        if(possiable){
            possiable = (c0 - n/2 + k) % 2 == 0 && (c1 - n/2 + k) % 2 == 0;
        }
        cel((possiable ? "YES" : "NO"));
    }   
}

int main()
{
    fast_io;
    solve();

    return 0;
}