#include <bits/stdc++.h>
using namespace std;
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sor(x) sort(all(x))
#define rsor(x) sort(rall(x))
#define BIT(x, i) (((x) >> (i)) & 1)
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

// void dfs(vector<vector<int>> &adj, vector<vector<int>> &w, vector<bool> &vs, int s, int parent, ll curr, vector<ll> &xor_v) {
//     vs[s] = 1;
//     xor_v[s] = curr;


//     for (int i = 0; i < sz(adj[s]); i++) {
//         int v = adj[s][i];
//         int wi = w[s][i];
//         if (v == parent) continue;
//         if (!vs[v]) dfs(adj, w, vs, v, s, curr ^ wi, xor_v);
//     }

// }

// void addEdge(vector<vector<int>> &adj, vector<vector<int>> &w, int u, int v, int wi) {
//     adj[u].push_back(v);
//     adj[v].push_back(u);
//     w[u].push_back(wi);
//     w[v].push_back(wi);
// }

// void solve() {
//     int n;
//     cin >> n;
//     vector<vector<int>> adj(n + 1), w(n + 1);
//     vector<bool> vs(n + 1);
//     vector<ll> xor_v(n + 1);

//     for (int i = 1; i < n; i++) {
//         int u, v, wi;
//         cin >> u >> v >> wi;
//         addEdge(adj, w, u, v, wi);
//     }
//     dfs(adj, w, vs, 1, -1, 0, xor_v);

//     ll ans = 0;
//     for (int i = 0; i < 26; i++) {
//         ll cnt = 0;
//         for (int j = 1; j <= n; j++)
//             if (xor_v[j] & (1 << i))
//                 cnt++;
//         ans += 1LL * cnt * (n - cnt) * (1 << i);

//     }
//     cout << ans << endl;

// }

const int MAXN = 1e3 + 5;
vector<pair<int, int>> g[MAXN];
ll xorVal[MAXN];

void dfs(int u, int pre, ll val) {
    xorVal[u] = val;
    for (auto [v, w] : g[u]) {
        if (v == pre) continue;
        dfs(v, u, val ^ w);
    }
}

void solve() {
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    // 1. DFS tính xorVal từ node 1
    dfs(1, -1, 0);

    // 2. Tính tổng
    ll ans = 0;
    for (int i = 0; i < 26; i++) {
        ll cnt1 = 0;
        for (int j = 1; j <= n; j++) if(BIT(xorVal[j], i)) cnt1++;
        ans += cnt1 * (n - cnt1) * (1 << i);
    }
    

    // for (int bit = 0; bit < 26; bit++) {
    //     ll cnt1 = 0;
    //     for (int i = 1; i <= n; i++) {
    //         if (xorVal[i] & (1LL << bit)) cnt1++;
    //     }
    //     ll cnt0 = n - cnt1;
    //     ans += cnt1 * cnt0 * (1LL << bit);
    // }

    cout << ans << "\n";
}

signed main() {
    fast_io
    solve();
}