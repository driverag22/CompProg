#include "iostream"
#include <cstdio>
#include <bits/stdc++.h>
#include "vector"
using namespace std;
int values[1000004];

void oneRun(){
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> values[i];
    }

    if (N == 1) {
        cout << 1 << " " << 1 << endl; return;
    }

    int max = values[0];
    int start = 0;
    int end = 1;
    int finalMax = INT_MIN;
    int finalStart = -1;
    int finalEnd = -1;
    int curVal;
    for (int i = 1; i < N; i++) { 
        curVal = values[i];
        if (curVal > max && max < 0) { 
            start = i;
            end = i;
            max = curVal;
            if (max > finalMax) {
                finalStart = start;
                finalEnd = end;
                finalMax = max;
            }
        } else {
            if (max > finalMax) {
                finalStart = start;
                finalEnd = i;
                finalMax = max;
            }
            max += curVal;
            end = i;
            if (max > finalMax) {
                finalStart = start;
                finalEnd = i;
                finalMax = max;
            }
            if (finalMax == values[0]) {
                finalEnd = 0;
                finalStart = 0;
            }
        }
    }
    finalStart++; 
    finalEnd++;
    cout << finalStart << " " << finalEnd << endl;
}

int main(){
    int cases;
    cin >> cases;
    while(cases-- > 0) oneRun();
    return 0;
}
