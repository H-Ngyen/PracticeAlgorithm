#include <bits/stdc++.h>
using namespace std;

bool checkValidity(int a, int b, int c) {
    return a + b > c && a + c > b && c + b > a;
}

int main () {
    int a, b , c; cin >> a >> b >> c;
    checkValidity(a,b,c);
    
    return 0;
}