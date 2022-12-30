#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
#include <vector>
#include <map>
using namespace std;

void oneRun(){
    int n;
    map<string, int> attributes; 
    cin >> n;

    if (n == 0) {
        cout << 0 << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        string name, category;
        cin >> name >> category;
        attributes[category]++;
    }

    int result = 1;
    for (pair<string, int> a : attributes) {
        /*
         * For a set A and set B, the possible combinations taking 0 or 1 elements from each set 
         * are (|A|+1) * (|B|+1). This makes sense since we match each element of set A with |B| elements of 
         * set B (or viceversa), and the '+1' accounts for not taking any element of either set.
         * Consider A = {a1, a2}, B = {b1}. Then |A| * |B| = 3 * 2 = 6, since we have:
         * a1 + b1
         * a2 + b1
         * a1
         * a2
         * b1
         * nothing.
         * */
        result *= (a.second + 1); 
    }
    result--; //remove the case where we take no attributes
    cout << result << endl;

}

int main(){

    int cases;
    cin >> cases;
    while(cases-- > 0){
        oneRun();
    }

    return 0;
}
