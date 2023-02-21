#include "iostream"
#include <algorithm>
#include <climits>
#include <cstdio>
#include <bits/stdc++.h>
#include "vector"
using namespace std;

int main() {
    double diff[7];
    double res, temp;
    int i;
    for (i = 0; i < 7; i++) cin >> diff[i];
    for (i = 0; i < 7; i++) {
        cin >> temp;
        diff[i] = (diff[i] - temp) * (diff[i] - temp);
    }
    for (i = 0; i < 7; i++) res += diff[i];
    res /= 7.0;
    printf("%.6f \n", res);
    return 0;
}
