#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
// #pragma GCC target("avx2,tune=native")
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);

void solve() {
    string s1, s2; cin >> s1 >> s2;
    if(s1[0] == 'R') {
        if(s2[0] == 'R') cout << "Draw" << endl;
        else if (s2[0] == 'S') cout << "Player 1" << endl; 
        else cout << "Player 2" << endl;
    }
    else if(s1[0] == 'S') {
        if(s2[0] == 'S') cout << "Draw" << endl;
        else if (s2[0] == 'P') cout << "Player 1" << endl;
        else cout << "Player 2" << endl;
    }
    else {
        if(s2[0] == 'P') cout << "Draw" << endl;
        else if (s2[0] == 'R') cout << "Player 1" << endl;
        else cout << "Player 2" << endl;
    }
}

signed main() {
    fast_io
    solve();
}