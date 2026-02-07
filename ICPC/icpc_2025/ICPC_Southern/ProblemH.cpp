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
    int n;
    cin >> n;
    vector<ll> a(n);
    ll product = 1;
    int zero_count = 0, neg_count = 0;
    ll max_val = LLONG_MIN, min_val = LLONG_MAX;

    // Đọc dãy và tính tích, đếm số 0, số âm, tìm max/min
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0) {
            zero_count++;
        } else {
            product *= a[i];
        }
        if (a[i] < 0) neg_count++;
        max_val = max(max_val, a[i]);
        min_val = min(min_val, a[i]);
    }

    // Nếu có >= 2 số 0, tích sau khi xóa số 0 là 0
    if (zero_count >= 2) {
        ll max_product = LLONG_MIN;
        vector<ll> candidates;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) continue;
            ll curr_product = product / a[i];
            if (curr_product > max_product) {
                max_product = curr_product;
                candidates.clear();
                candidates.push_back(a[i]);
            } else if (curr_product == max_product) {
                candidates.push_back(a[i]);
            }
        }
        if (max_product <= 0) {
            cout << 0 << " " << 0 << "\n";
        } else {
            ll luna = *max_element(candidates.begin(), candidates.end());
            ll thana = *min_element(candidates.begin(), candidates.end());
            cout << luna << " " << thana << "\n";
        }
        return;
    }

    // Trường hợp thông thường: tìm tích tối đa
    ll max_product = LLONG_MIN;
    vector<ll> candidates;
    for (int i = 0; i < n; i++) {
        ll curr_product;
        if (a[i] == 0) {
            curr_product = product;
        } else {
            curr_product = product / a[i];
        }
        if (curr_product > max_product) {
            max_product = curr_product;
            candidates.clear();
            candidates.push_back(a[i]);
        } else if (curr_product == max_product) {
            candidates.push_back(a[i]);
        }
    }

    ll luna = *max_element(candidates.begin(), candidates.end());
    ll thana = *min_element(candidates.begin(), candidates.end());
    cout << luna << " " << thana << "\n";
}

int main () {
    fast_io;
    solve();
    return 0;
}