#include <iostream>
#include <vector>
#define LEN 101

using namespace std;

int main() {
    long long d[LEN][LEN] = {0};
    int map[LEN][LEN] = {0};
    int n, m;

    cin >> n;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> map[i][j];
        }
    }

    d[n][n] = 1;

    for(int i=n; i > 0; i--){
        for(int j=n; j > 0; j--){
            if(map[i][j] == 0) continue;

            int dx[] = {map[i][j],0};
            int dy[] = {0,map[i][j]};
            
            for(int k=0; k<2; k++){
                int nx = j + dx[k];
                int ny = i + dy[k];

                if(ny > n || nx > n) continue;

                if(d[ny][nx] > 0){
                    //d(i,j) = d(i + map(i,j), j) + d(i, j + map(i,j))
                    d[i][j] += d[ny][nx];
                }
            }
        }
    }

    cout << d[1][1];
}