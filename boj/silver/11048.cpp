#include <iostream>
#include <vector>
#define LEN 1001

using namespace std;

int main() {
    int d[LEN][LEN] = {0};
    int dx[] = {1,1,0};
    int dy[] = {0,1,1};
    int n, m;

    cin >> n >> m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> d[i][j];
        }
    }

    for(int i=n; i > 0; i--){
        for(int j=m; j > 0; j--){
            int ans = 0;
            for(int k=0; k<3; k++){
                int nx = j + dx[k];
                int ny = i + dy[k];

                if(nx > m || ny > n) continue;

                ans = max(ans, d[ny][nx]);
            }

            d[i][j] += ans; //d(r,c) = max(d(r+1,c), d(r,c+1), d(r+1, c+1))
        }
    }

    cout << d[1][1];
}