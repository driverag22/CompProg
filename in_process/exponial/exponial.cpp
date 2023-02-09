#include "iostream"
#include <algorithm>
#include <climits>
#include <cstdio>
#include <bits/stdc++.h>
#include "vector"
using namespace std;
typedef long long ll;
ll leqfour[] = {0, 1, 2, 9, (1 << 18)};
void oneRun() {
    ll n, m;
    cin >> n >> m;
    ll exp;
    if (m == 1) exp = 1;
    if (n <= 4) {
        if (leqfour[n] >= m) exp = leqfour[n] % m + m;
        else exp = leqfour[n];
    }

}
int main() {
    int cases; cin >> cases;
    while(cases-- > 0) oneRun(); 
    return 0;
}
