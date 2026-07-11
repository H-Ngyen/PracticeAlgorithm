#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);
using ll = long long;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    vector<int> linkListToArray(ListNode *node) {
        vector<int> res;
        while(node != nullptr) {
            res.push_back(node->val);
        }
        reverse(res.begin(),res.end());
        return res;
    }
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *res = new ListNode();
        vector<int> l1 = linkListToArray(l1);
        vector<int> l2 = linkListToArray(l2);
        // int size = max(l1.size(), l2.size());    
    
        return res;
    }
    
};

void solve() {

}

signed main() {
    fast_io;
    solve();
}