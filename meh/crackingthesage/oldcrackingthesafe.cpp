#include <bits/stdc++.h>
#include <ostream>
using namespace std;
// http://24solver.us-west-2.elasticbeanstalk.com/?n1=6&n2=4&n3=5&n4=1

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
	for (int i = 0; i < 4; i++){
		a[i]=s[i];
	}
	for (int i = 0; i < p; i++){ //try every possibility
		int temp = a[i];
		a[p] = 0;

		a[i] = temp;
		a[i] = s[i]+s[p];
		func(p-1, a);

		a[i] = temp;
		a[i] = s[i]-s[p];
		func(p-1, a);

		a[i] = temp;
		a[i] = s[i]*s[p];
		func(p-1, a);

		a[i] = temp;
		a[i] = s[i]/s[p];
		func(p-1, a);
		a[i] = temp;
	}
}

void oneRun(){
	yes = false;
	cin >> s[0] >> s[1] >> s[2] >> s[3];

	func(4, s);
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
