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

// brute force 
// O(n^2)
bool isSubset(vector<int> &a, vector<int> &b) {
    bool ans;
    for (int i = 0; i < b.size(); i++) {
        ans = 0;
        for (int j = 0; j < a.size(); j++) {
            if(b[i] == a[j]) {
                ans = 1;    
                a[j] = -1;
                break;
            }
        }
        if(!ans) break;
    }
    return ans;
}

// binary search
// O(mn)
bool isSubset2(vector<int> &a, vector<int> &b) {
    sort(a.begin(), a.end());
    for (int i = 0; i < b.size(); i++) {
        auto it = lower_bound(a.begin(), a.end(), b[i]);
        if(*it == b[i])
            a.erase(it);
        else
            return 0;
    }
    return 1;
}

bool isSubset3(vector<int> &a, vector<int> &b) {
    unordered_multiset<int> ms(a.begin(), a.end());
    for (int i = 0; i < b.size(); i++) {
        auto it = ms.find(b[i]);
        if (it != ms.end())
            ms.erase(it);
        else 
            return 0;
    }
    return 1;
}

int main() {
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for (int &x : a) cin >> x;
    // dbg(a);
    for (int &x : b) cin >> x;
    // isSubset3(a,b);
    // dbg(b);
    cout << (isSubset3(a, b) ? "true" : "false") << endl;
    return 0;
}