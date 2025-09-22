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

void solve()
{
    int n; cin >> n;
    ll total_num = 1ll * n *(n + 1)/2;
        
    if(total_num % 2 != 0) cel("NO");
    else{
        cel("YES");

        int max_element = n;
        ll set1_sum = 0;

        vt<int> set1, set2;
        vt<int> vis(n + 1 , 0);

        while (set1_sum < total_num / 2){
            ll remaining_sum = total_num / 2 - set1_sum;
            
            if(remaining_sum > max_element){
                set1.push_back(max_element);
                set1_sum += max_element;
                vis[max_element] = 1;
                max_element--; 
            }
            else{
                set1.push_back(remaining_sum);
                vis[remaining_sum] = 1;
                set1_sum = total_num / 2;
            }
        }

        for (int i = 1; i <= n; i++)
            if(vis[i] != 1) set2.push_back(i);

        cel(sz(set1));
        for (auto i:set1) cht(i);
        
        cout << endl;
        
        cel(sz(set2));
        for (auto i:set2) cht(i);
    }      
}


int main()
{
    fast_io;
    solve();

    return 0;
}