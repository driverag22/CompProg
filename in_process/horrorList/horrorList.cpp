#include "iostream"
#include <algorithm>
#include <climits>
#include <cstdio>
#include <bits/stdc++.h>
#include "vector"
using namespace std;
const int maxN = INT_MAX - 4;

int main() {
  int N, H, L, i, j, k;
  cin >> N >> H >> L; //# movies, # movies in horror list, # similarities
  int horrorList[H];
  for (i = 0; i < H; i++) {
    cin >> horrorList[i];
  }
  int sim[L][2];
  for (i = 0; i < L; i++) {
    cin >> sim[i][0] >> sim[i][1];
  }
  int grades[N];
  for (i = 0; i < N; i++) grades[i] = maxN;
  for (int id : horrorList) grades[id] = 0;
  for (i = 0; i < L; i++) {
    int a = grades[sim[i][0]], b = grades[sim[i][1]];
    if ((a == 0 && b == 0) || (a == maxN && b == maxN)) continue; 
    else if (a < b) grades[sim[i][1]] = grades[sim[i][0]] + 1;
    else if (b < a) grades[sim[i][0]] = grades[sim[i][1]] + 1;
  }
  int max = -1;
  int ind = N;
  for (int i = 0; i < N; i++) {
    if (grades[i] > max) {
      max = grades[i];
      ind = i;
    }
  }
  cout << ind << endl;
  return 0;
}
