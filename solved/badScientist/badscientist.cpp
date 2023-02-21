#include "iostream"
using namespace std;
int cont [1225][2];
int theo [50];

bool noCont(int C [1225][2], int T [50], int k){
    for(int i = 0; i < k; i++){
        if((T[C[i][0]] == 1) && (T[C[i][1] == 1])) return true;
    }
    return false;
}

int recurse(int i, int T [50], int k, int m, int C [1225][2], int sum){
   if(i == m) return sum;
   if((T[C[i][0]] == 0) || T[C[i][1]] == 0) return recurse(i+1, T, k, m, C, sum);
   if(sum+1 > k) return 20;

   T[C[i][0]] = 0;
   int a = recurse(i+1, T, k, m, C, sum+1);
   T[C[i][0]] = 1;
   T[C[i][1]] = 0;
   int b = recurse(i+1, T, k, m, C, sum+1);
   T[C[i][1]] = 1;


   return min(a,b);
}

void oneRun(){
    int n, k, m;
    cin >> n >> k >> m;
    for(int i = 0; i < m; i++){
        cin >> cont[i][0] >> cont[i][1];
        theo[cont[i][0]] = 1; theo[cont[i][1]] = 1;
    }
    int result = recurse(0, theo, k, m, cont, 0);
    (result == 20)? cout << "IMPOSSIBLE" << endl : cout << result << endl;
}

int main(){
    int cases;
    cin >> cases;
    while(cases-- > 0){
        oneRun();
    }
    return 0;
}