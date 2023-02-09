#include "iostream"
#include <algorithm>
#include <climits>
#include <cstdio>
#include <bits/stdc++.h>
#include "vector"
using namespace std;

void oneRun(){
    string comm, vals;
    int l, r, n, i, j;
    bool dir = false;
    cin >> comm >> n >> vals;
    l = 0; r = n - 1; j = 0;

    int nums[n]; //will contain input numbers
    memset(nums, 0, sizeof(nums));
    for (i = 0; i < vals.size(); i++) {
        if (vals[i] == '[' || vals[i] == ']') continue;
        else if (vals[i] == ',') { 
            j++; 
            continue; 
        }
        int t = int(vals[i] - '0');
        nums[j] *= 10; nums[j] += t;
    }
    int del = 0;

    for (i = 0; comm[i]; i++) {
        switch(comm[i]) {
            //dir == false -> left side, dir == true -> right side
            case 'D': if(!dir){l++;}else{r--;} del++; break;
            case 'R': dir = !dir; break;
            default: break;
        }
    }
    if (del > n) {
        cout << "error" << endl;
    } else if (del == n){
        cout << "[]" << endl;
    } else { //print numbers in correct order
        cout << "[";
        if (!dir) {
            for (i = l; i < r; i++) {
                cout << nums[i] << ",";
            }
            cout << nums[r];
        } else {
            for (i = r; i > l; i--) {
                cout << nums[i] << ",";
            }
            cout << nums[l];
        }

        cout << "]" << endl;
    }
}

int main() {
    int cases; cin >> cases;
    while(cases-- > 0) oneRun(); 
    return 0;
}
