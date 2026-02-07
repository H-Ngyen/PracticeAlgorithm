#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("unroll-loops,no-stack-protector")
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sor(x) sort(all(x))
#define rsor(x) sort(rall(x))
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
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

//O(n)
void solve() {
    int n; cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll a = 1LL * i * i % MOD;
        ans = (ans + a) % MOD;
    }
    cout << ans << endl;
}

// O(1)
// n(n + 1)(2n + 1) / 6
// để tránh bị tràn số thì có thể tách công thức ra:
// => (n(n + 1) / 2) * (2n + 1) / 3   
void solve2() {
    int n; cin >> n;
    cout << (1LL * n * (n + 1) / 2) * (2LL * n + 1) / 3 << endl;
    // cout << 1LL * n * (n + 1) * (2 * n + 1) / 6 << endl;       
}

int main()
{
    fast_io;
    solve2();
    
    return 0;
}