#include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC optimize("O2")
#define fast_io ios::sync_with_stdio(false); cout.tie(nullptr); cin.tie(nullptr);
int gcd(int n) {
    
}

void print_divisors(int n) {
    set<long long> s;
    for (long long i = 1; i <= n / 2; i++) {
        if(n % i == 0) {
            s.insert(i);
            if (i != n / i) s.insert(n / i);
        }
    }
    for (int x: s) cout << x << ' ';
}

int main () {
    fast_io
    int n; cin >> n;
    print_divisors(n);
}