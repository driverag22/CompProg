#include "iostream"
#include <algorithm>
#include <climits>
#include <cstdio>
#include <bits/stdc++.h>
#include <pthread.h>
#include "vector"
using namespace std;
void oneRun(){
    int i, S, K;
    cin >> S >> K;
    if (K % 2 == 0) {
        if (S < K && S % 2 == 1) cout << 1 << endl;
        else {
            S = (S - K)%(K+1);
            if (S == 0) cout << K << endl;
            else if (S % 2 == 1) cout << 0 << endl;
            else cout << 1 << endl;
        }
    } else {
        if (S % 2 == 0) cout << 0 << endl;
        else cout << 1 << endl;
    }
}
int main() {
    int cases; cin >> cases;
    while(cases-- > 0) oneRun(); 
    return 0;
}
