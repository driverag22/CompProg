#include <bits/stdc++.h>
#include <ostream>
#include <vector>
using namespace std;
typedef long long ll;

int n, D, counter;
int l [105];
vector<int> ans;

void flip(int s [105], int a){
	int p = min(a+D, n-1);
	int q = max(a-D, 0);
	for(int i = a; i <= p; i++) (s[i] == 0) ? s[i] = 1 : s[i] = 0;
	for(int i = q; i < a; i++) (s[i] == 0) ? s[i] = 1 : s[i] = 0;
}

bool checkPast(int s [105], int t){
	if(t <= D) return true;
	for(int i = 0; i < t-D; i++){
		if (s[i] == 1) return false;
	}

	return true;
}

bool allOff(int s [105]){
	bool a = true;
	for(int i = 0; i < n; i++){
		if(s[n] == 1) a = false;
		return a;
	}
	return a;
}

void recurse(int s [105], int t, ll c, int n){
	if (allOff(s)) ans.push_back(c);
	if(!checkPast(s, t)) return;
	if(t == n) ans.push_back(c);	
	
	for(int i = 0; i < n; i++) {
		recurse(s, t+1, c, n);
		flip(s, i); 
		recurse(s, t+1, c+1, n);
	}
}

void oneRun(){
	cin >> n >> D;

	for(int i = 0; i < n; i++) cin >> l[i];
	ll c = 0;
	recurse(l, 0, c, n);

	vector<int>::const_iterator it = ans.begin();	
	int min = *(it++);

	while(it != ans.end()){
		if (*it < min) min = *it; 
		++it;
	}
	if(ans.size() == 0) cout << "impossible" << endl;
	else cout << min << endl; 

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
