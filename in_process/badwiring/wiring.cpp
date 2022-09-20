#include <bits/stdc++.h>
#include <ostream>
using namespace std;

int n, D, counter;
int l [105];

void flip(int s [105], int a){
	int p = min(a+D, n-1);
	int q = max(a-D, 0);
	for(int i = a; i <= p; i++) (s[i] == 0) ? s[i] = 1 : s[i] = 0;
	for(int i = q; i < a; i++) (s[i] == 0) ? s[i] = 1 : s[i] = 0;
}

bool allOff(int s [105]){
	bool a = true;
	for(int i = 0; i < n; i++){
		if(s[n] == 1) a = false;
		return a;
	}
	return a;
}

int recurse(int s [105], int t, int c, int n){
	if (allOff(s)) return c;
	if(t == n) return -1;	
	
	int temp [n];
	for(int i = 0; i < n; i++) temp[i] = s[i];
	for(int i = 0; i < n; i++) {
		if(s[i] == 1) flip(temp, i);
		return min(recurse(temp, t+1, c+1, n), recurse(l, t+1, c+1, n));
	}
	return 69;
}

void oneRun(){
	cin >> n >> D;

	for(int i = 0; i < n; i++) cin >> l[i];


	counter = recurse(l, 0, 0, n);

	(counter == -1) ? cout << "impossible" << endl : cout << counter << endl;
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
