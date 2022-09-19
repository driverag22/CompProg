#include <bits/stdc++.h>
#include <ostream>
using namespace std;

int n;
double s [4];
bool yes;

void func(int p, double s [4]){
	if (p == 0 && s[0] == 24){
		yes = true;
		return;
	}
	if (p == 0){return;}
	double a [4];
	for (int i = 0; i < p+1; i++){
		a[i]=s[i];
	}

	for(int i = 0; i < p+1; i++){
		for (int j = 0; j < p+1; j++){
			if(j == p) continue;

			double temp = a[j];
			double temp2 = a[i];
			a[j] = a[p];
			
			a[i] = s[i] + s[j];
			func(p-1, a);

			a[i] = s[i] - s[j];
			func(p-1, a);

			a[i] = s[i]*s[p];
			func(p-1, a);

			a[i] = s[i]/s[p];
			func(p-1, a);

			a[j] = temp;
			a[i] = temp2;
		}
	}

}

void oneRun(){
	yes = false;
	cin >> s[0] >> s[1] >> s[2] >> s[3];

	func(3, s);
	if(yes){
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
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
