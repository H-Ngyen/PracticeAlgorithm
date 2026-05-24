#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        unordered_map<int, int> nums_count;
        vector<int> results;
        for(int &num:arr) {
            nums_count[num]++;
            if(nums_count[num] == 2) results.push_back(num);
        } 
        return results;
    }

    vector<int> findDuplicates_sorting(vector<int>& arr) {
        vector<int> results; 
        sort(arr.begin(), arr.end());
        for (int i = 1; i < (int)arr.size(); i++) {
            if(arr[i] == arr[i - 1]) 
                results.push_back(arr[i++]);
        }
        return results;
    }
};

void solve() {
    Solution sol;
    vector<int> input = {2, 3, 1, 2, 3}; 
    // vector<int> input = {3, 2, 1}; 
    // vector<int> input = {1, 2, 2, 5, 4};
    vector<int> results = sol.findDuplicates_sorting(input);
    for(int &result:results) {
        cout << result << ' ';
    } 
}

signed main() {
    fast_io 
    solve();
}