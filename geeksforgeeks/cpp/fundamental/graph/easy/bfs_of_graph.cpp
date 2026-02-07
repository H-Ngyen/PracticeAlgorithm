#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O2")
#define fast_io ios::sync_with_stdio(false); cout.tie(nullptr); cin.tie(nullptr);

const int MAXN = 1e4;
vector<vector<int>> adj(MAXN);
vector<bool> vs(MAXN, 0);

void bfs_(int s) {

    queue<int> q;
    q.push(s);
    vs[s] = 1;
    
    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << ' ';
        for(int v:adj[u]) {
            if(!vs[v]) {
                q.push(v);
                vs[v] = 1;
            }
        }
    }
}

vector<int> bfs(vector<vector<int>> &adj) {
    vector<int> res;
    queue<int> q;
    q.push(0);
    vs[0] = 1;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        res.push_back(u);
        for(int v:adj[u]) {
            if(!vs[v]) {
                q.push(v);
                vs[v] = 1;
            }
        }
    }
    return res;
}   

void solve() {
    int n; cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        int v;
        while(ss >> v) adj[i].push_back(v);
    }
    vector<int> res = bfs(adj);
    for(int &x:res) cout << x << ' ';

}

signed main() {
    fast_io
    solve();
}