#include "iostream"
#include <algorithm>
#include <climits>
#include <cstdio>
#include <bits/stdc++.h>
#include "vector"
using namespace std;
// https://math.stackexchange.com/questions/1991476/sum-of-all-the-digits-of-the-integers-from-one-integer-to-another
int sumOfDigitsUntil(int n) {
    int sum = 0;
    if (n < 0) return 0;
    else if (n == 1) return 1;
    for (int i = 0; i < ceil(log10(n)); i++) {
        int k = floor( ( n - floor( n / pow(10, i+1) ) * pow(10, i+1) ) / pow(10, i) );
        sum += 45 * pow(10, i) * floor( n / pow(10, i+1) );
        sum += pow(10, i) * ( k * (k-1) ) / 2;
        sum += k * (n + 1 - pow(10, i) * floor( n / pow(10,i) ) );
    }
    return sum;
}

void oneRun(){
    int a, b, sum;
    /* cin >> a >> b; */
    cin >> a;
    /* sum = sumOfDigitsUntil(b) - sumOfDigitsUntil(a-1); */
    /* cout << sum << endl; */
    cout << sumOfDigitsUntil(a) << endl;
}
int main() {
    int cases; cin >> cases;
    while(cases-- > 0) oneRun(); 
    return 0;
}
