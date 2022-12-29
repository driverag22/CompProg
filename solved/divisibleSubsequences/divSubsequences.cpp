#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
int seq[50005];

void oneRun(){
    int d, n;
    cin >> d >> n;

    int modSum = 0;
    int counter = 0;

    int sums[d]; //sums[i] keeps track of sums of subsequences with %d == i
    memset(sums, 0, sizeof(sums));
    sums[0] = 1; // {1, 0, ..., 0}

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a; a %= d; //take digit

        modSum += a; //add to modSum and apply modulus
        modSum %= d;

        counter += sums[modSum]; //add to result
        sums[modSum]++; //increase # of subsequences with %d == modSum by 1
    }

    cout << counter << endl;
}

int main(){
    int cases; 
    cin >> cases;
    while(cases-- > 0) oneRun();
    return 0;
}
