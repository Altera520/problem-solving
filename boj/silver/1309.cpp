#include <iostream>
#define LEN 100001
#define MOD 9901

using namespace std;

int main() {
    int d[LEN][3];
    int n, ans;

    cin >> n;

    d[1][0] = 1;
    d[1][1] = 1;
    d[1][2] = 1;

    //d(n)은 d(n-1) 과 (0,0), (1,0), (0,1)과의 조합, 가로 세로 인접 조건 적용
    // 0 = (0,0), 1 = (1,0), 2 = (0,1)
    for(int i=2; i<=n; i++){
        d[i][0] = (d[i-1][0] + d[i-1][1] + d[i-1][2]) % MOD;
        d[i][1] = (d[i-1][0] + d[i-1][2]) % MOD;
        d[i][2] = (d[i-1][0] + d[i-1][1]) % MOD;
    }

    ans = (d[n][0] + d[n][1] + d[n][2]) % MOD;
    cout << ans;
}