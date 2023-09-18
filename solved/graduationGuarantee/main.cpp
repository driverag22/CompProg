#include "iostream"
#include <algorithm>
#include <climits>
#include <cstdio>
#include <bits/stdc++.h>
#include "vector"
using namespace std;
double p[5008];

bool compare(double &a, double &b) {
  return a - b > 1e-6;
}

int main() {
  int k, n, i, j, l;
  cin >> n >> k;
  for (i = 1; i <= n; i++) cin >> p[i];
  sort(p+1, p + n + 1, compare);

  // s[i][j] : prob of getting i correct with j questions
  double s[n+5][n+5]; 
  for (i = 0; i <= n; i++) {
    for (j = 0; j <= n; j++) {
      s[i][j] = 0;
    }
  }

  s[0][0] = 1;
  for (i = 1; i <= n; i++) s[0][i] = s[0][i-1] * (1 - p[i]);
  for (i = 1; i <= n; i++) s[i][i] = s[i-1][i-1] * p[i];

  for (i = 1; i <= n; i++) {
    for (j = i + 1; j <= n; j++) {
      s[i][j] = p[j] * s[i-1][j-1] + (1-p[j]) * s[i][j-1];
    }
  }

  double colVals[n+1];
  for (j = 0; j <= n; j++) {
    colVals[j] = 0;
    for (i = 0; i <= j; i++) {
      if (2*i - j >= k) colVals[j] += s[i][j];
    }
  }
  /* for (i = 0; i <= n; i++) { */
  /*   for (j = 0; j <= n; j++) { */
  /*     cout << s[i][j] << ", "; */ 
  /*   } */
  /*   cout << endl; */
  /* } */
  double t = 0;
  for (double a : colVals) t = max(t, a);
  cout << t << endl;
  return 0;
}
