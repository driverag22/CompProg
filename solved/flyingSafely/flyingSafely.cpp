#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
#include <vector>
#include <map>
using namespace std;

void oneRun() {
    int n, m, a ,b, i, result; //cities, pilots
    cin >> n >> m;
    for (i = 0; i < m; ++i) {
        cin >> a >> b;
    }
    result = n - 1;
    cout << result << endl;
}

int main(){

    int cases;
    cin >> cases;
    while(cases-- > 0){
        oneRun();
    }

    return 0;
}











