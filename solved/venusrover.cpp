#include <bits/stdc++.h>
#include <ostream>
using namespace std;
/* typedef long long ll; */

int N, T, M;
bool yes;

void oneRun(){
	cin >> N >> T >> M;
	int a [N+1][T+1][M+1];
	
	int v [N+1][3];

	for (int i = 1; i <= N; i++){
		cin >> v[i][0] >> v[i][1] >> v[i][2]; //time,mass,value
	}

	for (int k = 0; k <= T; k++){
		for (int l = 0; l <= M; l++){
			a[0][k][l] = 0;
		}
	}

	for (int i = 1; i <= N; i++){
		for (int k = 0; k <= T; k++){ //time
			for (int l = 0; l <= M; l++){ //mass
				if (v[i][0] > k || v[i][1] > l){
					a[i][k][l] = a[i-1][k][l];
				} else{
					a[i][k][l] = max(a[i-1][k][l], a[i-1][ k-(v[i][0]) ][ l-(v[i][1]) ] + v[i][2]);
				}
			}
		}
	}

	cout << a[N][T][M] << endl;

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
