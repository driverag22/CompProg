#include "iostream"
#include <algorithm>
#include <climits>
#include <cstdio>
#include <bits/stdc++.h>
#include "vector"
using namespace std;

int main() {
    string input;
    int l = 0, r = 0, i, t, c;
    cin >> input >> c;
    for (i = 0; i < c; i++) {
        cin >> t;
        l += t;
        cin >> t;
        r = t;
    }
    r = l + r;
    for (i = l; i < r; i++) cout << input[i];
    cout << endl;
    return 0;
}
