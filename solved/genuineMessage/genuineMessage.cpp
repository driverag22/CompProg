#include "iostream"
#include <algorithm>
#include <climits>
#include <cstdio>
#include <bits/stdc++.h>
#include "vector"
using namespace std;

void oneRun(){
    string input;
    int i, j;
    cin >> input;
    int counter[26];
    memset(counter, 0, sizeof(counter));

    for (i = 0; input[i]; i++) {
        j = input[i] - '0'; 
        j -= 17;
        if (counter[j] == 3) {
            if (input[i-1] == input[i]) counter[j] = 0;
            else {
                cout << "FAKE" << endl;
                return;
            }
        } else {
            counter[j]++;
        }
    }
    for (i = 0; i < 26; i++) {
        if (counter[i] == 3) {
            cout << "FAKE" << endl;
            return;
        }
    }
    cout << "OK" << endl;
}
int main() {
    int cases; cin >> cases;
    while(cases-- > 0) oneRun(); 
    return 0;
}
