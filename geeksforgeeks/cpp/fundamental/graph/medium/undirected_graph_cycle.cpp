#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O2")
#define fast_io ios::sync_with_stdio(false); cout.tie(nullptr); cin.tie(nullptr);
using ll = long long;
#define BIT(x, i) (((x) >> (i)) & 1)

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

const int MOD = 1e9 + 7;

//call stack
void dfs_r(int u, int pre, vector<vector<int>> &adj, vector<bool> &vs, bool &ans) {
    if(ans) return;
    vs[u] = 1;
    for(int x:adj[u]) {
        if(vs[x] && x != pre) {
            ans = 1;
            return;
        }
        if(!vs[x]) dfs_r(x, u, adj, vs, ans);
    }
}

// stack heap
void dfs_i(int s, vector<vector<int>>& adj, vector<bool>& vs, bool &ans) {
    stack<pair<int,int>> st; // {node, parent}
    st.push({s, -1});
    vs[s] = 1;

    while (!st.empty()) {
        auto [u, parent] = st.top(); st.pop();
        for (int v : adj[u]) {
            if (!vs[v]) {
                vs[v] = 1;
                st.push({v, u});
            } else if (v != parent) {
                ans = true;
                return;
            }
        }
    }
}

void bfs(int s, vector<vector<int>> &adj, vector<bool> &vs, vector<int> &par, bool &ans) {
    queue<int> q;
    q.push(s);
    vs[s] = 1;

    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v:adj[u]) {
            if(!vs[v]) {
                q.push(v);
                vs[v] = 1;
                par[v] = u;
            }
            else if (v != par[u]) {
                ans = 1;
                return;
            }
        }
    }
}

// convert edge list to adjacency list
// adjacency list are faster, low space and easier to implement DFS
bool isCycle(int V, vector<vector<int>>& edges) {
    bool ans = 0;
    vector<bool> vs(V);
    vector<vector<int>> adj(V);
    vector<int> par(V, -1);

    for(auto e:edges) {
        int u = e[0], v = e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < V; i++) {
        if(!vs[i]) bfs(i, adj, vs, par, ans);
    }
    return ans;
}

// input is edge list
void solve () {
    int v, e; cin >> v >> e;
    vector<vector<int>> edges;
    for(int i = 0; i < e; i++) {
        int x, y; cin >> x >> y;
        edges.push_back({x, y});
    }
    cout << (isCycle(v, edges) ? "true" : "false") << endl;
}

signed main () {
    fast_io
    solve();
}