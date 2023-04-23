#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, X, i, j;
    cin >> n >> X;
    if (n < 2) {
        cout << 1 << endl;
        return 0;
    }
    vector<int> prices;
    for (i = 0; i < n; i++) {
        cin >> j;
        prices.push_back(j);
    }
    sort(prices.begin(), prices.end());
    int res = 1;
    for (i = 1; i < n; i++) {
        if (prices[i] + prices[i-1] <= X) {
            res++;
        } else {
            break;
        }
    }
    cout << res << endl;
    return 0;
}
