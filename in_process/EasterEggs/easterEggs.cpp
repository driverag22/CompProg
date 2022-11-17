#include "iostream"
#include <cstdio>
#include <bits/stdc++.h>
#include "vector"
using namespace std;
int h, w; 
double counter;
int N, B, R;
int eggsX[255];
int eggsY[255];
int plantX[255];
int plantY[255];



void oneRun(){
    cin >> N >> B >> R;
    for(int i = 0; i < B; i++){
        cin >> eggsX[i] >> eggsY[i];
    }
    for(int i = 0; i < R; i++){
        cin >> plantX[i] >> plantY[i];
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
