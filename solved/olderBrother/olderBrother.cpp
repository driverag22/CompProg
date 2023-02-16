#include "iostream"
#include <algorithm>
#include <climits>
#include <cstdio>
#include <bits/stdc++.h>
#include "vector"
using namespace std;
vector<int> primes;
bool is_prime[100000];

void sieveOfEratosthenes(int n)
{
    int p = 2;
     
    for(int i = 2; i < n; i++)
       is_prime[i] = true;
        
    while (p * p <= n) {
        if (is_prime[p] == true) {
            // Update all multiples of p
            for(int i = p + p; i < n + 1; i += p) is_prime[i] = false;
        }
        p += 1;
    }
    for(int i = 2; i < n + 1; i++) {
       if (is_prime[i])
           primes.push_back(i);
    }
}

int main() {
    int n, c;
    cin >> n;
    sieveOfEratosthenes(int(sqrt(n))+1);
    for (auto i : primes) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            if (n == 1) cout << "yes" << endl;
            else cout << "no" << endl;
            return 0;
        }
    }
    if (n == 1) cout << "no" << endl;
    else cout << "yes" << endl;
    return 0;
}
