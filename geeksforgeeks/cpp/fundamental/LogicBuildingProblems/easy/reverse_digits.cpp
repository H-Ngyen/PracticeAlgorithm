#include <bits/stdc++.h>
using namespace std;

int reverseDigits(int n) {
    int ans = n % 10;
    n /= 10;
    while (n) {
        ans = (ans * 10) + (n % 10);
        n /= 10;
    }
    return ans;
}
int main () {

    return 0;
}