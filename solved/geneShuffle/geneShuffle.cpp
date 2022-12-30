#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
int gen1[100003], gen2[100003];
bool seen1[100003], seen2[100003];

void oneRun(){
    int N, i, maxi, k, j;
    cin >> N;
    for (i = 0; i < N; i++) cin >> gen1[i];
    for (i = 0; i < N; i++) cin >> gen2[i];
    memset(seen1, 0, sizeof(seen1)); //set to false
    memset(seen2, 0, sizeof(seen2)); //set to false

    int diff = 0, first = 0;
    for (j = 0; j < N; j++) {
        if (seen2[gen1[j]]) { //if int gen1[j] has already appeared at gen2[0:j-1], we remove 1
            diff--;
        } else { // add 1 otherwise
            diff++;
        }
        seen1[gen1[j]] = true;      // set that gen1[j] has appeared at gen1[0:j]
        if (seen1[gen2[j]]) { // if int gen2[j] has appeared at gen1[0:j-1], we remove 1
            diff--;
        } else { // add 1 otherwise
            diff++;
        }
        seen2[gen2[j]]=true;        // set that gen2[j] has appeared at gen2[0:j]

        if (diff == 0) { // This means gen1[first+1 : j+1] has the same elements as gen2[first+1 : j+1]
            // since we have added 1 and removed 1 an equal number of times.
            // E.g., 1-2-3, 3-2-1, first round is -2, next round -1+1=0, last round +2, giving 0 at the end.
            cout << first + 1 << "-" << j+1; //offset of 1
            cout << " ";
            first = j+1; //update first value
        }
    }
}

int main(){
    int cases;
    cin >> cases;
    while(cases-- > 0) oneRun();
    return 0;
}
