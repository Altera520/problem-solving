#include <iostream>
#include <vector>
#define LEN 401
#define INF 1e9

using namespace std;

int table[LEN][LEN] = {0};

void floyd(int n){
    for(int k = 1; k <= n; k++){
        for(int  i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                table[i][j] = min(table[i][j], table[i][k] + table[k][j]);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, s;
    cin >> n >> k;

    // 테이블 초기화
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) continue;
            table[i][j] = INF;
        }
    }

    for(int i = 1; i <= k; i++){
        int from, to;
        cin >> from >> to;
        table[from][to] = 1;
    }

    floyd(n);

    cin >> s;
    for(int i = 1; i <= s; i++){
        int s1, s2, ans = 0;
        cin >> s1 >> s2;

        if(table[s1][s2] != INF 
            && table[s1][s2] > 0) ans = -1;
        else if(table[s2][s1] != INF
            && table[s2][s1] > 0) ans = 1;

        cout << ans << '\n';
    }
}