#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
#include "vector"
using namespace std;
double counter;
int init_x, init_y;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

struct Node{
	char type = '#';
	int visited = 0;
};

Node nodes[201][201];

void DFS(int x, int y, Node nodes[201][201]) {
	if (nodes[x][y].visited == 1 || nodes[x][y].type == '#'){
		return;
	}
	if (nodes[x][y].type == '.'){
		counter++;
	} 
    if (nodes[x][y].type == 't'){
        counter++;
        return;
    }
	nodes[x][y].visited = 1;
    for (int i = 0; i < 4; i++){
		DFS(x + dx[i], y + dy[i], nodes);
	}
}

void oneRun(){
    int h,w;
    cin >> h >> w;
	counter = 0;

    // nodes[width][height]
    for(int y = 0; y < h; y++){
        string s;
        cin >> s;
        for(int x = 0; x < w; x++){
            nodes[x][y].type = s[x];
            nodes[x][y].visited = 0;
			if(s[x] == 's'){
                init_y = y; init_x = x;
            }
        }
    }

    for(int y = 0; y < h; y++){
        for(int x = 0; x < w; x++){
            cout << nodes[x][y].type;
        }
        cout << endl;
    }

	DFS(init_x, init_y, nodes);
    printf("%.2f \n", counter);
}

int main(){

    int cases;
    cin >> cases;

    while(cases-- > 0){
        oneRun();
    }

    return 0;
}
