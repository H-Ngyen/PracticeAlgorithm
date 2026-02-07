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

int getSecondLargest(vector<int> &arr) {
    int first = arr[0], second = -1;
    for (int i = 1; i < arr.size(); i++) {
        if (first < arr[i]) {
            second = first;
            first = arr[i];
        }
        else if (arr[i] < first && arr[i] > second) second = arr[i];
    }    
    return second;
}

int main () {
    vector<int> v = {12,35,1,10,34, 1};
    cout << getSecondLargest(v) << endl;
    return 0;
}