#include <bits/stdc++.h>
using namespace std;

vector<string> AllPossibleStrings(string s) {
    long long n = s.size();
    vector<string> ans;
    for (int i = 1; i < (1LL << n); i++) {
        string sub = "";
        for (int j = 0; j < n; j++) 
            if(i & (1 << j)) sub += s[j]; 
        ans.push_back(sub);
    }
    sort(ans.begin(), ans.end());
    return ans;            
}

int main () {
    string s; cin >> s;
    vector<string> res = AllPossibleStrings(s);
    for (auto r:res) cout << r << ' ';
    return 0;
}