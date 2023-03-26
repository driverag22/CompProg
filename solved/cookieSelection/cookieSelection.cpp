#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    string line;
    int val, pMin, pMax;
    priority_queue<int> max;
    priority_queue<int, vector<int>, greater<int>> min;

    while (cin >> line) {
        if (line == "#") {
            pMin = min.top();
            min.pop();
            if (min.size() != max.size()) {
                int pMax = max.top();
                max.pop();
                min.push(pMax);
            }
            cout << pMin << endl;
        } else {
            val = stoi(line);
            if (min.size() == 0) {
                min.push(val);
            } else {
                pMin = min.top();
                if (val > pMin) {
                    min.push(val);
                    if (min.size() > (max.size() + 1) ) {
                        pMin = min.top();
                        min.pop();
                        max.push(pMin);
                    }
                } else {
                    max.push(val);
                    if (max.size() > min.size()) {
                        pMax = max.top();
                        max.pop();
                        min.push(pMax);
                    }
                }
            }
            

        }
    }

    return 0;
}
