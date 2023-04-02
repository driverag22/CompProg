#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    int c, m, i, j, k; 
    cin >> c >> m;
    int pays[m][c];

    for (i = 1; i <= m; i++) { // merchant
        for (j = 1; j <= c; j++) { // price per j cpus
            cin >> pays[i][j];
        }
    }

    int sol[m+1][c+1];

    for (i = 0; i <= m; i++) { // selling 0 cpus gives 0
        sol[i][0] = 0;
    }
    for (i = 0; i <= c; i++) { // selling to nobody gives 0
        sol[0][i] = 0;
    }

    for (i = 1; i <= m; i++) {
        for (k = 1; k <= c; k++) {
            sol[i][k] = max(sol[i-1][k], pays[i][k]);
        }
    }
    cout << endl;
    cout << endl;
    for (i = 1; i <= m; i++) {
        for (k = 0; k <= c; k++) {
            cout << sol[i][k] << "  ";
        }
        cout << endl;
    }

    return 0;
}
