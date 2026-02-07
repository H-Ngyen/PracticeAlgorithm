#include <bits/stdc++.h>
using namespace std;
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

void solve2()
{
    ll n, m;
    cin >> n >> m;
    if (n % 2 || m % 2 || m > 2 * n || n > m) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    
    if (2 * n == m) {
        cout << m / 4 << ' ' << 0 << endl;
        return;
    }

    if (m == n) {
        cout << 0 << ' ' << m / 2 << endl;
        return;
    }

    if (n == m - 2) {
        cout << 1 << ' ' << n / 2 - 1 << endl;
        return;
    }

    if ((n / 2) % 2 == 0 && m % 3 == 0) {
        cout << n / 2 / 2 << ' ' << n / 2 / 2 << endl;
        return;
    }

    if (2 * (n - 2) == m - 2) {
        cout << m / 4 << ' ' << 1 << endl;
        return;
    }

    else {
        ll a = n / 2;
        ll b = (m - n) / 2;
        cout << b << ' ' << a - b << endl;
        return;
    }
}

// 2x + 2y = n
// 4x + 2y = m
void solve() {
    ll n, m; cin >> n >> m;

    if (n % 2 != 0 || m % 2 != 0 || m < n || m > 2 * n) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    ll t = (m - n) / 2;
    ll o = (2 * n - m) / 2;

    cout << t << ' ' << o << endl;
}

int main () {
    fast_io;
    solve();
    return 0;
}