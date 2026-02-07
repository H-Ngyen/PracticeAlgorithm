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

bool isPalindrome(int n) {
    vector<int> v;
    while (n) {
        v.push_back(n % 10);
        n /= 10;
    }
    for (int i = 0; i < int(v.size() / 2); i++) {
        if (v[i] != v[v.size() - 1 - i])
            return 0;
    }
    return 1;
}

// đảo n lại rồi so sánh số vừa đảo với n
bool isPalindrome2(int n) {
    int t = n;
    int res = 0;
    while (t) {
        res = res * 10 + t % 10;
        t /= 10;
    }
    return res == n;
}


int main() {
    cout << isPalindrome(555) << endl;
    return 0;
}