#include <bits/stdc++.h>
#include <ostream>
using namespace std;
// http://24solver.us-west-2.elasticbeanstalk.com/?n1=6&n2=4&n3=5&n4=1

int n;
double s [4];
bool yes;

void setArr(double a [4], double s [4]){
	for (int i = 0; i < 4; i++){
		a[i]=s[i];
	}
}

void func(int p, double s [4]){
	if (p == 0){
		if (s[0] == 24){
			yes = true;
		}
		return;
	}
	double a [4];

	setArr(a, s);

	for (int i = 0; i < p; i++){ //try every possibility
		for(int k = i + 1; k < p; k++){
			int temp = a[i];
			a[i] = a[i] + a[k];
			func(p-1, a);

			a[i] = temp;
			a[i] = a[i] - a[k];
			func(p-1, a);

			a[i] = temp;
			a[i] = a[i] / a[k];
			func(p-1, a);

			a[i] = temp;
			a[i] = a[i] * a[k];
			func(p-1, a);

			setArr(a, s);
		}
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
