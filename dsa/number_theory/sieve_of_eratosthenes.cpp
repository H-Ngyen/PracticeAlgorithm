#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);
using ll = long long;

const int MAXN = (int)1e7;
bool isPrime[MAXN];

// time : O(nlog(log(n)))
// space: O(n)
void sieve (int n) {
    fill(isPrime, isPrime + n, 1);
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i * i <= n; i++) {
        if(isPrime[i]) {
            for (int j = i * i; j <= n; j+=i) {
                isPrime[j] = 0;
            }
        }
    }
}
 
// time : O(sqrt(n))
// space: O(1)
bool checkPrime(int n) {
    if(n == 2 || n == 3) return 1;
    if(n <= 1 || n % 2 == 0 || n % 3 == 0) return 0;
    for (int i = 5; 1LL * i * i <= n; i+=6) {
        if(n % i == 0 || n % (i + 2) == 0) {
            return 0;
        }
    }
    return 1;
}

void testCheckPrime(ll n, ll repeats) {
    auto start = chrono::high_resolution_clock::now();
    ll cnt = 0;
    for (ll i = 0; i < repeats; i++) {
        cnt += checkPrime(n);
    }
    auto end = chrono::high_resolution_clock::now();
    cout << "[checkPrime] n=" << n 
         << " repeated " << repeats 
         << " times: " 
         << chrono::duration<double, milli>(end - start).count() << " ms\n";
}

void testSieve(int n) {
    auto start = chrono::high_resolution_clock::now();
    sieve(n);
    auto end = chrono::high_resolution_clock::now();
    cout << "[sieve] up to " << n 
         << ": " 
         << chrono::duration<double, milli>(end - start).count() << " ms\n";
}

void solve() {
    // testCheckPrime(1e9, MAXN);
    testSieve(MAXN);
}

signed main() { 
    fast_io
    solve();
}