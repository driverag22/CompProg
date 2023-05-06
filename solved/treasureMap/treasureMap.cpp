#include "iostream"
#include <algorithm>
#include <climits>
#include <cstdio>
#include <bits/stdc++.h>
#include "vector"
using namespace std;

void oneRun(){
    int N, c, b, i, j;
    cin >> N;
    for (i = sqrt(N); i > 0; i--) { // i = b - c
        if (N % i == 0) {
            j = N / i; // j = b + c
            if ( ( (i+j) % 2 == 0) && ( (j - i) % 2 == 0) ) {
                b = (i + j) / 2;
                c = (j - i) / 2;
                cout << c << " " << b << endl;
                return;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}

int main() {
    int cases; cin >> cases;
    while(cases-- > 0) oneRun(); 
    return 0;
}
