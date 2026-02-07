#include <bits/stdc++.h>
using namespace std;

/*You are required to complete this function*/
void addFraction(int num1, int den1, int num2, int den2) {  
    int _lcm = lcm(den1, den2);
    int num = num1 * (_lcm / den1) + num2 * (_lcm / den2);
    int qd = gcd(num, _lcm);
    cout << num / qd << "/" << _lcm/qd << endl;
}

int main () {
    // addFraction(1 , 600, 2, 300);
    cout << gcd(21,24) << endl;
    return 0;
}