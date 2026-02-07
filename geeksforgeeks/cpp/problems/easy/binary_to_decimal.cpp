#include <bits/stdc++.h>
using namespace std;

int binaryToDecimal(string &b) {
    int n = b.size();
    int t = n, ans= 0;
    
    while (t--)
        if (b[t] & 1) ans += (1LL << (n - 1 - t));
    return ans;
}
    // for (int i = 0; i < n; i++) {
    //     if(b[i] & (1 << i)) ans += (1 << i); 
    // }
int main() {
    string s; cin >> s;
    cout << binaryToDecimal(s) << endl;
    return 0;
}