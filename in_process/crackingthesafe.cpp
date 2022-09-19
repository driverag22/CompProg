#include <bits/stdc++.h>
#include <ostream>
using namespace std;

int n;
double s [4];
bool yes;

void rec(double s [4], int p){
	if (yes == true) return;

	if (p == 0){
		if(s[0] == 24.0){
			yes = true;
		}
		return;
	}


	for(int i = 0; i <= p; i++){
		for (int j = 0; j <= p; j++){

			if (i == j) continue;

			double temp = s[i];
			double temp2 = s[j];
			
			double t[4] = {temp+temp2, temp-temp2, temp*temp2, temp/temp2};

			s[j] = s[p];

			for(int k = 0; k < 4; k++){
				s[i] = t[k];
				rec(s, p-1);
			}

			s[i] = temp;
			s[j] = temp2;
		}
	}


}

void oneRun(){
	yes = false;
	cin >> s[0] >> s[1] >> s[2] >> s[3];

	rec(s, 3);

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
