#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(false); cout.tie(nullptr); cin.tie(nullptr);

const long long MOD = 1e9 + 7;

int isDivisibleBy10(string bin) {
    long long sum1 = 0, sum2 = 0;
    int n = bin.size();

    int i = n - 1;
    for (char c:bin) {
        long long t = c - '0';
        if(i == n/2 - 1)
            sum1 += (1LL * t * (1LL << i ));
        else
            sum2 += (1LL * t * (1LL << i ));
        i--;
    }
    return (sum1 % 10 + sum2 % 10) % 10 == 0;    
}

int isDivisibleBy10_1(string bin) {
    long long sum = 0;

    // int i = bin.size() - 1;
    for (int i = bin.size() - 1; i >= 0; i--) {
        int t = (bin[i] - '0');
        sum += (t * (1 << i--));
    }
    return sum % 10 == 0;    
}

int main () {
    fast_io
    string s; cin >> s;
    cout << isDivisibleBy10(s) << endl;
    // cout << 2 % 10 << endl;
    return 0; 
}