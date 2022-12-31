#include "iostream"
#include <cstdio>
#include <bits/stdc++.h>
#include "vector"
using namespace std;
int values[1000004];

void oneRun(){
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> values[i];
    }
    int start = 1;
    int end = 1;
    bool during = true;
    int beg = 0;
    while (values[beg] < 0 && beg < N) {
        beg++;
    }
    int max = values[beg];
    int tmp = 0;
    for (int i = beg; i < N; i++) { //starting from each i, we try all sequences
        if ( i >= 0) {
            for (int j = i; j < N; j++) {
                tmp += values[j];
                if (max < tmp) { //note that \leq here would give i and j maximal for output
                    max = tmp;
                    if (during) { 
                        end = j + 1;
                    } else {
                        start = i + 1;
                        end = j + 1;
                        during = true;
                    }
                } else {
                    during = false;
                }
            }
            tmp = 0;
        }
    }
    cout << start << " " << end << endl;
}

int main(){
    int cases;
    cin >> cases;
    while(cases-- > 0) oneRun();
    return 0;
}
