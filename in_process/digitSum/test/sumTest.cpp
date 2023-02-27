#include "iostream"
#include <algorithm>
#include <climits>
#include <cstdio>
#include <bits/stdc++.h>
#include "vector"
using namespace std;
int sumOfDigitsUntil(double n) {
    double sum = 0.0;
    if (n < 0) return 0;
    for (int i = 0; i <= ceil(log10(n)); i++) {
        double k = floor( ( n - floor( n / pow(10,i+1) ) * pow(10,i+1) ) / pow(10,i) );
        sum += 45 * pow(10, i) * floor( n / pow(10, i+1) );
        sum += pow(10, i) * ( k * (k-1) ) / 2;
        sum += k * (n + 1 - pow(10, i) * floor( n / pow(10,i) ) );
    }
    return sum;
}
int oneRun(double a, double b){
    int sum;
    sum = sumOfDigitsUntil(b) - sumOfDigitsUntil(a-1);
    return sum;
}
