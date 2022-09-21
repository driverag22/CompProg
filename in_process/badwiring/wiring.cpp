#include "bits/stdc++.h"
#include "ostream"
#include "vector"
using namespace std;
typedef long long ll;

int n, D, counter;
int l [105];
vector<int> ans;

void flip(int s [105], int index){
	int p = min(index+D, n-1);
	int q = max(index-D, 0);
    for(int i = q; i <= p; i++) (s[i] == 0) ? s[i] = 1 : s[i] = 0;
}
bool allOff(int s [105], int n){
    for(int i = 0; i < n; i++){
        if(s[i] == 1) return false;
    }
    return true;
}
bool prevFine(int s [105], int index, int D){
    if (index <= D) return true;
    for (int i = 0; i < index-D; i++) {
        if(s[i] == 1) return false;
    }
    return true;
}
void recurse(int s [105], int index, int c, int n){
    if(allOff(s, n)) ans.push_back(c);
//    if(index > D && s[index-D-1] == 1) return;
    if(!prevFine(s, index, D)) return;
	if(index == n) return;

    recurse(s, index+1, c, n);
    flip(s, index);
    recurse(s, index+1, c+1, n);
}

void oneRun(){
	cin >> n >> D;

	for(int i = 0; i < n; i++) cin >> l[i];
	recurse(l, 0, 0, n);

    if(ans.size() == 0) cout << "impossible" << endl;
    else {
        vector<int>::const_iterator it = ans.begin();
        int min = *(it++);

        while (it != ans.end()) {
            if (*it < min) min = *it;
            ++it;
        }
        cout << min << endl;
        ans.clear();
    }
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
