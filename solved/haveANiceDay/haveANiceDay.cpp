#include "iostream"
#include <algorithm>
#include <climits>
#include <cstdio>
#include <bits/stdc++.h>
#include "vector"
using namespace std;

void oneRun(){
    string D, M, Y;
    int i, t, temp, a, b, c, d;
    cin >> D >> M >> Y;
    a = stoi(D); b = stoi(M);
    d = stoi(Y); c = d / 100; d = d % 100;
    map<int, int> counter;
    for (i = 0; D[i]; i++) counter[int(D[i]) - 48] += 1;
    for (i = 0; M[i]; i++) counter[int(M[i]) - 48] += 1;
    for (i = 0; Y[i]; i++) {
        temp = int(Y[i]) - 48;
        counter[temp] += 1;
        t = counter[temp];
    }
    map<int, int>::iterator it = counter.begin();
    while (it != counter.end()) {
        if (it->second != t) {
            cout << "no" << endl;
            return;
        }
        ++it;
    }
    if ((a + b + c == d) || (a + b == c + d)
        || (a == b + c + d) || (b + c == a + d) 
        || (b == a + c + d) || (c == a + b + d)
        || (c + a == b + d)) {
        cout << "yes";
    } else {
        cout << "no";
    }
    cout << endl;
}
int main() {
    int cases; cin >> cases;
    while(cases-- > 0) oneRun(); 
    return 0;
}
