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

ll findMaxPath(vt<vt<ll>> &v, int n, int m){
    vt<vt<ll>> dp(n, vt<ll>(m, 0));
    dp[0][0] = v[0][0];

    for (int i = 1; i < n; i++) dp[0][i] = dp[0][i - 1] + v[0][i];
    for (int i = 1; i < m; i++) dp[i][0] = dp[i - 1][0] + v[i][0];

    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            dp[i][j] = v[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
    
    return dp[n-1][m-1];
}

void solve(){
    int n, m; cin >> n >> m;
    vt<vt<ll>> v(n, vt<ll>(m));
    srand(time(0));

    for (int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            v[i][j] = rand() % 101;
    
    for (int i = 0; i < n; i++) cel(v[i]);
    
    cel(findMaxPath(v, n, m));
}

int main()
{
    fast_io;
    solve();
    // test();
    
    return 0;
}