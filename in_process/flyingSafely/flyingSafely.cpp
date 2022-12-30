#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
#include <vector>
#include <map>
using namespace std;
vector<vector<int>> edges;

int antecesor(int x, vector<int>& parent) {
    if (x == parent[x]) {
        return x;
    }
    parent[x] = antecesor(parent[x], parent);
    return parent[x];
}

void oneRun() {
    /*
     * Idea is that we iterate over every edge, filling the graph (making parents) in order, 
     * if one of the edges causes a cylce we can 'remove' it.
     * We count how many edges we can remove and return m - {# rem. edges}
     * 
     */
    int n, m; //cities, pilots
    cin >> n >> m;
    int extraEdges = 0; //edges we can remove <==> pilots we don't need to trust
    edges.clear();

    int a,b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        edges.push_back( {a, b} );
    }

    vector<int> parent(n);
    for (int i = 1; i <= n; i++) parent[i] = i; //vectors point to themshelves

    for (auto pilot : edges) {
        int cityA = pilot[0]; int cityB = pilot[1];
        int prevCityA = antecesor(cityA, parent); // find furthest cities connected to cityA
        int prevCityB = antecesor(cityB, parent); // and cityB

        if (prevCityA == prevCityB) {  //same antecessor, so cycle
            extraEdges++; //we 'remove' the edge
        } else {
            parent[prevCityA] = prevCityB; //otherwise update parent
        }
    }

    int result = m - extraEdges;
    cout << result << endl;
}

int main(){

    int cases;
    cin >> cases;
    while(cases-- > 0){
        oneRun();
    }

    return 0;
}











