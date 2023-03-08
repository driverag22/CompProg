#include "iostream"
#include <algorithm>
#include <climits>
#include <cstdio>
#include <bits/stdc++.h>
#include "vector"
using namespace std;
typedef long long ll;
ll sumOfDigits(ll n) {
    if (n < 10) return (n*(n+1))/2;

    ll d = (ll)(log10(n));

    ll *a = new ll[d+1];
    a[0]=0; a[1]=45;
    for (ll i = 2; i <= d; i++) 
        a[i] = a[i-1]*10 + 45*ceil(pow(10,i-1));

    ll p = ceil(pow(10, d));
    ll msd = n / p;

    return msd*a[d] + (msd*(msd-1)/2)*p + 
        msd*(1+n%p) + sumOfDigits(n%p);
}

void oneRun(){
    ll sum, a, b;
    cin >> a >> b;
    sum = sumOfDigits(b) - sumOfDigits(a-1);
    cout << sum << endl;
}
int main() {
    int cases; cin >> cases;
    while(cases-- > 0) oneRun(); 
    return 0;
}
