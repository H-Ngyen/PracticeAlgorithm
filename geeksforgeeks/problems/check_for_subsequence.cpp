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

// bool isSubSequence(string A, string B) {
//     unordered_multiset<char> ms(B.begin(), B.end());
//     for (auto c : B) {
//         auto it = ms.find(c);
//         dbg(*it, c);
//         if (it == ms.end()) {
//             return 0;
//         }
        
//         ms.erase(it);
//     }
//     return 1;
// }

bool isSubSequence(string a, string b) {
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if(a[i] == b[j]) i++;
        j++;       
    }
    
    return i == a.size();
}

int main() {
    // string a, b; cin >> a >> b;
    // cout << (isSubSequence(a, b) ? "1" : "0") << endl;
    cout << gcd(12,56);
    return 0;
}