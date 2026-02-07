#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}

vector<int> primeFac(int n) {
    vector<int> ans;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) {
            if (isPrime(i)) ans.push_back(i);
            if (i != n / i && isPrime(n / i)) ans.push_back(n / i);
        }
    sort(ans.begin(), ans.end());
    return ans.empty() ? vector<int> {n} : ans;
}

int main () {
    int n; cin >> n;
    vector<int> res = primeFac(n);
    for(int x:res) cout << x << ' ';
    // cout << isPrime(37) << endl;
    // cout << sqrt(1e6) << endl;
    return 0;
}