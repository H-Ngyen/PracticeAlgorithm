#include <bits/stdc++.h>
using namespace std;

// hashing
void sort012(vector<int>& arr) {
    unordered_map<int, int> hm;
    vector<int> ans;
    for(int &i : arr) hm[i]++;
        
    int j = 0;
    for (int i = 0; i < 3; i++) {
        while (hm[i]--){
            arr[j] = i;
            j++;
        }
    }
}

int main () {

    return 0;
}