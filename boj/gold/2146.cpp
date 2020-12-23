#include <iostream>
#include <vector>
#include <queue>
#define LEN 101
#define INF 1e9

using namespace std;

int map[LEN][LEN] = {0};
bool visit[LEN][LEN] = {false};
queue<pair<int, int>> q;
int dx[] = {1,0,-1,0}; //eswn
int dy[] = {0,1,0,-1};
int n, pt = 0;

typedef struct node{
    int x;
    int y;
    int depth;
}node;

void bfs(int x, int y){
    if(map[y][x] == 0) return;
    if(visit[y][x]) return;

    pt++;
    q.push({x,y});
    visit[y][x] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;

        for(int k=0; k<4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(1 > nx || nx > n || 1 > ny || ny > n) continue;
            if(map[ny][nx] == 0 || visit[ny][nx]) continue;

            q.push({nx, ny});
            visit[ny][nx] = true;
        }

        map[y][x] = pt;
        q.pop();
    }
}

int find_bridge(int x, int y){
    int ans = INF;
    int cur = map[y][x];
    if(cur == 0) return ans;

    bool check[LEN][LEN] = {false};
    queue<node> fq;

    fq.push({x,y,0});

    while(!fq.empty()){
        int x = fq.front().x;
        int y = fq.front().y;
        int d = fq.front().depth;

        for(int k=0; k<4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(1 > nx || nx > n || 1 > ny || ny > n) continue;
            if(check[ny][nx]) continue;
            if(map[ny][nx] != 0 && map[ny][nx] != cur){
                return d;
            }
            if(map[ny][nx] != 0) continue;

            fq.push({nx, ny, d+1});
            check[ny][nx] = true;
        }

        fq.pop();
    }

    return ans;
}

int main() {
    int ans = INF;
    cin >> n;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> map[i][j];
        }
    }

    // 1. 라벨링
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            bfs(i,j);
        }
    }

    // 2. 최소길이 탐색
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            ans = min(find_bridge(i,j), ans);
        }
    }

    cout << ans;
}