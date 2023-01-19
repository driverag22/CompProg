#include "iostream"
#include <algorithm>
#include <climits>
#include <cstdio>
#include <bits/stdc++.h>
#include "vector"
using namespace std;
int result[10003][103]; // result[i][j] = min. price of buying i items using only first j stores
struct Shop {
    int numItems = 0;
    int price = 0;
    int startup = 0;
};
void oneRun(){
    int n, m, i, j, k, priceChooseShop, availableItems;
    /* memset(result, 0, sizeof(result)); */
    cin >> n >> m;
    Shop shops[m+4];
    for (i = 1; i <= m; i++) {
        // # items, price per item, price per order
        cin >> shops[i].numItems >> shops[i].price >> shops[i].startup;
    }
    // Sort decreasing order:
    sort(shops+1, shops+m+1, [](Shop const &a, Shop const &b){ return a.price > b.price; }); 

    for (i = 0; i <= n; i++) result[i][0] = INT_MAX; //no shops
    for (j = 0; j <= m; j++) result[0][j] = 0; //no items

    for (i = 1; i <= n; i++) { // iterate from buying 1 items to n items
        for (j = 1; j <= m; j++) { // iterate from buying from only first to all m shops
            priceChooseShop = 0;
            availableItems = shops[j].numItems;
            if ( i > availableItems ) {
                // buy all possible items, the rest from other shops
                priceChooseShop = result[i-availableItems][j-1] + shops[j].startup + (availableItems * shops[j].price); 
            } else {
                // buy all i items from same shop
                priceChooseShop = shops[j].startup + (i * shops[j].price); 
            }
            result[i][j] = min(result[i][j-1], priceChooseShop);
        }
    }
    cout << result[n][m] << endl;
}
int main() {
    int cases; cin >> cases;
    while(cases-- > 0) oneRun(); 
    return 0;
}
