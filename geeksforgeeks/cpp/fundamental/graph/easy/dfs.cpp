#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O2")
#define ll long long
#define fast_io ios::sync_with_stdio(false); cout.tie(nullptr); cin.tie(nullptr);

void dfs(int u, vector<vector<int>> &adj, vector<bool> &vs) {
    vs[u] = 1;
    cout << u << ' ';
    for(int v:adj[u]) {
        if(!vs[v]) dfs(v, adj, vs);
    }
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<bool> vs(n);
    dfs(1, adj, vs);
}

signed main() {
    fast_io
    solve();
}