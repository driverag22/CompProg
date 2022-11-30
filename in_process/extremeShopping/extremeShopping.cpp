#include "iostream"
#include <cstdio>
#include <bits/stdc++.h>
#include "vector"
using namespace std;

void oneRun(){
    int n, m;
    int shops [105][3];
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> shops[i][0] >> shops[i][1] >> shops[i][2];
    }
    int result [n+3];
    result[0] = 0;
    int payedShops [104];
    for (int i = 1; i <= n; i++) {
        int bestStore = -1;
        int minPrice = INT_MAX;
        for(int j = 0; j < m; j++){
            if (shops[j][0] == 0){
                continue;
            }
            if (payedShops[j] == 1) {
                if (minPrice > shops[j][1]) {
                    bestStore = j;
                    minPrice = shops[j][1];
                } 
            } else {
                if (minPrice > shops[j][1] + shops[j][2]){
                    bestStore = j;
                    minPrice = shops[j][1] + shops[j][2];
                }
            }
        }
        result[i] = result[i-1] + minPrice;
        payedShops[bestStore] = 1;
        shops[bestStore][0]--;
    }
    for (int i = 0; i <= n; i++) {
        cout << i << ":" << result[i] << endl;
    }
}

int main(){

    int cases;
    cin >> cases;

    while(cases-- > 0){
        oneRun();
    }

    return 0;
}
