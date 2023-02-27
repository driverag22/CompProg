#include "iostream"
#include <algorithm>
#include <climits>
#include <cstdio>
#include <bits/stdc++.h>
#include "vector"
#include "slowtest.cpp"
#include "sumTest.cpp"
using namespace std;
int main() {
    int i, sum1, sum2;
    int start = 0, end = 1e9;
    for (i = start; i < end; i++) {
        cout << i << endl;
        sum1 = oneRun(i, i);
        sum2 = slowOneRun(i, i);
        if (sum1 != sum2) {
            cout << "sum 1 = " << sum1 << " and sum2 = " << sum2;
            cout << "i == " << i << endl;
            return 0;
        }
    }
    return 0;
}
