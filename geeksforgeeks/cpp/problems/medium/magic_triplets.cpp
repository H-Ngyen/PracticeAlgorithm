// Desc: Counts the number of "magic triplets" in the array, where a triplet (i, j, k) satisfies:
//  *       i < j < k and nums[i] < nums[j] < nums[k].
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);

/**
 * Solution: For each element nums[i], treat it as the middle of a potential triplet.
 *           Use a Fenwick Tree (Binary Indexed Tree) to count:
 *           - left[i]: number of elements before i that are less than nums[i]
 *           - right[i]: number of elements after i that are greater than nums[i]
 *           The total number of valid triplets is the sum of left[i] * right[i] for all i.
 *
 * Time complexity: O(n log MAXN)
 * Space complexity: O(MAXN)
 */
const int MAXN = (int)1e5;
int BIT[MAXN + 5];
int n;

void update(int i, int v) { for( ; i <= MAXN; i += i & -i) BIT[i] += v; }
   
int query(int i) {
    int res = 0;
    for ( ; i ; i -= i & -i) res += BIT[i];
    return res;
}

int countTriplets_fenwickTree(vector<int> nums) {
    n = nums.size();
    int left[n + 1], right[n + 1];
        
    fill(BIT, BIT + MAXN + 5, 0);
    for (int i = 1; i <= n; i++) {
        int x = nums[i - 1];
        left[i] = query(x - 1);
        update(x, 1);
    }
        
    fill(BIT, BIT + MAXN + 5, 0);
    for (int i = n; i ; i--) {
        int x = nums[i - 1];
        right[i] = query(MAXN) - query(x);
        update(x, 1);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) ans += left[i] * right[i];
    return ans;
} 

/**
 * Solution: For each element at index j, count how many elements before it are smaller (left),
 *           and how many elements after it are larger (right). The number of valid triplets
 *           with nums[j] as the middle element is left * right. Sum over all j.
 *
 * Time complexity: O(n^2)
 * Space complexity: O(1)
 */
int countTriplets(vector<int> nums) {
    int res = 0, n = nums.size();
    for (int j = 0; j < n; j++) {
        int left = 0, right = 0;
        for(int i = 0; i < j; i++)
            if(nums[j] > nums[i]) left++;
        for (int k = j + 1; k < n; k++)
            if(nums[j] < nums[k]) right++;
        res += left * right;
    }
    return res;
}

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for(int &x : v) cin >> x;
    cout << countTriplets_fenwickTree(v) << endl;
}

signed main() {
    fast_io
    solve();
}