#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void swapNumber(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void solve() {
    int a, b; cin >> a >> b;
    swap(a,b);
    // swapNumber(a, b);
    cout << a << ' ' << b;
}

int main() {
    solve();

    return 0;
}