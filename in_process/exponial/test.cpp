#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
const int maxn = 1e5 + 500;
#define inf 0x3f3f3f3f
#define ll long long
ll biao[] = {0,1,2,9,(1 << 18) };//The result value of n<=4 of the formula given by the title
 ll mod_pow(ll a, ll n, ll mod) {//Quick power
	a %= mod;
	ll ret = 1;
	while (n) {
		if (n & 1) ret = (ret*a) % mod;
		a = a*a%mod;
		n >>= 1;
	}
	return ret;
}
 ll euler(ll n) {//Find the Euler value of a number in log(n) time
	ll ans = n;
	for (ll i = 2; i*i <= n; i++) {
		if (n%i == 0)
		{
			ans -= ans / i;
			while (n%i == 0) n /= i;
		}
	}
	if (n>1) ans -= ans / n;
	return ans;
}
ll dfs(ll n, ll m) {
	if (m == 1) return 1;
	 if (n <= 4) //Because when n<=4, it is possible that the power is less than or equal to the modulus, and the rest is the power greater than the modulus
	 {//So the minimum 4 items of n are preprocessed, and the fifth item is much larger than the maximum value of modulus 1e9
		if (biao[n] >= m) return biao[n] % m + m;
		return biao[n];
	}
	ll exp = dfs(n - 1, euler(m));
	return mod_pow(n, exp, m) + m;
}
int main() {
	ll n, mod;
	while (~scanf("%lld%lld", &n, &mod)) {
		ll exp = dfs(n - 1, euler(mod));
		ll ans = mod_pow(n, exp, mod);
		printf("%lld\n", ans);
	}
}
