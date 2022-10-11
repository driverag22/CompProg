#include "iostream"
using namespace std;
int result [500+3][100000+3];


void oneRun(){
    int N, M;
    cin >> N >> M;

    int G [N+1];

    for(int i = 1; i <= N; i++){
        int a;
        cin >> a;
        G[i] = a%M;
    }
    G[0]=0;

    for(int j = 0; j <= M; j++) result[0][j] = -N-2;
    result[0][0] = 0;

    for(int i = 1; i <= N; i++){
        for(int j = M - 1; j >= 0; j--){
            result[i][j] = max( result[i-1][j], result[i-1][(j-G[i]+M)%M] + 1);
        }
    }

    for(int i = 1; i<= N; i++) cout << G[i] << ",";
    cout << endl;
    for(int i = 0; i <= N; i++){
        for (int j = 0; j <= M-1; j++){
            cout << result[i][j] << ", ";
        }
        cout << endl;
    }



    cout << result[N][0] << endl;

}

int main(){

    int cases;
    cin >> cases;

    while(cases-- > 0){
        oneRun();
    }

    return 0;
}
