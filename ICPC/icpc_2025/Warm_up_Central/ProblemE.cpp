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

int isPrime(ll n) {
    if (n <= 1) return -1;
    if (n == 2 || n == 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return -1;

    for (ll i = 5; 1LL * i * i <= n; i+=6)
        if (n % i == 0 || n % (i + 2) == 0) 
            return -1;
    return 1;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    int cnt = 0;
    int np_cnt = 0;
    for(int &x:a) cin >> x;

    for (int i = 0; i < a.size(); i++) {
        a[i] = isPrime(a[i]);
        if(a[i] == -1) np_cnt++;
    }
    
    if(np_cnt <= 1) 
        cout << n * (n + 1) / 2 - np_cnt << endl;
    else {
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += a[j];
                if(sum >= 0) {
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
}

// Fenwick Tree (BIT)
struct Fenwick {
    vector<ll> bit;
    int n;
    Fenwick(int n) : n(n), bit(n + 1, 0) {}
    void add(int idx, ll val) {
        for (++idx; idx <= n; idx += idx & -idx) bit[idx] += val;
    }
    ll sum(int idx) {
        ll res = 0;
        for (++idx; idx > 0; idx -= idx & -idx) res += bit[idx];
        return res;
    }
    ll range_sum(int l, int r) {
        return sum(r) - (l ? sum(l - 1) : 0);
    }
};

// Sieve of Eratosthenes
vector<char> sieve(int n) {
    vector<char> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; 1LL * i * i <= n; i++)
        if (is_prime[i])
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
    return is_prime;
}

void solve2() {
    int n;
    cin >> n;
    vector<int> a(n);
    int maxA = 0;
    for (int &x : a) {
        cin >> x;
        maxA = max(maxA, x);
    }

    vector<char> is_prime = sieve(max(2, maxA));

    // map 1 ↦ -1, prime ↦ +1, else ↦ -1
    int np_cnt = 0;
    for (int &x : a) {
        if (x <= 1 || !is_prime[x]) {
            x = -1;
            np_cnt++;
        } else x = 1;
    }

    if (np_cnt <= 1) {
        cout << 1LL * n * (n + 1) / 2 - np_cnt << '\n';
        return;
    }

    // prefix sums + coordinate compression
    vector<ll> pref(n + 1, 0);
    for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + a[i];

    vector<ll> vals = pref;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    Fenwick bit(vals.size());
    ll cnt = 0;

    for (int i = 0; i <= n; i++) {
        int idx = lower_bound(vals.begin(), vals.end(), pref[i]) - vals.begin();
        cnt += bit.sum(idx); // đếm prefix[j] <= prefix[i]
        bit.add(idx, 1);
    }

    cout << cnt << '\n';
}

// ========== BINARY INDEXED TREE ==========
int getSum(int BITree[], int index) {
    int sum = 0;
    index = index + 1;
    while (index > 0) {
        sum += BITree[index];
        index -= index & (-index);
    }
    return sum;
}

void updateBIT(int BITree[], int n, int index, int val) {
    index = index + 1;
    while (index <= n) {
        BITree[index] += val;
        index += index & (-index);
    }
}

int *constructBITree(int n) {
    int *BITree = new int[n + 1];
    for (int i = 1; i <= n; i++) BITree[i] = 0;
    return BITree;
}

void solve3() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    // 1️⃣ Chuyển sang +1 hoặc -1
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        b[i] = (isPrime(a[i]) == 1 ? 1 : -1);

    // 2️⃣ Prefix sum
    vector<ll> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + b[i - 1];

    // 3️⃣ Nén giá trị prefix để index hóa BIT
    vector<ll> vals = pref;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    auto getId = [&](ll x) {
        return int(lower_bound(vals.begin(), vals.end(), x) - vals.begin());
    };

    int m = vals.size();
    int *BITree = constructBITree(m);

    // 4️⃣ Duyệt qua từng prefix, đếm số prefix <= prefix[i]
    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        int id = getId(pref[i]);
        ans += getSum(BITree, id);
        updateBIT(BITree, m, id, 1);
    }

    cout << ans << "\n";
}

int main () {
    fast_io;
    solve3();
    
    return 0;
}