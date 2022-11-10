#include "iostream"
#include <cstdio>
#include <bits/stdc++.h>
#include "vector"
using namespace std;
int h, w;
char lab [96][96];



struct Node {
    vector<Node> adj;
    string type;
    bool visited = false;
};

Node g [96][96];
vector<int> answers;
int a,b;
double counter;

void makeGraph(){
    for(int i = 1; i < h-1; i++){
        for (int j = 1; j < w-1; j++){
            g[i][j].adj.clear();
            g[i][j].adj.push_back(g[i+1][j]); g[i][j].adj.push_back(g[i-1][j]);
            g[i][j].adj.push_back(g[i][j+1]); g[i][j].adj.push_back(g[i][j-1]);
        }
    }
    for(int j = 1; j < w-1; j++){
        g[0][j].adj.clear(); g[0][j].adj.push_back(g[1][j]);
        g[0][j].adj.push_back(g[0][j+1]); g[0][j].adj.push_back(g[0][j-1]);

        g[h-1][j].adj.clear(); g[h-1][j].adj.push_back(g[h-2][j]);
        g[h-1][j].adj.push_back(g[h-1][j+1]); g[h-1][j].adj.push_back(g[h-1][j-1]);
    }
    for(int j = 1; j < h-1; j++){
        g[j][0].adj.clear(); g[j][0].adj.push_back(g[j][1]);
        g[j][0].adj.push_back(g[j+1][0]); g[j][0].adj.push_back(g[j-1][0]);

        g[j][w-1].adj.clear(); g[j][w-1].adj.push_back(g[j][w-2]);
        g[j][w-1].adj.push_back(g[j+1][w-1]); g[j][w-1].adj.push_back(g[j-1][w-1]);
    }

    g[0][0].adj.clear();
    g[0][0].adj.push_back(g[0][1]); g[0][0].adj.push_back(g[1][0]);
    g[h-1][0].adj.clear();
    g[h-1][0].adj.push_back(g[h-1][1]); g[h-1][0].adj.push_back(g[h-2][0]);
    g[0][w-1].adj.clear();
    g[0][w-1].adj.push_back(g[0][w-2]); g[0][w-1].adj.push_back(g[1][w-1]);
    g[h-1][w-1].adj.clear();
    g[h-1][w-1].adj.push_back(g[h-1][w-2]); g[h-1][w-1].adj.push_back(g[h-2][w-1]);

}

void DFS(Node x){
    if(x.type == '#' || x.visited) return;
    if(x.type == '.'){
        counter++;
    }
    x.visited = true;
    for (Node n: x.adj){
        DFS(n);
    }
}

void oneRun(){
    cin >> h >> w;
    counter = 0;

    for(int i = 0; i < h; i++){
        string s;
        cin >> s;
        for(int j = 0; j < w; j++){
            if(s[j] == 's') a = i, b = j;
            lab[i][j] = s[j];
            lab[i][j].type = s[j];
        }
    }
    makeGraph();

    DFS(g[a][b]);

    printf("%.2f" , counter);
}

int main(){

    int cases;
    cin >> cases;

    while(cases-- > 0){
        oneRun();
    }

    return 0;
}
