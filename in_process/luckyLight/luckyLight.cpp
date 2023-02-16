#include "iostream"
#include <algorithm>
#include <climits>
#include <cstdio>
#include <bits/stdc++.h>
#include "vector"
using namespace std;
int segments[105][4];

void oneRun(){
    int n, xs, ys, i;
    cin >> n >> xs >> ys;
    for (i = 0; i < n; i++) {
        cin >> segments[i][0] >> segments[i][1];
        cin >> segments[i][2] >> segments[i][3];
    }
}
int main() {
    int cases; cin >> cases;
    while(cases-- > 0) oneRun(); 
    return 0;
}
