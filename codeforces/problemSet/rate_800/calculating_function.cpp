#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(false); cout.tie(nullptr); cin.tie(nullptr);
using ll = long long;

const ll MOD = 1e9 + 7;

void solve() {
    ll n; cin >> n;
    ll ans = 0;
    if(n & 1) {
        ll cnt_e = n / 2;
        ll cnt_o = cnt_e + 1;
        ans = (1LL * cnt_e * ((n + 1) / 2)) - (1LL * cnt_o * ((n + 1) / 2));
    }
    else {
        ll cnt_e = n / 2;
        ll cnt_o = cnt_e;
        ans = (1LL * cnt_e * ((n + 2) / 2)) - (1LL * cnt_o * (n / 2) );
    }
    cout << ans << endl; 
}

void solve2() {
    ll n; cin >> n;
    ll ans = (n & 1 ? -(n + 1) / 2 : n / 2);
    cout << ans << endl;
}

int main () {
    fast_io
    solve2();

    return 0;
}