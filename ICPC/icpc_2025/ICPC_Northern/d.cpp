#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O2")
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

ll count_sequences_mod(ll n, ll k, ll M, ll P) {
    if (k == 0) return 1 % P;
    if (k == 1) return n % P;

    ll limit = n - (k - 1);
    if (limit <= 0) return 0;

    ll Smax = (M - 1) * (k - 1);
    vector<ll> dp(Smax + 1, 0);
    dp[0] = 1;

    for (int t = 0; t < k - 1; t++) {
        vector<ll> new_dp(Smax + 1, 0);
        ll prefix = 0;
        for (int s = 0; s <= Smax; s++) {
            prefix += dp[s];
            if (s - M >= 0) prefix -= dp[s - M];
            prefix = (prefix % P + P) % P;
            new_dp[s] = prefix;
        }
        dp.swap(new_dp);
    }

    ll res = 0;
    for (ll s = 0; s <= min(Smax, limit - 1); s++) {
        res = (res + (limit - s) % P * dp[s]) % P;
    }

    return res % P;
}

void solve() {
    ll n, k, M, P;
    cin >> n >> k >> M >> P;
    cout << count_sequences_mod(n, k, M, P) << "\n";
}

signed main () {
    fast_io;
    solve();
}