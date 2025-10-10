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

// O(n^2)
void solve() {
    int n, sum; cin >> n;
    vector<int> v(n), ans;
    for (int &x : v) cin >> x;
 
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            if (v[i] < v[j]) break;
            if (j == n - 1) ans.push_back(v[i]);
        }

    ans.push_back(v[n - 1]);
    for (int &x : ans) cout << x << ' ';
}  

// O(n)
void solve2() {
    int n, sum = 0; cin >> n;
    vector<int> v(n), ans;
    for (int &x : v) cin >> x;
    
    int maxRight = v[n - 1];
    ans.push_back(maxRight);

    for (int i = n - 2; i >= 0; i--) {
        if (v[i] >= maxRight) {
            maxRight = v[i];
            ans.push_back(maxRight);
        }
    }
    reverse(ans.begin(), ans.end());
    for (int &x : ans) cout << x << ' ';
}

int main()
{
    fast_io;
    solve2();
    
    return 0;
}