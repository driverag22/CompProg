#include "iostream"
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
    Shop shops[105];
    int n, m;
    /* int items[105]; */
    /* int price[105]; */
    /* int startup[105]; */
    memset(result, 0, sizeof(result));
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        // # items, price per item, price per order
        cin >> shops[i].numItems >> shops[i].price >> shops[i].startup;
        /* cin >> items[i] >> price[i] >> startup[i]; */
    }

    cout << "presort" << endl;
    for (int i = 0; i < m; i++) cout << shops[i].price << endl;

    std::sort(shops, shops+m, [](Shop const &a, Shop const &b){ return a.price > b.price; });

    cout << endl;
    cout << "postsort" << endl;
    for (int i = 0; i < m; i++) cout << shops[i].price << endl;
}

int main(){
    int cases; cin >> cases;
    while(cases-- > 0) oneRun();
    return 0;
}
