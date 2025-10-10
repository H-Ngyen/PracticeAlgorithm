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

int pairCubeCount(int n) {
    int limit = cbrt(abs(n)), ans = 0;
    for (int i = 1; i <= limit; i++) {
        int j = cbrt(n - i*i*i);
        if (i*i*i + j*j*j == n) 
        {
            ans++;
            dbg(i, j);
        }
    }
    return ans;
}

int main () {
    cout << pairCubeCount(1729) << endl;
    // cout << cbrt(3088)<< endl;
    return 0;
}