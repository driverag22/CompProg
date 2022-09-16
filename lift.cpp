#include <bits/stdc++.h>
#include <ostream>
using namespace std;
typedef long long ll;

int n;
bool yes;

void oneRun(){
	cin >> n;

	int s [n+1];
	ll total = 0;

	for (int i = 1; i <= n; i++){
		cin >> s[i]; 
		total += s[i];
	}

	ll a [n+1][total + 1];

	for (int i = 0; i <= total; i++){
		a[0][i] = 0;
	}

	for (int i = 1; i <= n; i++){
		for (int k = total; k >= 0; k--){
			a[i][k] = min(a[i-1][k] + s[i], a[i-1][k] + k - s[i]);
		}
	}

	cout << a[n][0] << endl;

}

int main(){

	int cases;
	cin >> cases;

	while(cases > 0){
		oneRun();
		cases--;
	}

    return 0;
}
