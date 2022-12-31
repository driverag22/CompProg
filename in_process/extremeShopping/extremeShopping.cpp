#include "iostream"
#include <cstdio>
#include <bits/stdc++.h>
#include "vector"
using namespace std;
int result[10003][103]; // result[i][j] = min. price of buying i items using only first j stores
int remItems[10003][103]; // remItems[i][j] = remaining items at store j after buying first i items
bool alreadyBought [10003][105]; // alreadyBought[i][j] = true if we already bought at store j after buying first i items 

void oneRun(){
    int n, m;
    int shops [105][3];
    memset(alreadyBought, 0, sizeof(alreadyBought));
    memset(result, 0, sizeof(result));
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        // # items, price per item, price per order
        cin >> shops[i][0] >> shops[i][1] >> shops[i][2];
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            remItems[i][j] = shops[j][0];
        }
    }
    for (int i = 0; i <= m; i++) result[0][i] = 0; //no items
    for (int i = 0; i <= n; i++) result[i][0] = INT_MAX; //no shops
    
    for (int i = 1; i <= n; i++) { // iterate from buying 1 items to n items
        cout << i << " items : " << result[i][m];
        int chosenShop = -1;
        int minPrice = INT_MAX;
        int price = 0;
        for (int k = 1; k <= m; k++) { // iterate from buying from only first to all m shops
            remItems[i][k] = remItems[i-1][k];
            // determine best shop to get next item from
            for (int j = 1; j <= k; j++) {  //go over each shop in range [1,k]
                if (remItems[i][j] <= 0) { //if no items left continue
                    continue;
                }
                if (alreadyBought[i-1][j]) { //already paid startup price
                    price = shops[j][1]; //price per item 
                    if (price < minPrice) {
                        minPrice = price; //update minPrice
                        chosenShop = j; //update chosenShop
                    }
                } else { //still have to pay startup price
                    price = shops[j][1] + shops[j][2]; //price per item + startup
                    if (price < minPrice) {
                        minPrice = price; //update minPrice
                        chosenShop = j; //update chosenShop
                    }
                }
            }
            //price to buy i-1 items at k-1 stores + min price to buy another item 
            //                                  OR
            //price to buy i-1 items at k stores + min price to buy another item 
            int minVal = min(result[i-1][k], result[i-1][k-1]) + minPrice;
            cout << " result[" << i << "-1][" << k << "] = " << result[i-1][k] << endl;
            cout << "result[" << i << "-1][" << k << "-1] = " << result[i-1][k-1] << endl;
            cout << "result[" << i << "][" << k << "-1] = " << result[i][k-1] << endl;
            cout << "minVal = " << minVal << endl;
            if (minVal < result[i][k-1]) {
                remItems[i][chosenShop]--; //remove 1 item
                alreadyBought[i][chosenShop] = true; //already paid startup price, might've already been true
                result[i][k] = result[i-1][k] + minPrice;
            } else {
                result[i][k] = result[i][k-1];
            }
            /* cout <<  " ||| " << i << " items : " << result[i][m] << endl; */
        }
    }

    cout << result[n][m] << endl;
    /* for (int i = 1; i <= n; i++) cout << i << " : " << result[i] << endl; */
}

int main(){

    int cases;
    cin >> cases;

    while(cases-- > 0){
        oneRun();
    }

    return 0;
}
