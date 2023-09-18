#include "iostream"
#include <algorithm>
#include <climits>
#include <cstdio>
#include <bits/stdc++.h>
#include "vector"
using namespace std;
long h[200000];

int main() {
  int N, i, j, k; cin >> N;
  for (i = 0; i < N; i++) cin >> h[i];
  int a = 0;
  bool inc = true;
  int t = 0;
  for (i = 1; i < N; i++) {
    if (inc) {
      cout << "inc ";
      cout << "at " << i-1 << " : " << (h[i-1] - h[a]) << endl;
      if (!(h[i] >= h[i-1])) {
        inc = false;
        if (t < (h[i - 1] - h[a]) ) t = (h[i - 1] - h[a]);
        a = i - 1;
      }
    } else {
      cout << "dec ";
      cout << "at " << i-1 << " : " << (h[a] - h[i-1]) << endl;
      if (!(h[i] <= h[i-1])) {
        inc = true;
        if (t < (h[a] - h[i]) ) t = (h[a] - h[i-1]);
      }

    }
  }
  cout << t << endl;
  return 0;
}
