#include "iostream"
#include <algorithm>
#include <climits>
#include <cstdio>
#include <bits/stdc++.h>
#include "vector"
using namespace std;

int main() {
  int n, i, j;
  cin >> n;
  int a = 0, b = 0; string s; char sep; int end = 0;
  for (i = 0; i < n; i++) {
    int x, y;
    cin >> x >> sep >> y;
    if ((x < a && y <= b) || (x < b && y <= a) || (x <= a && y < b) || (x <= b && y < a)) {
      if (end == 0) {
        end = i + 1;
      }
    } else if ( ( x == 11 && (y > b || y > a)) ) {
      if (end == 0) end = i + 1;
    } else if ( ( y == 11 && (x > a || x > a)) ) {
      if (end == 0) end = i + 1;
    }
    a = x, b = y;
  }
  if (end == 0) {
    cout << "ok" << endl;
  } else {
    cout << "error " << end << endl;
  }
  return 0;
}
