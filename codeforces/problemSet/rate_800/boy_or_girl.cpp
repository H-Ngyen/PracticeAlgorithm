#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

void solve() {
    string userName; cin >> userName;
    unordered_set<char> diffChar;
    diffChar.insert(userName.begin(), userName.end());
    
    int count = diffChar.size();
    cout << (count % 2 != 0 ? "IGNORE HIM!" : "CHAT WITH HER!") << endl;
}

signed main() {
    fast_io
    solve();
        // std::cout << __cplusplus << '\n';

}