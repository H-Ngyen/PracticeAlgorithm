#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

int minJumps(vector<int>& arr) {
    int max_r = 0, curr = 0, count = 0;
    if (arr[0] == 0) return -1;
    
    for (int i = 0; i < arr.size(); i++) {
        max_r = max(max_r, i + arr[i]);
        if (max_r >= arr.size() - 1) return count + 1;
        if (curr == i) {
            if (max_r == i) return -1;
            else {
                count++;
                curr = max_r;
            }
        }
    }
    return -1;
}

int main () {
    vector<int> arr = {1, 4, 3, 2, 6, 7}; 
    cout << minJumps(arr) << endl;
    return 0;
}