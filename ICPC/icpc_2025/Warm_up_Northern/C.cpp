#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O2")
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

void solve() {
    long long N, L; cin >> N >> L;
    vector<long long> a(N);
    for(int i=0;i<N;i++) cin >> a[i];

    vector<long long> mins(N), maxs(N);
    vector<long long> pts;
    pts.reserve(2*N + 1);
    for(int i=0;i<N;i++){
        long long m = min(a[i], L - a[i]);
        long long M = max(a[i], L - a[i]);
        mins[i] = m;
        maxs[i] = M;
        pts.push_back(m);
        pts.push_back(M);
    }
    pts.push_back(0);
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());

    sort(mins.begin(), mins.end());
    sort(maxs.begin(), maxs.end());

    int idx_min_le = 0;
    int idx_max_le = 0; 
    long double ans = 0.0L;
    long long prev = 0;

    while(idx_min_le < N && mins[idx_min_le] <= prev) idx_min_le++;
    while(idx_max_le < N && maxs[idx_max_le] <= prev) idx_max_le++;

    for(size_t k = 0; k < pts.size(); ++k){
        long long t = pts[k];
        if(t > prev){
            long double G;
            if(idx_min_le < N){
                G = 0.0L;
            } else {
                int m = N - idx_max_le;
                if(m == 0) G = 1.0L;
                else {
                    G = powl(0.5L, (long double)m);
                }
            }
            long double d = (long double)(t - prev);
            ans += d * (1.0L - G);
        }
        prev = t;
        while(idx_min_le < N && mins[idx_min_le] <= prev) idx_min_le++;
        while(idx_max_le < N && maxs[idx_max_le] <= prev) idx_max_le++;
    }

    cout << (double)ans << "\n";
}

signed main () {
    fast_io;
    solve();
}