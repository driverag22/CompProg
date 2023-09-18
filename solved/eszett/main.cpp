#include "iostream"
#include <algorithm>
#include <climits>
#include <cstdio>
#include <bits/stdc++.h>
#include "vector"
using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.length();
  for (int i = 0; i < n; i++) s[i] = tolower(s[i]);
  cout << s << endl;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == 's' && s[i+1] == 's') {
      string c = s;
      c[i] = 'B';
      c.erase(i+1,1);
      cout << c << endl;
    }
  }
  return 0;
}
