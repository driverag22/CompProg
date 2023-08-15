#include "iostream"
#include <cstdio>
#include <bits/stdc++.h>
#include "vector"
using namespace std;

int factorial (int t) {
    int fact = 1;
    for (int i = 2; i <= t; i++) fact *= i;
    return fact;
}

int main(){

    int N;
    cin >> N;

    if (N < 10) {
        double sum = 1.0;
        int fact;
        for (int i = 2; i <= N; i+=2) {
            fact = factorial(i);
            sum += (1.0 / fact);
        }
        for (int i = 1; i <= N; i+=2) {
            fact = factorial(i);
            sum -= (1.0/fact);
        }
        sum = 1 - sum;

        cout << sum << endl;
    } else {
        double a = 0.632121;
        cout << a << endl;
    }


    return 0;
}
