#include <bits/stdc++.h>
using namespace std;

int findNthTerm(int n) {
    return n * (n + 1) / 2;
}

int main () {
    cout << findNthTerm(7) << endl;
    return 0;
}