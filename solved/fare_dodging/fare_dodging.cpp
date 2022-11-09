#include "iostream"
#include <cstdio>
#include <bits/stdc++.h>
#include "vector"
using namespace std;
int n, m, start, finish;
double s, p, y;

struct Node {
//    vector<Edge> adj_edg;
    double dist = INT_MAX;
    vector< pair<int, double> > adj_node; //adj node index, connecting edge weight (expected ticket cost)
    int parent;
};


double dijkstra(Node cities [205]) {
    cities[start].dist = 0;
    priority_queue< pair<double, int>, vector<pair<double, int>>, greater< pair<double, int> > > prQ;
    prQ.push(make_pair(0, start));
    while(!prQ.empty()){
        int k = prQ.top().second;
        double d = prQ.top().first;
        prQ.pop();

        if (d <= cities[k].dist) {
            for (int i = 0; i < cities[k].adj_node.size(); i++){
                int r = cities[k].adj_node[i].first; //adj. node index
                double w = cities[k].adj_node[i].second; //connecting edge weight
                if(d + w < cities[r].dist){
                    cities[r].dist = d + w;
                    prQ.push(make_pair(cities[r].dist, r));
                    cities[r].parent = k;
                }
            }

        }
    }
    return cities[finish].dist;
}

void oneRun(){
    cin >> n >> m >> start >> finish >> s >> p >> y;
    Node cities [405];
    double dist [m][4]; //index of one city, index of other city, probability, distance
    for(int i = 0; i < m; i++){
        for(int j = 0; j < 4; j++){
            cin >> dist[i][j];
        }
    }
    int connections [m+2];
    for (int i = 0; i < m; i++){
        connections[i] = min(s+p*dist[i][3], (dist[i][2]/100.0)*(y+p*dist[i][3]));
        int a = dist[i][0];
        int b = dist[i][1];
        cities[a].adj_node.push_back(make_pair(b, (dist[i][2]/100.0)*(y+p*dist[i][3])));
        cities[b].adj_node.push_back(make_pair(a, (dist[i][2]/100.0)*(y+p*dist[i][3])));
        cities[a].adj_node.push_back(make_pair(201+a, s));
        cities[b].adj_node.push_back(make_pair(201+b, s));
        cities[201+a].adj_node.push_back(make_pair(a, 0));
        cities[201+b].adj_node.push_back(make_pair(b, 0));
        cities[201+a].adj_node.push_back(make_pair(201+b, p*dist[i][3]));
        cities[201+b].adj_node.push_back(make_pair(201+a, p*dist[i][3]));
    }
    double result = dijkstra(cities);
    printf("%.2f \n", result);
}

int main(){

    int cases;
    cin >> cases;

    while(cases-- > 0){
        oneRun();
    }

    return 0;
}
