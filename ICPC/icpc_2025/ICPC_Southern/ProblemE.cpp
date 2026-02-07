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
        int n; cin >> n;
        deque<int> a(n);
        for (int &x:a) cin >> x;
        int ans = 0;
        int a_size = a.size();
        while (!a.empty()) {
            if(a.size() >= 2 && gcd(a[0], a[1]) == 1) {
                a.pop_front();
                a.pop_front();
            }
            else {
                for (int i = 1; ; i++) {
                    if (gcd(a[0] + i, a[1]) == 1) {
                        a.push_back(i);
                        a[0] = a[0] + i;
                        break;
                    }
                }
            }
            ans++;
        }
        cout << ans << endl;
    }
}

void solve2() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x:a) cin >> x;

        if (n <= 2) cout << 2LL * n << endl;
        else cout << n << endl;
    }
}
int main () {
    fast_io;
    solve2();
    // cout << gcd(12,15) << endl;
    return 0;
}