#include "iostream"
#include <algorithm>
#include <climits>
#include <cstdio>
#include <bits/stdc++.h>
#include "vector"
using namespace std;
long long sumOfDigitsUntil(int n) {
    long long sum = 0;
    if (n < 0) return 0;
    for (int i = 0; i <= ceil(log10(n)); i++) {
        long long k = floor( ( n - floor( n / pow(10,i+1) ) * pow(10,i+1) ) / pow(10,i) );
        sum += 45 * pow(10, i) * floor( n / pow(10, i+1) );
        sum += pow(10, i) * ( k * (k-1) ) / 2;
        sum += k * (n + 1 - pow(10, i) * floor( n / pow(10,i) ) );
    }
    return sum;
}

void oneRun(){
    long long sum, a, b;
    cin >> a >> b;
    sum = sumOfDigitsUntil(b) - sumOfDigitsUntil(a-1);
    cout << sum << endl;
}
int main() {
    int cases; cin >> cases;
    while(cases-- > 0) oneRun(); 
    return 0;
}
