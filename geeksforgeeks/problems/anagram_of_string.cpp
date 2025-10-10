#include <bits/stdc++.h>
using namespace std;

int remAnagram(string& s1, string& s2) {
    unordered_map<char, int> hm;
    int ans = 0;
    for (char &c:s1) hm[c]++;
    for (char &c:s2) hm[c]--;
    
    for (auto x : hm) ans += abs(x.second);
    return ans;
}

int main() {
    string s1, s2; cin >> s1 >> s2;
    cout << remAnagram(s1,s2) << endl;
    return 0;
}