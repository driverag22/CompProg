#include "iostream"
#include "vector"
#include "math.h"
using namespace std;


int recurse(int index, int counter, int height, double h [9], double r [9], double R [9], double bowls [9], int last, int n, int skip){
    if(counter == 0) return height;
    if(bowls[index] == 0){
        if(index == n-1){ 
			recurse(0, counter, height, h, r, R, bowls, last, n, skip);
		}else{
		    recurse(index+1, counter, height, h, r, R, bowls, last, n, skip);
		}
    }

    if(skip == n) return INT_MAX;
    bowls[index] = 0;
    int sum;
    if(counter == n){
        sum = h[last];
    } else {
        int alpha = atan( (R[last] - r[last])/2*h[last]);
        int theta = atan( (R[index]-r[index]) / 2*h[index]);
        if(alpha < theta){
           sum = ((R[index]-R[last]) * (h[last]-h[index]))/(2*R[last]-R[index]);
        } else {
            sum = h[index] - (h[last] * (R[last] - r[index]))/(R[last] - r[last]);
        }
    }

    int a,b;
    if(index == n-1){
        a = recurse(0, counter-1, height + sum, h, r, R, bowls, index, n, 0);
        bowls[index] = 1;
        b = recurse(0, counter, height, h, r, R, bowls, last, n, skip+1);
    } else{
        a = recurse(index+1, counter-1, height + sum, h, r, R, bowls, index, n, 0);
        bowls[index] = 1;
        b = recurse(index+1, counter, height, h, r, R, bowls, last, n, skip+1);
    }
    return min(a, b);
}

void oneRun(){
    int n;
    cin >> n;
    double h [9];
    double r [9];
    double R [9];
    double bowls [9];

    for(int i = 0; i < n; i++){
        cin >> h[i] >> r[i] >> R[i];
        bowls[i] = 1;
    }
    int ans = recurse(0, n, 0, h, r, R, bowls, 0, n, 0);

    cout << ans << endl;

}

int main(){

    int cases;
    cin >> cases;

    while(cases-- > 0){
        oneRun();
    }

    return 0;
}
