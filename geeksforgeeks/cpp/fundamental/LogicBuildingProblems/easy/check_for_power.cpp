#include <bits/stdc++.h>
using namespace std;

int isPowerOfAnother(int X, int Y) {
    if (X == 1) return Y == 1;
    int res = 1;
        
    while (res < Y)
        res *= X;
    if (res == Y) return 1;
    return 0;
}

int main () {
    return 0;
}