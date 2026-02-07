#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
// #pragma GCC target("avx2,tune=native")
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);
using ll = long long;

class NumArray {
private:
    vector<int> _BIT;
    vector<int> _a;
    int _MAXN;
    
    int get(int pos) {
        int sum = 0;
        for(int i = pos + 1; i ; i -= i & -i) sum += _BIT[i];
        return sum;
    }
public:
    NumArray(vector<int>& nums) {
        _MAXN = nums.size() + 5;
        _BIT.assign(_MAXN, 0);
        _a.assign(_MAXN, 0);
        for(int i = 0; i < nums.size(); i++) update(i, nums[i]); 
    }
    
    void update(int pos, int val) {
        int v = val - _a[pos];
        _a[pos] = val;
        for(int i = pos + 1; i < _MAXN; i += i & -i) _BIT[i] += v;    
    }
    
    int sumRange(int left, int right) {
        return get(right) - get(left - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

void solve() {
    vector<int> a = {1, 3, 5};
    NumArray* BIT = new NumArray(a);
    cout << BIT->sumRange(0,2) << endl;
    BIT->update(1,2);
    cout << BIT->sumRange(0,2) << endl;
    delete BIT;
}

signed main() {
    fast_io
    solve();
}