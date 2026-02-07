#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return 0;
    for (long long i = 2; i <= sqrt(n); i++) 
        if (n % i == 0) return 0;
    return 1;
}

int main () {
    cout << isPrime(INT32_MAX) << endl;
    return 0;
}