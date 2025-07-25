#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("unroll-loops,no-stack-protector")
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sor(x) sort(all(x))
#define rsor(x) sort(rall(x))
#define vt vector
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define cel(x) cout << x << '\n'
#define cht(x) cout << x << ' '
using ll = long long;
using ull = unsigned long long;

const int MOD = 1e7 + 7;
const int INT = 1e9 + 7;

float convertToGPA(float score10) {
    if (score10 < 0.0 || score10 > 10.0) {
        std::cerr << "Diem khong hop le. Vui long nhap tu 0 den 10." << std::endl;
        return -1;
    }
    return (score10 * 4.0) / 10.0;
}

int main() {
    float score10;
    std::cout << "Nhap diem thang 10: ";
    std::cin >> score10;

    float gpa = convertToGPA(score10);
    if (gpa >= 0) {
        std::cout << "Diem GPA (thang 4): " << std::fixed << std::setprecision(2) << gpa << std::endl;
    }

    return 0;
}
