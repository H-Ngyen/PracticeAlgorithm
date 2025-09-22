#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("unroll-loops,no-stack-protector")
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sor(x) sort(all(x))
#define rsor(x) sort(rall(x))
#define vt vector
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define cel(x) cout << x << '\n'
#define cht(x) cout << x << ' '
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

class Solution {
public:
    //O(log(b))
    long long power(long long a, long long b, long long mod) {
        long long ans = 1;
        while (b) {
            if (b & 1LL)
                ans = ans * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return ans;
    }
    
    // O(nlog(M)) => M = max(b,c)
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> ans;
        for (int i = 0; i < variables.size(); i++)
            if (power(power(variables[i][0], variables[i][1], 10), variables[i][2], variables[i][3]) == target) 
                ans.push_back(i);
        return ans;
    }
};
   
int main()
{
    Solution sol;
    vector<vector<int>> variables = {{10,2,6,2},{8,10,5,7}};
    vector<int> result = sol.getGoodIndices(variables, 0);
    // cel(sol.power(8,10));
    return 0;
}