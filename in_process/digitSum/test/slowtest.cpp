#include "iostream"
#include <algorithm>
#include <climits>
#include <cstdio>
#include <bits/stdc++.h>
#include "vector"
using namespace std;
int slowOneRun(int a, int b){
    int sum = 0, i, temp;
    for (i = a; i <= b; i++) {
        temp = i;
        while (temp > 0) {
            sum += (temp % 10);
            temp /= 10;
        }
    }
    return sum;
}
