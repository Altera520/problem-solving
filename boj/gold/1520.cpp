#include <iostream>
#define LEN 501
using namespace std;

int map[LEN][LEN];
bool visit[LEN][LEN] = { false };
int count[LEN][LEN] = { 0 };
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int m, n, cnt = 0;

int dfs(int x, int y){
    if((x==n && y==m) || count[y][x] > 0){
        return count[y][x];
    }

    for(int i=0; i<4; i++){
        int tx = x + dx[i];
        int ty = y + dy[i];

        if(tx >= 1 && tx <= n && ty >= 1 && ty <= m){
            if(map[ty][tx] < map[y][x]){
                if(!visit[ty][tx]){
                    visit[ty][tx] = true;
                    count[y][x] += dfs(tx, ty);
                } 
                else count[y][x] += count[ty][tx];
            }
        }
    }

    return count[y][x];
}

int main() {

    cin >> m >> n;

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            cin >> map[i][j];
        }
    }

    visit[1][1] = true;
    count[m][n] = 1;
    dfs(1,1);

    cout << count[1][1];
}