#include <bits/stdc++.h>
using namespace std;

string getDayOfWeek(int d, int m, int y) {
    int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    vector<string> weekdays = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};        
    if (m < 3)
        y -= 1;
    int i = ((y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7);
    return weekdays[i];
}

int main () {
    cout << getDayOfWeek(28,12,1995) << endl;
    return 0;
}