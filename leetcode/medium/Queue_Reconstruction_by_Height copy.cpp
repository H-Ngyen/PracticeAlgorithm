#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
// #pragma GCC target("avx2,tune=native")
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);
using ll = long long;

class Solution {
private:
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        if(a[0] != b[0]) 
            return a[0] > b[0];
        return a[1] < b[1];
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        vector<vector<int>> ans;
        ans.reserve(n);
        sort(people.begin(), people.end(), cmp);
        for (auto &p:people) ans.insert(ans.begin() + p[1], p);
        return ans;        
    }
};

class Solution_FenwickTree {
private:
    int n; 
    vector<int> bit;
    
    static bool cmp(const vector<int> &a, const vector<int> &b) { return (a[0] != b[0] ? a[0] < b[0] : a[1] > b[1]); }

    void update(int i, int v) {
        for(; i <= n; i += i & -i) bit[i] += v; 
    }

    int getSum(int i) {
        int sum = 0;
        for(; i ; i -= i & -i) sum += bit[i];
        return sum;
    }
    int findByOrder(int k) {
        int l = 1, r = n;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if(getSum(mid) <= k) l = mid + 1;
            else r = mid;
        }
        return l;
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        n = people.size();
        vector<vector<int>> res(n, vector<int> (2, -1));
        bit.assign(n + 5, 0);
        sort(people.begin(), people.end(), cmp);
        for(int i = 1; i <= n; i++) update(i, 1);
        for(auto &p:people) {
            int k = p[1];
            int pos = findByOrder(k);
            res[pos - 1] = p;
            update(pos, -1);
        }
        return res;
    }
};

void solve() { 
    int n; cin >> n;
    vector<vector<int>> people(n, vector<int> (2));
    for (int i = 0; i < n; i++) cin >> people[i][0] >> people[i][1]; 
    Solution_FenwickTree* sol = new Solution_FenwickTree();
    vector<vector<int>> res = sol->reconstructQueue(people);
    for (auto &r:res) cout << r[0] << " " << r[1] << endl;
    delete sol;
}

signed main() {
    fast_io
    solve();
}