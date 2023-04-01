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

    for (k = 1; k <= m; k++) {
        temp = sqrt(n + k*k);
        if (ceil(temp) - temp < 0.0001) {
            cout << temp << " " << k << endl;
            return 0;
        }
    }

    cout << "impossible" << endl;
        
    return 0;
}
