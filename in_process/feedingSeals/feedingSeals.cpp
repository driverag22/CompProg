#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, c, i, j;
    cin >> n >> c;
    vector<int> buckets;
    int temp;
    for (i = 0; i < n; i++) {
        cin >> temp;
        buckets.push_back(temp);
    }
    sort(buckets.begin(), buckets.end(), greater<int>());
    int counter = 0;
    bool in = true;
    while (buckets.size() > 0) {
        for (j = 1; j < buckets.size(); j++) {
            if (buckets[0] + buckets[j] <= c) {
                counter++;
                buckets.erase(buckets.begin() + j);
                buckets.erase(buckets.begin());
                in = false;
                break;
            }
        }
        if (in) {
            counter++;
            buckets.erase(buckets.begin());
        } else {
            in = true;
        }
    }
    cout << counter << endl;
    return 0;
}
