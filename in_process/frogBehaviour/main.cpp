#include "iostream"
#include <algorithm>
#include <climits>
#include <cstdio>
#include <bits/stdc++.h>
#include "vector"
using namespace std;
int f[200004];

int main() {
  int n, i = 0, j = 0, k = 0, q;
  memset(f, 0, sizeof(f));
  map<int,int> l;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> f[i];
    l.insert(make_pair(f[i], i));
  }
  cin >> q;
  for (i = 0; i < q; i++) {

    cin >> j;
    k = f[j]; // get position of frog j

    l[f[j]] = 0; // empty out old position
    f[j] = k;  // frog j moves to positon k
    l[k] = 1; // set position k to used
    
    cout << k << endl;
  }
  return 0;
}
