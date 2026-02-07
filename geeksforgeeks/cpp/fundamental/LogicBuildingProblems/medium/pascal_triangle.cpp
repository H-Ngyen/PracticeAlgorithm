#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

const long long MOD = 1e9 + 7;

// O(n^2)
vector<int> nthRowOfPascalTriangle(int n) { 
    if(n == 1) return {1};
    if(n == 2) return {1,1};
    vector<vector<int>> ans (n, vector<int> (n));
    ans[0] = {1};
    ans[1] = {1,1};
    for (int i = 2; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) ans[i][j] = 1;
            else ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
        }
    }
    return ans[n - 1];
}

int C(int n, int k, vector<vector<int>> &dp) {
    if (k == 0 || k == n) return 1;
    if (dp[n][k] != -1) return dp[n][k];
    return dp[n][k] = C(n - 1, k - 1, dp) + C(n - 1, k, dp);
}

vector<int> nthRowOfPascalTriangle2(int n) {
    vector<int> row;
    vector<vector<int>> dp(n + 1, vector<int> (n + 1, - 1));
    for (int k = 0; k < n; k++)
        row.push_back(C(n - 1, k, dp));
    return row;
}

// O(n)
vector<int> nthRowOfPascalTriangle3(int n) {
    --n;
    vector<int> row(n + 1);
    row[0] = 1;
    for (int i = 1; i <= n; i++)
        row[i] = row[i - 1] * (n - i + 1) / i;
    return row;
}

int main() {
    int n; cin >> n;
    // cout << fac(n) / fac(n - 0) * fac(0) << endl;
    vector<int> res = nthRowOfPascalTriangle2(n);
    for (int x:res) cout << x << ' ';
    // vector<vector<int>> dp(n);

    // cout << C(4,0,dp) << endl;
    return 0;
}