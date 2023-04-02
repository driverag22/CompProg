#include "iostream"
#include <algorithm>
#include <climits>
#include <cstdio>
#include <bits/stdc++.h>
#include "vector"
using namespace std;

int main() {
    int n, m, k, i; cin >> n;
    double temp;

    if (n % 2 == 1) { //odd
        m = (n + 1) / 2;
        k = (n - 1) / 2;
    } else if (n % 4 == 0) {
        n /= 4;
        m = n + 1;
        k = n - 1;
    } else {
        cout << "impossible" << endl;
        return 0;
    }
    cout << m << " " << k << endl;
    return 0;
}
