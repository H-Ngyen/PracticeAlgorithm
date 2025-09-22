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

void sol(){
    ll T; cin >> T;
    while (T--)
    {
        vt<ll> v(9);
        ll ans = 0;
        for (int i = 0; i < 9; i++) {
            cin >> v[i];
            ans += v[i];
        }
        cel(55 - ans);
    }
}

void solve(){
    ll T; cin >> T;
    while (T--)
    {
        vt<ll> v(9);
        for (int i = 0; i < 9; i++) cin >> v[i];
        sor(v);
        for (int i = 0; i < 9; i++){
            if(v[8] != 10){
                cel(10);
                break;
            }
            if(v[i] != i+1) {
                cel(i+1);
                break;
            }
        }
    }
}

int main()
{
    fast_io;
    sol();
    
    return 0;
}