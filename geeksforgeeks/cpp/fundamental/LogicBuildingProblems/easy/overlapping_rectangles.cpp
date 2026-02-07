#include <bits/stdc++.h>
using namespace std;

int doOverlap(vector<int> L1, vector<int> R1, vector<int> L2, vector<int> R2) {
    int w1 = abs(R1[0] - L1[0]), w2 = abs(R2[0] - L2[0]);
    return L1[0] + w1 >= L1[1] && L1[1] + w1 >= L1[0] 
            && L2[0] + w2 >= L2[1] && L2[1] + w2 >= L2[0];
}

int main () {
    vector<int> L1(2), R1(2), L2(2), R2(2);
    for (int x:L1) cin >> x;
    for (int x:R1) cin >> x;
    for (int x:L2) cin >> x;
    for (int x:R2) cin >> x;
   
    cout << doOverlap(L1,R1,L2,R2) << endl;
   
    return 0;
}