#include "iostream"
#include <cstdio>
#include <bits/stdc++.h>
#include "vector"
using namespace std;

typedef long long ll;

int main(){
    ll n;
    cin >> n;
    ll temp = n;
    int numDigits = 0;
    if (n < 10) {
        cout << n << endl;
        return 0;
    }

    while (temp >= 99) {
        temp = temp / 10;
        numDigits++;
    }
    numDigits++;
    if (temp % 10 <= 4) {
        temp /= 10;
    } else {
        temp /= 10;
        temp++;
    }
    for (int i = 0; i < numDigits; i++) temp *= 10;

    cout << temp << endl;
    return 0;
}
