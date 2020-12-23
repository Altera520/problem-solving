#include <iostream>
#include <vector>
#include <queue>
#define LEN 101
#define INF 1e9

using namespace std;

typedef struct node{
    int x;
    int y;
    int dir;
    int step;
}node;

int main() {
    int m, n, ans = INF;
    int map[LEN][LEN];
    bool visit[LEN][LEN][4] = {false};
    int dx[] = {1,-1,0,0}; //ewsn
    int dy[] = {0,0,1,-1};
    int l[] = {3,2,0,1};
    int r[] = {2,3,1,0};
    queue<node> q;
    node robot, end;
    cin >> m >> n;

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            cin >> map[i][j];
        }
    }

    cin >> robot.y >> robot.x >> robot.dir;
    cin >> end.y >> end.x >> end.dir;
    robot.dir--;
    end.dir--;

    if(robot.y != end.y || robot.x != end.x || robot.dir != end.dir){
        q.push({robot.x, robot.y, robot.dir, 0});
        visit[robot.y][robot.x][robot.dir] = true;

        while(!q.empty()){
            int x = q.front().x;
            int y = q.front().y;
            int dir = q.front().dir;
            int step = q.front().step;
            bool possible = true;

            for(int k=1; k<=5; k++){
                int nx = x, ny = y, ndir = dir;

                if(1 <= k && k <= 3){
                    if(!possible) continue;
                    nx += dx[dir] * k;
                    ny += dy[dir] * k;
                }
                else if(k == 4){ //left;
                    ndir = l[dir];
                }
                else if(k == 5){ //right;
                    ndir = r[dir];
                }

                if(1 > nx || nx > n || 1 > ny || ny > m) continue;
                if(map[ny][nx] == 1){
                    possible = false;
                    continue;
                }
                if(visit[ny][nx][ndir]) continue;
                if(ny == end.y && nx == end.x && ndir == end.dir){
                    ans = min(step+1, ans);
                    continue;
                }

                q.push({nx, ny, ndir, step + 1});
                visit[ny][nx][ndir] = true;
            }

            q.pop();
        }

        if(ans == INF) ans = 0;
    }
    else ans = 0;

    cout << ans;
}