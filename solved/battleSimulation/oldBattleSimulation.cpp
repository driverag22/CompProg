#include "iostream"
#include <algorithm>
#include <climits>
#include <cstdio>
#include <bits/stdc++.h>
#include "vector"
using namespace std;
typedef long long ll;

void counter(char a) {
    if (a == 'R') cout << 'S';
    else if (a == 'B') cout << 'K';
    else if (a == 'L') cout << 'H';
    else if (a == ' ') cout << 'Q';
}

int main() {
    string input, tracker;
    ll i;
    cin >> input;
    for (i = 0; input[i]; i++) {
        for (char w : tracker) {
            if (w == input[i]) {
                for (char a : tracker) counter(a);
                tracker.clear();
            }
        }
        tracker += input[i];
        if (tracker.length() == 3) {
            cout << 'C';
            tracker.clear();
        }
    }
    for (char a : tracker) counter(a);
    cout << endl;
    return 0;
}
