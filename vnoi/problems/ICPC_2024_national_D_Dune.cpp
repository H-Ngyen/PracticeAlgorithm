#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
// #pragma GCC target("avx2,tune=native")
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);

unordered_map<int, string> hashmap = {{0, "Guiding Beat"}, {1, "Warning Beat"}, {2, "Resting Phase"}};
void solve() {
    int T; cin >> T;
    while (T--) {
        vector<float> v(4);
        for(float &x : v) cin >> x;
        v[3] += 0.5;

        double currV = 0;
        int i = 0;
        while (currV + v[i] < v[3]) {
            currV += v[i];
            i = (i + 1) % 3 ;
        }
        cout << hashmap[i] << endl;
    }
}

void solve2() {
    int T; cin >> T;
    while(T--) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        int t = (2LL * d + 1) % (2LL * (a + b + c));
        if (t < 2LL * a) cout << hashmap[0] << endl;
        else if (t < 2LL * (a + b)) cout << hashmap[1] << endl;
        else cout << hashmap[2] << endl;
    }
}

signed main() {
    fast_io
    solve();
}