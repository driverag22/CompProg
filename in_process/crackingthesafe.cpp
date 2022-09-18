#include <bits/stdc++.h>
#include <ostream>
using namespace std;
// http://24solver.us-west-2.elasticbeanstalk.com/?n1=6&n2=4&n3=5&n4=1

int n;
double s [4];
bool yes;

void func(double nums [4], int p){
	if (p == 0){
		if(fabs(nums[0] - 24.0) <=1e-9){ 
			yes = true;
		}
		return;
	}


	for(int i = 0; i < p; i++){
		for (int j = 0; j < p; j++){
			if (j == i){
				continue;
			}
			double temp = nums[i];
			double temp2 = nums[p];
			double n [4] = { nums[i] + nums[j], nums[i]-nums[j], nums[i]*nums[j], nums[i]/nums[j] };
			
			for(int k = 0; k < 4; k++){
				nums[i] = n[k];
				nums[p] = nums[j];
				nums[j] = temp2;
				func(nums, p-1);
			}
			nums[j] = nums[p];
			nums[p] = temp2;
			nums[i] = temp;			

		}
	}


}

void oneRun(){
	yes = false;
	int a;
	for (int i = 0; i < 4; i++){
		cin >> a;
		s[i] = a * 1.0;
	}

	func(s, 3);
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
