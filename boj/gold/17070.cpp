#include <iostream>
#include <vector>
#include <queue>
#define LEN 17

using namespace std;

typedef struct info{
    int y;
    int x;
    int dir; //가로:0, 세로:1, 대각:2
}info;

int main() {
    int n, ans = 0;
    queue<info> q;
    int map[LEN][LEN];
    int dx[] = {1,0,1};
    int dy[] = {0,1,1};

    cin >> n;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> map[i][j];
        }
    }

    q.push({1,2,0}); //y,x,direction

    while(!q.empty()){
        info cur = q.front();

        for(int i=0; i<3; i++){
            int y = cur.y + dy[i];
            int x = cur.x + dx[i];

            //가로 -> 가로, 대각
            //세로 -> 세로, 대각
            //대각 -> 가로, 세로, 대각
            if(cur.dir != 2 && (cur.dir != i && i!=2)) continue; 

            //n 범위인지
            if(x > n || y > n) continue;

            //벽 검사
            if(map[y][x] == 1) continue;

            //회전 가능 여부 검사
            if(i == 2 && (map[y-dy[0]][x-dx[0]] == 1 || map[y-dy[1]][x-dx[1]] == 1)) continue;

            q.push({y,x,i});
        }

        if(cur.x == n && cur.y == n){ //find
            ans++;
        }

        q.pop();
    }

    cout << ans;
}