//tag: greedy, dp
//desc: như bài chia đồng xu (bài toán kinh điển greedy)
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
using ld = long double;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve(){
    int n; cin >> n;
    int arr[5] = {1,5,10,20,100};
    int count = 0;
    for (int i = 4; i >= 0 ; i--)
    {
        while(n - arr[i] >= 0) 
        {
            n-=arr[i];
            count++;
        }
        // cel("n: " << n << "\tarr[i]: " << arr[i]);
        if(n == 0) break;
    }
    cel(count);
}

int main()
{
    fast_io;
    solve();

    return 0;
}