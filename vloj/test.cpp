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

void test(){
    pair<int, string> p = {1, "hello"};
    cout << p;
}

//arr = {1, 4, 5}
//arr[i] * arr[i + 1] < 0 
//1 * -4 = -
//1 *  1 = +
void solve2(){
    int n; cin >> n; 
    vt<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    bool check = true;
    for (int i = 0; i < n - 1; i++)
    {
        if(a[i] * a[i + 1] >= 0){
            check = false;
            break;
        }
    }
    cel(( check ? "YES" : "NO"));
}

void solve()
{
    int n; cin >> n;
    ll res = 0;
    vt<string> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        (b[i][1] == '+' ? res++ : res--);
    }
    cel(res);
}

void sol(){
    int k, n, w; cin >> k >> n >> w;    
    for (int i = 1; i <= w; i++) n -= i*k;
    cel((n < 0? -n : 0));
}   

void sol2(){
    int k, n, w; cin >> k >> n >> w;    
    ll total_cost = k * w * (w + 1) / 2;
    cel((n < total_cost ? total_cost - n : 0));
}   

int main()
{
    fast_io;
    test();

    return 0;
}