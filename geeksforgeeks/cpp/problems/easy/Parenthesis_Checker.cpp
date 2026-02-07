#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string& s) {
    stack<char> st;
    for(char c:s) {
        if(c == '(' || c == '{' || c == '[') st.push(c);
        else if (c == ')' || c == '}' || c == ']') {
            if(st.empty()) return 0;
            char t = st.top();
            if (c == ')' && t != '(' ||
                c == '}' && t != '{' ||
                c == ']' && t != '[')
                return 0;
            st.pop();
        }
    }
    return st.empty();      
}

int main () {
    string s; cin >> s;
    cout << (isBalanced(s)) << endl;
    return 0;
}