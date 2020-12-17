#include <iostream>
#define LEN 1001
#define MOD 10007

using namespace std;

int main() {
    int d[LEN][10] = {0}; //초기화 필수
    int n, ans = 0;

    cin >> n;

    for(int i=0; i<10; i++){
        d[1][i] = 1;
    }

    for(int i=2; i<=n; i++){
        for(int j=0; j<10; j++){
            for(int k=j; k<10; k++){
                d[i][j] = (d[i][j] + d[i-1][k]) % MOD;
            }
        }
    }

    for(int i=0; i<10; i++){
        ans = (ans + d[n][i]) % MOD;
    }

    cout << ans;
}