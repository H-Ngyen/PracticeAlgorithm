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

bool divby13(string s) {
    int n = 0;
    for (char c : s) n = (n * 10 + (c - '0')) % 13;
    dbg(n);
    return n == 0;
}

bool divby13_2(string &s) {
    long long n = stoi(s);
    return n % 13 == 0;
}

int main () {
    //46465396726998134418
    //13393762137886793
    //2911285
    string s = "13393762137886793";
    cout << divby13(s) << endl;
    // cout << divby13("46465396726998134418") << endl;

    // cout << findDivisors(8) << endl;
    
    // for(int i = 1; i <= 100000; i++) {
    //     if(findDivisors(i)) cout << i << endl;
    // }
    // cout << sqrt(8) << endl;
    return 0;
}