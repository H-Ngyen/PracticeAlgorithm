#include <bits/stdc++.h>
using namespace std;

int isPrime(int n) {
    if(n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) 
        if(n % i == 0) return 0;
    return 1;
}

int largestPrimeFactor(int n) {
    int ans = -1;

    if (n % 2 == 0) ans = 2;
    for (int i = 3; i <= n / 2; i+=2)
        if (n % i == 0) {
            if (isPrime(i)) ans = max(ans, i);
            if (i != n / i && isPrime(n/i)) ans = max(ans, n/i);
        }
    if (ans == -1 && isPrime(n)) ans = n;
    return ans;
}

int largestPrimeFactor2(int n) {
    int ans = -1;
    while (n % 2 == 0) {
        ans = 2;
        n /= 2;
    }
    
    for (int i = 3; i * i <= n; i+=2) 
        while (n % i == 0) {
            n /= i;
            ans = i;
        }
    
    if(n > 2) ans = n;

    return ans;
}

int main () {
    int n; cin >> n;
    cout << largestPrimeFactor2(n) << endl;
    // cout <<  powl(7,1) << endl;
    return 0;
}