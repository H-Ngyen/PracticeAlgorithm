#include<bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(0); cin.tie(0);
using ll = long long;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = (int)nums.size();
        unordered_map<int, int> hashMap(n);
        for (int i = 0; i < n; i++) {
            if(hashMap.find(target - nums[i]) != hashMap.end()) 
                return {hashMap[target - nums[i]], i};
            hashMap[nums[i]] = i;
        }
        return {};
    }
};

void solve() {
    Solution sol;
    vector<int> nums = {2, 7, 11 ,15};
    int target = 9;
    vector<int> results = sol.twoSum(nums, target);
    for(auto &result : results) {
        cout << result << ' ';
    }
}

signed main () {
    fast_io
    solve();
}