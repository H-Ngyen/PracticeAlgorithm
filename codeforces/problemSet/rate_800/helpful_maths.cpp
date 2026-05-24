#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

void solve_hashmap() {
    string s; cin >> s;
    string results;
    unordered_map<char, int> words;
    for(char &c:s) {
        words[c]++;
    }
    int first = words['1'], 
        second = words['2'],
        third = words['3'],
        total = first + second + third;  

    while(total--) {
        if(first != 0) {
            results.push_back('1');
            first--;
        }
        else if (second != 0) {
            results.push_back('2');
            second--;
        } 
        else {
            results.push_back('3');
            third--;
        } 
    }
    int n = (int)results.size();
    for(int i = 0; i < n; i++) {
        if (i + 1 == n) cout << results[i];
        else cout << results[i] << '+';
    }
}

void solve() {
    string s; cin >> s;
    vector<int> results; 
    int count = 0;
    for (char &c:s)  {
        if(c == '+') continue;
        else {
            results.push_back(c - '0');
            count++;
        } 
    }
    sort(results.begin(), results.end());
    for(int &result:results) {
        if(count == 1) cout << result << endl;
        else {
            cout << result << '+';
            count--;
        }
    }
}

signed main() {
    fast_io
    solve();
}