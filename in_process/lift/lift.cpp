#include <bits/stdc++.h>
#include <ostream>
using namespace std;

const unsigned int MAXANGER = (1 << 31);
int n;
bool yes;
int students [1505];
int anger [1505]; //current floor, last stopped floor

int sumUp(int a, int b [1505]){
    int sum = 0;
    for(int i = a+1; i <= n; i++) sum+=b[i];
    return sum;
}

void oneRun(){
    cin >> n;
	students[0] = 0;
    for(int i = 1; i <= n; i++) {
		cin >> students[i]; 
		students[i] += students[i-1];
	}

    anger[0] = 0; 

    for(int i = 1; i <= n; i++){ 
		anger[i] = MAXANGER;
		for(int j = 0; j < i; j++){
			anger[i] = min(anger[i], anger[j] + students[n] - students[i]);
			anger[j] += students[i] - students[j];
		}
    }

    cout << anger[n] << endl;
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
