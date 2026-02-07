#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);
using namespace std;

void solve() {
    int n, p; cin >> n >> p;
    set<int> set_arr;
    for (int i = 0; i < p; i++) {
        int x; cin >> x;
        set_arr.insert(x);
    } 
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int x; cin >> x;
        set_arr.insert(x);
    }  
    
    bool check = 1;
    for (int i = 1; i <= n; i++) {
        auto pos = set_arr.find(i);
        if(pos == set_arr.end()) {
            check = 0;
            break;
        }
    }
    cout << (check ? "YES" : "NO") << endl;
}

int arr[207];
void solve2() {
    int n, q, p; cin >> n >> p;
    fill(arr, arr + 207, 0);
    
    for (int i = 0; i < p; i++) {
        int x; cin >> x;
        arr[x] = 1;
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x; cin >> x;
        arr[x] = 1;
    }
    
    bool check = 0;
    for (int i = 1; i <= n; i++) {
        if(arr[i] == 0) check = 1;
    }
    cout << (!check ? "YES" : "NO") << endl;
}
signed main() {
    fast_io
    solve2();
}