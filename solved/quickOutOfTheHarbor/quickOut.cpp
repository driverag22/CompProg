#include <iostream>
#include <vector>
#include <queue>
using namespace std;

char grid[500][500];
bool visited[500][500];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

struct E {
    int r, c, t;
    E(){}
    E(int lr, int lc, int lt) { r = lr; c = lc; t = lt; }
};

struct compareE {
    bool operator()(const E &e1, const E &e2) const {
        return e1.t > e2.t; // smaller time = sorted as "greater" = higher priority
    }
};

void oneRun() {
    int h, w, d; cin >> h >> w >> d;
    int sr, sc; // start coords
    for (int r = 0; r < h; r++) {
        for (int c = 0; c < w; c++) {
            cin >> grid[r][c];
            if (grid[r][c] == 'S') {
                sr = r;
                sc = c;
            }
            visited[r][c] = false;
        }
    }

    priority_queue<E, vector<E>, compareE> q;
    q.push(E(sr, sc, 0));
    while (!q.empty()) {
        E curr = q.top();
        q.pop();

        if (visited[curr.r][curr.c]) continue;

        visited[curr.r][curr.c] = true;

        if (curr.r == 0 || curr.r == h-1 || curr.c == 0 || curr.c == w-1) {
            cout << curr.t+1 << endl;
            break;
        }

        for (int k = 0; k < 4; k++) {
            int nextR = curr.r + dr[k];
            int nextC = curr.c + dc[k];
            if (nextR >= 0 && nextR < h && nextC >= 0 && nextC < w && grid[nextR][nextC] != '#') {
                int nextT = curr.t + 1;
                if (grid[nextR][nextC] == '@') nextT += d;
                q.push(E(nextR, nextC, nextT));
            }
        }
    }
}

int main() {
    int cases; cin >> cases;
    while (cases-- > 0) oneRun();
    return 0;
}
