#include <bits/stdc++.h>
using namespace std;

// sliding window
vector<int> subarraySum(vector<int> &arr, int target) {
    int ans = 0, left = 0;
    for (int right = 0; right < arr.size(); right++) {
        ans += arr[right];
        while (ans > target && right < arr.size()) {
            ans -= arr[left];
            left++;
        }
        if (ans == target)
            return {left + 1, right + 1};
    }
    return {-1};
}

int main() {

    return 0;
}