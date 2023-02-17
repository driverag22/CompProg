#include "iostream"
#include <algorithm>
#include <climits>
#include <cstdio>
#include <bits/stdc++.h>
#include "vector"
using namespace std;

double getLength(int t) {
    switch(t) {
        case 0: return 2.00;
        case 1: return 1.00;
        case 2: return (1.00/2.00);
        case 4: return (1.00/4.00);
        case 8: return (1.00/8.00);
        case 16: return (1.00/16.00);
        default: return 1.00;
    }
}

int main() {
    int N, i, t;
    double sum = 0.00;
    cin >> N;
    for (i = 0; i < N; ++i) {
        cin >> t;
        sum += getLength(t);
    }
    printf("%.4f \n", sum);
    return 0;
}
