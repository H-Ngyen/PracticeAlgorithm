#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);
using ll = long long;

const int MAXN = (int)1e6;
const int INF = (int)1e9;
bool check;

bool isPrime(ll n) {
    if(n == 2 || n == 3) return 1;
    if(n <= 1 || n % 2 == 0 || n % 3 == 0) return 0;
    for (ll i = 5; i *  i <= n; i+=6) {
        if(n % i == 0 || n % (i + 2) == 0) {
            return 0;
        }
    }
    return 1;
}
void solve() {
    int T; cin >> T;
    while(T--) {
        ll n, ans = 0; cin >> n;
        check = 1;
        if(!isPrime(n)) check = 0;
        else {
            int k = sqrt(n);
            int min = INF;

            for(int i = n - 2; i >= n - k; i-=2) {
                if(isPrime(i)) {
                    min = abs(n - i);
                    ans = i;
                    break;
                }
            }

            for(int i = n + 2; i <= n + k; i+=2) {
                if(isPrime(i)) {
                    int curr = abs(n-i);
                    if(min > curr || (min == curr && i < ans)) ans = i;
                    break;
                }
            }
        }
        if(check) cout << "YES" << ' ' << ans << endl;
        else cout << "NO" << endl;
    }
}

signed main() {
    fast_io
    // solve();

    // cout <<isPrime(1LL * 1e18);
    // cout << sqrt(97) << endl;
    // cout << 97 + 9 << endl;
    cout << (long long)sqrt(1LL * 1e18) << endl;
    cout << 97 + 9 << endl;
}