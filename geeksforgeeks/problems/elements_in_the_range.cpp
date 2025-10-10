#include <bits/stdc++.h>
using namespace std;

bool check_elements(int arr[], int n, int A, int B) {
    unordered_set<int> h(arr, arr + n);
    for (int i = A; i <= B; i++) 
        if (h.find(i) == h.end())
            return 0;
    return 1;
}

int main()
{
    int n = 7, a = 2, b = 5;
    int arr[] ={1, 4, 5, 2, 7, 8, 3};
    cout << (check_elements(arr, n , a, b) ? "true" : "false") << endl;
    
    return 0;
}