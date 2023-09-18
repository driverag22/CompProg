#include "iostream"
#include <algorithm>
#include <climits>
#include <cstdio>
#include <bits/stdc++.h>
#include "vector"
using namespace std;

int main() {
  int n, i, c = 0, u = 0;
  cin >> n;
  string s; cin >> s;

  for (i = 0; i < n; i++) {
    if (s[i] == '1') {
      c++;
      u = 2;
    } else if (u > 0) {
      u--; c++;
    }
  }
  cout << c << endl;
  return 0;
}
