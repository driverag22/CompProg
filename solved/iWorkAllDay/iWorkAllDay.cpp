#include "iostream"
#include <algorithm>
#include <climits>
#include <cstdio>
#include <bits/stdc++.h>
#include "vector"
using namespace std;

int main() {
    int N, i, H;
    cin >> N;
    int heights[N];

    for (i = 0; i < N; i++) cin >> heights[i];
    cin >> H;
    int min = heights[0];
    int minVal = H % heights[0];
    int temp;
    for (i = 1; i < N; i++) {
        temp = H % heights[i];
        if (temp < minVal) {
            min = heights[i];
            minVal = temp;
        }
    }
    cout << min << endl;

    return 0;
}
