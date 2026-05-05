#include<bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);

class Solution {
public:
    // vector<int> getConcatenation(vector<int>& nums) {
    //     vector<int> results = nums;
    //     for (int &num : nums) {
    //         results.push_back(num);
    //     }
    //     return results;
    // }
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> results = nums;
        results.insert(results.end(), nums.begin(), nums.end());
        return results;
    }
};

void solve() {
    Solution sol;
    vector<int> nums = {1,2,1};
    vector<int> results = sol.getConcatenation(nums);
    for (int &result : results)
    {
        cout << result << ' ';
    }
}

signed main() {
    fast_io
    solve();
}