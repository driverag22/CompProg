#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main() {
    int M, N, ax, ay, bx, by, i, j, k; 
    double R;
    cin >> M >> N >> R >> ax >> ay >> bx >> by;
    
    int dist = abs(ax - bx);
    double res = 0;
    double angle = dist * (M_PI / M);
    if (ay > by) {
        res += R * (1.0 / N) * (ay - by);            
        if (angle > 2.0) {
            res += 2 * by * (1.0 / N) * R;     
        } else {
            res += angle * (1.0 / N) * R * by;
        }
    } else if (ay == by) {
        if (angle > 2.0) {
            res += 2 * by * (R / N);     
        } else {
            res += angle * (R / N) * by;
        }
    } else {
        res += (R / N) * (by - ay);            
        if (angle > 2.0) {
            res += 2 * ay * (R / N);     
        } else {
            res += angle * (R / N) * ay;
        }
    }
    printf("%.6f \n", res);
    return 0;
}
