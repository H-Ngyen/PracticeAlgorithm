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

void sol(){
    int n; cin >> n;
    int v;
    
    ll res = 0;
    for (int i = 0; i < n; i++){
        ll sum = 0;
        for (int j = 0; j < 3; j++)
        {
            cin >> v;
            sum += v;
        }
        if(sum >= 2) res++;    
    }
    cel(res);
}

int main()
{
    fast_io;
    sol();

    return 0;
}