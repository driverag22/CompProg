#include "iostream"
#include "vector"
using namespace std;


int recurse(int index, int counter, int height, int h [9], int r [9], int R [9], int bowls [9], int last, int n){
    if(counter == 0) return height;
    if(bowls[index] == 0){
        if(index == n-1) recurse(0, counter, height, h, r, R, bowls, last, n);
        recurse(index+1, counter, height, h, r, R, bowls, last, n);
    }

    bowls[index] = 0;
    int sum;
    if(counter == 1){
        sum = (h[last]*r[index])/(R[last]*r[last]) + h[index];
    } else if (counter == n) {
        sum = 0;
    } else {
        sum = (h[last]*r[index])/(R[last]*r[last]);
    }

    int a,b;
    if(index == n-1){
        a = recurse(0, counter-1, height + sum, h, r, R, bowls, index, n);
        bowls[index] = 1;
        b = recurse(0, counter, height, h, r, R, bowls, last, n);
    } else{
        a = recurse(index+1, counter-1, height + sum, h, r, R, bowls, index, n);
        bowls[index] = 1;
        b = recurse(index + 1, counter, height, h, r, R, bowls, last, n);
    }
    return min(a, b);
}

void oneRun(){
    int n;
    cin >> n;
    int h [9];
    int r [9];
    int R [9];
    int bowls [9];

    for(int i = 0; i < n; i++){
        cin >> h[i] >> r[i] >> R[i];
        bowls[i] = 1;
    }
    int ans = recurse(0, n, 0, h, r, R, bowls, -1, n);

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
