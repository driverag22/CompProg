#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

void oneRun(){
    int P, N;
    cin >> P >> N;
    int values[N];
    for (int i = 0; i < N; i++) {
        cin >> values[i];
    }
    int itempp = floor( N / (P+1));

    sort(values, values+N);


    int sum = 0;
    for (int i = N-1; i > N - 1 - itempp; i--) {
        sum += values[i]; 
    }
    cout << sum << endl;
}

int main(){
    int cases; 
    cin >> cases;
    while(cases-- > 0) oneRun();
    return 0;
}
