#include "iostream"
#include <cstdio>
#include <bits/stdc++.h>
#include "vector"
using namespace std;

void oneRun(){
    int d, n;
    cin >> d >> n;
    int elems[n+3];
    int a;
    for (int i = 0; i < n; i++) { 
        cin >> a;
        elems[i] = a % d;
    }
    int counter = 0;
    int solutions[n+3];
    for (int i = n-1; i >= 0; i--) {
        int c = i-1;
        solutions[i] = elems[c];
        while (solutions[i] < d && c >= 0) {
            solutions[i] += elems[c];
            c--;
        }
        if (solutions[i] == d) {
            counter++;
        }
    }

    cout << counter << endl;
}

int main(){
    int cases; 
    cin >> cases;
    while(cases-- > 0) oneRun();
    return 0;
}
