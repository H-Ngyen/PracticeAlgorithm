#include <bits/stdc++.h>
using namespace std;

string decToBinary(int n) {
    string ans;
    while (n) {
        ans.push_back('0' + (n & 1));
        n >>= 1;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string decToBinary2(int n) {
    string ans;
    while (n) {
        ans += to_string(n % 2);
        n >>= 1;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main () {
    cout << decToBinary(7) << endl;
    return 0;
}