#include "iostream"
#include <algorithm>
#include <climits>
#include <cstdio>
#include <bits/stdc++.h>
#include "vector"
using namespace std;

void counter(char a) {
    if (a == 'R') cout << 'S';
    else if (a == 'B') cout << 'K';
    else if (a == 'L') cout << 'H';
}

int main() {
    string input, tracker;
    int i;
    cin >> input;
    for (i = 0; input[i]; i++) {
        for (char w : tracker) {
            if (w == input[i]) {
                for (char a : tracker) counter(a);
                tracker.clear();
            }
        }
        if (tracker.length() == 2) {
            cout << "C";
            tracker.clear();
        } else {
            tracker += input[i];
        }
    }
    if (tracker.length() == 3) cout << "C";
    else for (char a : tracker) counter(a);
    cout << endl;
    return 0;
}
