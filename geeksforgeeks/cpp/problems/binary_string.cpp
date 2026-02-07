#include <bits/stdc++.h>
using namespace std;

int binarySubstring(string &s) {
    multiset<char> hash(s.begin(), s.end());
    hash.erase('0');
    return hash.size();
}

int main() {
    string s = "1111";
    cout << binarySubstring(s) << endl;
    return 0;
}