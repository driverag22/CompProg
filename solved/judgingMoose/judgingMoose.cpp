#include <algorithm>
#include <climits>
#include <cstdio>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    int l, r;
    cin >> l >> r;

    if ((l == 0 && r == 0) || r < 0 || l < 0) {
        cout << "Not a moose" << endl;
    } else if (l == r) {
        r += r;
        cout << "Even " << r << endl;
    } else {
        r = max(r,l);
        r += r;
        cout << "Odd " << r << endl;
    }
    return 0;
}
