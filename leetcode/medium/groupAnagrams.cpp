#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("avx2,tune=native")
#include<bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> results; 
        unordered_map<string, vector<string>> sorted;
        for(string &str:strs) {
            string unSort = str;
            sort(str.begin(), str.end());
            sorted[str].push_back(unSort); 
        }
        for (auto const &it: sorted)
            results.push_back({it.second});

        return results;
    }

    // static unordered_map<string, vector<string>> SortElementStrs(vector<string> &strs) {
    //     unordered_map<string, vector<string>> results;
    //     for (string &str:strs) {
            
    //     }
        
        
    //     return results;
    // }
};

void solve() {
    Solution sol;
    vector<string> strs  = {"eat","tea","tan","ate","nat","bat"};
    // vector<string> strs  = {"","",""};
    vector<vector<string>> results = sol.groupAnagrams(strs);
    for (int i = 0; i < (int)results.size(); i++) {
        for (int j = 0; j < (int)results[i].size(); j++) {
            cout << results[i][j] << ", ";
        }
        cout << endl;
    }
}

signed main () {
    fast_io
    solve();
    // string s1 = "eat";
    // string s2 = "ate";
    // sort(s1.begin(), s1.end());
    // sort(s2.begin(), s2.end());
    // cout << (s1 == s2 ? "YES" : "NO");
    // cout << s1;
}