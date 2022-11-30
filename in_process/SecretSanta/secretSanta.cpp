#include "iostream"
#include <cstdio>
#include <bits/stdc++.h>
#include "vector"
using namespace std;
int h, w; 
double counter;
int init_x, init_y;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

struct Node{
	char type = '#';
	int visited = 0;
};

Node nodes[207][207];

void DFS(int x, int y){
	if (nodes[x][y].visited == 1 || nodes[x][y].type == '#'){
		return;
	}
	if (nodes[x][y].type == '.' || nodes[x][y].type == 't'){
		counter++;
	} 
	nodes[x][y].visited = 1;
    for (int i = 0; i < 4; i++){
		DFS(x + dx[i], y + dy[i]);
	}
}

void oneRun(){
    cin >> h >> w;
	counter = 0;

    for(int i = 1; i <= h; i++){
        string s;
        cin >> s;
        for(int j = 1; j <= w; j++){
            nodes[i][j].type = s[j];
            nodes[i][j].visited = 0;
			if(s[j] == 's'){
                init_x = i; init_y = j;
            }
        }
    }
    for(int i = 0; i <= w+2; i++){
        nodes[0][i].visited = '#';
        nodes[h+2][i].visited = '#';
    }
    for(int i = 0; i <= h+2; i++){
        nodes[i][0].visited = '#';
        nodes[i][w+2].visited = '#';
    }

	DFS(init_x, init_y);
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
