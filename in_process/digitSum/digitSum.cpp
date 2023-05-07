#include "iostream"
#include <algorithm>
#include <climits>
#include <cstdio>
#include <bits/stdc++.h>
#include "vector"
using namespace std;
typedef long long ll;

int sumDigits(int n) {
    int sum = 0, m;
    while (n > 0) {
        m = n % 10;
        sum += m;
        n /= 10;
    }
    return sum;
}

int solve(int n) {
    if (n <= 0) return 0;
    else if (n % 10 == 0) return (10 * solve(n/10) + 45 * (n / 10));
    return solve(n - 1) + sumDigits(n-1);
}

void oneRun() {
    int a, b, res;
    cin >> a >> b;
    res = solve(b+1) - solve(a);
    cout << res << endl;
}

int main() {
    int cases; cin >> cases;
    while(cases-- > 0) oneRun(); 
    return 0;
}
