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

//O(n)
int divisibleBy4(string N) {
    long long n = 0;
    for (char c : N) n = (n * 10 + (c - '0')) % 4;
    return n == 0;
}

//O(1)
// solution: Một số chia hết cho 4 nếu số được tạo bởi hai chữ số cuối của nó chia hết cho 4. 
// Ví dụ: xét số 76952. Số được tạo bởi hai chữ số cuối = 52. Vì 52 chia hết cho 4, nên đáp án là CÓ.
int divisibleBy4_1(string N) {
    int n = N.size();
    if (n == 1) return (N[0] - '0') % 4 == 0;

    int f = N[n - 1] - '0';
    int s = N[n - 2] - '0';

    return (s * 10 + f) % 4 == 0;
}

void solve() {
    cout << divisibleBy4("1124") << endl;
}

int main()
{
    fast_io;
    solve();
    return 0;
}