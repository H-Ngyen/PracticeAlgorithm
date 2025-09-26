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
 
// O(max(a,b))
void solve(){
    int T; cin >> T;
    while (T--)
    {
        ll a, b; cin >> a >> b;
        while (a > 0 && b > 0) {
            if(a < b) {
                a -= 1;
                b -= 2;
            }
            else {
                a -= 2;
                b -= 1;
            }
        }
        cout << (a == 0 && b == 0 ? "YES" : "NO") << endl;
        dbg(a,b);
    }
}

//O(1)
// a -= 2 => b -= 1 và ngược lại
// => mỗi lượt -3 coin => total_coin % 3 == 0 
void solve2(){
    int T; cin >> T;
    while (T--) {
        int a, b; cin >> a >> b;
        if((a + b) % 3 == 0 && 2 * a >= b && 2 * b >= a) 
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;           
    }   
}
 
int main()
{
    fast_io;
    solve2();
    
    return 0;
}