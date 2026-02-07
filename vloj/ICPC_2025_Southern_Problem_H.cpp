#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
// #pragma GCC target("avx2,tune=native")
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);
using ll = long long;

const int INF = (int)1e9;
const int NEG_INF = (int)-1e9;
void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    ll product = 1;
    int zero_count = 0, neg_count = 0;
    ll max_val = NEG_INF, min_val = INF;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0) {
            zero_count++;
        } 
        else {
            product *= a[i];
        }
        if (a[i] < 0) neg_count++;
        max_val = max(max_val, a[i]);
        min_val = min(min_val, a[i]);
    }

    if (zero_count >= 2) {
        ll max_product = NEG_INF;
        vector<ll> candidates;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) continue;
            ll curr_product = product / a[i];
            if (curr_product > max_product) {
                max_product = curr_product;
                candidates.clear();
                candidates.push_back(a[i]);
            } 
            else if (curr_product == max_product) {
                candidates.push_back(a[i]);
            }
        }
        if (max_product <= 0) {
            cout << 0 << " " << 0 << endl;
        } 
        else {
            ll luna = *max_element(candidates.begin(), candidates.end());
            ll thana = *min_element(candidates.begin(), candidates.end());
            cout << luna << " " << thana << endl;
        }
        return;
    }

    ll max_product = NEG_INF;
    vector<ll> candidates;
    for (int i = 0; i < n; i++) {
        ll curr_product;
        if (a[i] == 0) {
            curr_product = product;
        } 
        else {
            curr_product = product / a[i];
        }
        if (curr_product > max_product) {
            max_product = curr_product;
            candidates.clear();
            candidates.push_back(a[i]);
        } 
        else if (curr_product == max_product) {
            candidates.push_back(a[i]);
        }
    }

    ll luna = *max_element(candidates.begin(), candidates.end());
    ll thana = *min_element(candidates.begin(), candidates.end());
    cout << luna << " " << thana << endl;
}

signed main() {
    fast_io
    solve();
}