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

const int MAXN = 505;
const double EPS = 1e-12;
vector<pair<int,int>> adj[MAXN]; // (v, edge_index)
vector<pair<int,int>> edges;

void solve() {
    int n, m;
    cin >> n >> m;
    edges.assign(m+1, {0,0});

    for(int i = 1;i <= m;i++){
        int u, v; cin >> u >> v;
        edges[i] = {u, v};
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    int N = n - 1;
    if(N == 0){
        cout << "0.000" << endl;
        return;
    }
    vector<vector<double>> A(N, vector<double>(N+1, 0.0)); 

    vector<int> deg(n+1, 0);
    for(int u=1; u<=n; ++u) deg[u] = (int)adj[u].size();

    for(int u=1; u<=n-1; ++u){
        int r = u-1;
        A[r][r] = 1.0;
        for(auto pr : adj[u]){
            int j = pr.first; // neighbor j of u
            if(j == n) continue; // h_n = 0 skip
            int c = j - 1;
            A[r][c] -= 1.0 / deg[j];
        }
        A[r][N] = (u == 1) ? 1.0 : 0.0;
    }

    // Gaussian elimination with partial pivoting
    for(int col = 0, row = 0; col < N && row < N; ++col, ++row){
        int sel = row;
        for(int i = row; i < N; ++i){
            if(fabs(A[i][col]) > fabs(A[sel][col])) sel = i;
        }
        if(fabs(A[sel][col]) < EPS){
            --row; // skip this column
            continue;
        }
        swap(A[sel], A[row]);
        double pivot = A[row][col];
        for(int j = col; j <= N; ++j) A[row][j] /= pivot;
        for(int i = 0; i < N; ++i){
            if(i == row) continue;
            double f = A[i][col];
            if(fabs(f) < EPS) continue;
            for(int j = col; j <= N; ++j) A[i][j] -= f * A[row][j];
        }
    }

    // extract h[1..n-1]
    vector<double> h(n+1, 0.0);
    for(int i=1;i<=n-1;i++) h[i] = A[i-1][N];
    h[n] = 0.0;

    // compute p_e for each edge
    vector<double> p;
    p.reserve(m);
    for(int i=1;i<=m;i++){
        int u = edges[i].first, v = edges[i].second;
        double pu = (u==n ? 0.0 : h[u] / deg[u]);
        double pv = (v==n ? 0.0 : h[v] / deg[v]);
        p.push_back(pu + pv);
    }

    sort(p.begin(), p.end(), greater<double>());

    double ans = 0;
    for(int i=0;i<m;i++) ans += p[i] * (i+1);

    cout.setf(std::ios::fixed);
    cout << setprecision(3) << ans << "\n";
}

signed main () {
    fast_io;
    solve();
}