#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

char per[3] = {'P', 'E', 'R'};
int main(){
    string s;
    cin >> s;

    int n = s.length();
    int counter = 0;
    int tracker = 0;

    for (int i = 0; i < n; i++) {
        tracker %= 3;

        if (s[i] != per[tracker]) counter++;

        tracker++;
    }
    cout << counter << endl;

    return 0;
}
