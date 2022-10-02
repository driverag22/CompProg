#include <bits/stdc++.h>
#include <ostream>
using namespace std;

int n;
bool yes;

int sumUp(int a, int b [1505]){
    int sum = 0;
    for(int i = a+1; i <= n; i++) sum+=b[i];
    return sum;
}

void oneRun(){
    cin >> n;
    int students [1505];
    for(int i = 1; i <= n; i++) cin >> students[i];
    int anger [n+1][n+1]; //current floor, last stopped floor

    for(int i = 0; i <= n; i++){
        anger[0][i] = 0;
    }

    for(int i = 1; i <= n; i++){ //current floor
        for(int j = 0; j <= n; j++){ //last not-stopped floor
            int stop = sumUp(i, students);
            anger[i][j] = min(anger[i-1][j] + stop, anger[i-1][]);
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
