#include "iostream"
#include <algorithm>
#include <climits>
#include <cstdio>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
bool van = false;

void recurse(int x, int y, string input, string X, string Y, int i) {
    if (i == input.length() || van) {
        if (x == X.length() && y == Y.length()) {
            cout << "BANISH" << endl;
            van = true;
        }
        return;
    }
    if (x < X.length()) if (input[i] == X[x]) recurse(x+1, y, input, X, Y, i+1);
    if (y < Y.length()) if (input[i] == Y[y]) recurse(x, y+1, input, X, Y, i+1);
    recurse(x, y, input, X, Y, i+1);
}

int main() {
    string input, X, Y;
    cin >> input >> X >> Y;
    recurse(0, 0, input, X, Y, 0);
    if (!van) cout << "KEEP" << endl;

    return 0;
}
