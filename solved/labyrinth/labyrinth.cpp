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
	bool visited = false;
};
// nodes[width][height]
Node nodes[100][100];

void DFS(int x, int y, int h, int w) {
	if (nodes[x][y].visited == true || nodes[x][y].type == '#'){
		return;
	}
	if (nodes[x][y].type == '.'){
		counter++;
	} 
    if (nodes[x][y].type == 't'){
        counter++;
        return;
    }
	nodes[x][y].visited = true;
    for (int i = 0; i < 4; i++){
        if (x + dx[i] < w && x + dx[i] > -1 
            && y + dy[i] < h && y + dy[i] > -1) {
		    DFS(x + dx[i], y + dy[i], h, w);
        }
	}
}

void oneRun(){
    int h,w;
    cin >> h >> w;
	counter = 0;
    for(int y = 0; y < h; y++){
        string s;
        cin >> s;
        for(int x = 0; x < w; x++){
            nodes[x][y].type = s[x];
            nodes[x][y].visited = false;
			if(s[x] == 's'){
                init_y = y; init_x = x;
            }
        }
    }

	DFS(init_x, init_y, h, w);
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
