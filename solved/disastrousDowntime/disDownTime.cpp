#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, i, j;
    cin >> n >> k;
    int t[n];
    for (i = 0; i < n; i++) {
        cin >> t[i];
    }

    int dif = t[n-1] - t[0];
    int c[ dif + 1002 ];
    memset(c, 0, sizeof(c));
    for (int time : t) {
        int temp = time - t[0];
        for (i = 0; i < 1000; i++) {
            c[temp + i]++;
        }
    }
    int res = 0;
    for (int s : c) {
        res = max(res, s); 
    }
    double ans = res;
    ans = ceil(ans / k);
    cout << ans << endl;
    return 0;
}
