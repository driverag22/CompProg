#include "iostream"
#include <algorithm>
#include <climits>
#include <cstdio>
#include <bits/stdc++.h>
#include "vector"
using namespace std;

int main() {
  int n;
  cin >> n;
  long sum = 0;
  // Brute force solution. We know for n = 10, answer is 1073741824.
  // We now it will be some i^n), 
  // where those are the numbers that can be recognised (if 5 numbers can be recognised based on 
  // top/bottom, there are 5^n possibilities)
  /* for (int i = 0; i <= 10; i++) { */
  /*   sum = pow(i,n); */
  /*   if (sum == 1073741824) { */
  /*     cout <<" << j << endl; */
  /* } */
  // With this we get i = 8. Trying for n = 13 we see that this works :).
  sum = pow(8,n);
  cout << sum << endl;
  return 0;
}
