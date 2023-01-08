#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

void oneRun(){
    string upSide, downSide, s;
    cin >> s;
    cin >> upSide;
    cin >> downSide;
    int n = upSide.length();
    int j = 0;

    for (int i = 0; i < n; i++) {
        if ( (upSide[i] == '*') || (downSide[i] == '*') ) j++; 
        else if ( (upSide[i] == s[j]) || (downSide[i] == s[j]) ) j++;
        if (j == s.length()){
            cout << "win" << endl;
            return;
        }
    }

    cout << "lose" << endl;
}

int main(){

    int cases;
    cin >> cases;
    while(cases-- > 0){
        oneRun();
    }

    return 0;
}
