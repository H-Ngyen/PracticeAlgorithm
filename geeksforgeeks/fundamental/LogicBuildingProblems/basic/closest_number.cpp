#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

//O(m)
void solve() {
    int n, m; cin >> n >> m;
    int ans = 0;
    int min = 1e9;
    for (int i = n - abs(m); i <= n + abs(m); i++) {
        if(i % m == 0) {
            int curr = abs(n - i);
            if (min > curr || min == curr && abs(i) > abs(ans)) {
                min = curr;
                ans = i;
            }
        }
    }
    cout << ans << endl;
}

// O(1)
void solve2() {
    int n, m; cin >> n >> m;
    
    int t = n / m;
    int f_ans = m*t;
    int s_ans = m * n > 0 ? m * (t + 1) : m * (t - 1);
    
    if (abs(n - f_ans) < abs(n - s_ans)) {
        cout << f_ans << endl;
        return;
    }
    cout << s_ans << endl;
}

void test() {
    cout << sin(1) << endl;
}

int main() {
    test();
    // cout << -2 * 2 << endl;

    return 0;
}