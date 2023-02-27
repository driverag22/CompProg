#include "iostream"
#include <algorithm>
#include <climits>
#include <cstdio>
#include <bits/stdc++.h>
#include "vector"
using namespace std;
void slowOneRun(){
    int sum = 0, a, b, i, temp;
    cin >> a >> b;
    for (i = a; i <= b; i++) {
        temp = i;
        while (temp > 0) {
            sum += (temp % 10);
            temp /= 10;
        }
    }
    cout << sum << endl;
}
int main() {
    int cases; cin >> cases;
    while(cases-- > 0) slowOneRun(); 
    return 0;
}
