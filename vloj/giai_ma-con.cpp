#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);
using ll = long long;

void solve() {
    int tt; cin >> tt;
    while (tt--) {
        string s, c; cin >> s >> c;
        int n = c.size(), count = 0;
        for (int i = 0; i <= (int)s.size() - n; i++) {
            if(s.compare(i,n,c) == 0) count++;
        }
        cout << count << endl;
    } 
}

bool compareCus(int pos, int size, string &s1, string &s2) {
    int i = 0, end = pos + size;
    for (; pos < end; pos++) {
        if (s1[pos] != s2[i++]) return false;
    }
    return true;
}

void solve2() {
    int tt; cin >> tt;
    while(tt--) {
        string s, c; cin >> s >> c;
        int count = 0;
        size_t pos = s.find(c, 0);
        while (pos != string::npos) {
            count++;
            pos = s.find(c,pos + 1);
        }
        cout << count << endl;
    }
}

signed main() {
    fast_io
    solve2();
}