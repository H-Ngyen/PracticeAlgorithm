#include <bits/stdc++.h>
using namespace std;

bool isAnagram_bruteForce(string s, string t) {
    if((int)s.size() != (int)t.size()) return false;
    int string_size = (int)s.size();
    for (int i = 0; i < string_size; i++) {
        bool ok = false;
        for (int j = 0; j < string_size; j++) {
            if (s[i] == t[j]) {
                t[j] = '#';
                ok = true;
                break;
            }
        }
        if(!ok) return false;
    }
    return true;
}

bool isAnagram_sorting(string s, string t) {
    if((int)s.size() != (int)t.size()) return false;
    sort(s.begin(), s.end());
    sort(t.begin(),t.end());
    for (int i = 0; i < (int)s.size(); i++)
        if(s[i] != t[i]) 
            return false;
    return true;
}

bool isAnagram(string s, string t) {
    if((int)s.size() != (int)t.size()) return false;
    unordered_map<char, int> freq;
    for (char &c:s) freq[c]++;

    for (char &c:t) {
        freq[c]--;
        if(freq[c] < 0) return false;
    }
    return true;
}

void solve() {
    string s , t;
    s = "rat";
    t = "car";
    cout << isAnagram(s, t) << endl;
}

signed main() {
    solve();
}