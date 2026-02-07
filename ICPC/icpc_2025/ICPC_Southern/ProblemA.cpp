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

void solve() {
    int T; cin >> T;
    while (T--) {
        int n;
        ll C, D;
        cin >> n >> C >> D;
        vector<ll> a(n), b(n);
        for (auto &x : a) cin >> x;
        for (auto &x : b) cin >> x;

        ll maxA = *max_element(a.begin(), a.end());
        ll maxB = *max_element(b.begin(), b.end());

        ll minA = *min_element(a.begin(), a.end());
        ll minB = *min_element(b.begin(), b.end());
        if (maxA - minA <= C && maxB - minB <= D) {
            cout << 0 << endl;
            continue;
        }

        ll ans = LLONG_MAX;
        bool possible = 0;

        for (ll A_target = maxA; A_target >= maxA - C && A_target >= minA; --A_target) {
            for (ll B_target = maxB; B_target >= maxB - D && B_target >= minB; --B_target) {
                bool check = true;
                ll sum = 0;
                for (int i = 0; i < n; i++) {
                    ll ta = A_target - a[i];
                    ll tb = B_target - b[i];
                    if (ta != tb || ta < 0) { check = 0; break; }
                    sum += ta;
                }
                if (check) {
                    possible = true;
                    ans = min(ans, sum);
                }
            }
        }

        cout << (possible ? ans : -1) << endl;
    }
}

int main () {
    fast_io;
    solve();
    return 0;
}