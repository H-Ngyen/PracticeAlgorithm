#include <bits/stdc++.h>
using namespace std;
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

void solve() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<vector<int>> used;

        // Truy vấn từng block hoán vị
        for (int i = 0; i < N; ++i) {
            vector<int> perm(6);
            for (int j = 0; j < 6; ++j) {
                cout << "? " << (i * 6 + j + 1) << endl;
                cout.flush();
                cin >> perm[j];
            }
            used.push_back(perm);
        }

        // Sắp xếp để dùng binary_search
        sort(used.begin(), used.end());

        // Duyệt tất cả hoán vị của 1..6
        vector<int> candidate = {1, 2, 3, 4, 5, 6};
        do {
            if (!binary_search(used.begin(), used.end(), candidate)) {
                cout << "! ";
                for (int x : candidate) cout << x << " ";
                cout << endl;
                cout.flush();
                break;
            }
        } while (next_permutation(candidate.begin(), candidate.end()));
    }
}

int main() {
    solve();

    return 0;
}