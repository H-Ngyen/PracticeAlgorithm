#include<bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);

class Solution {
public:
    // time: O(n)
    // avg space: O(n)
    // worst space: O(n*n) 
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> hashMap;
        for (int &num : nums)
        {
            if(hashMap.contains(num)) return true;
            hashMap[num]++;
        }
        return false;
    }

    // time: O(nlogn)
    // space: O(1)
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < (int)nums.size(); i++)
            if(nums[i - 1] == nums[i]) return true;
        return false;
    }
};

void solve() {
    Solution sol;
    vector<int> nums = {1,2,3,1};
    bool isDuplicate = sol.containsDuplicate(nums);
    cout << (isDuplicate ? "YES" : "NO");
}

signed main() {
    fast_io
    solve();
}