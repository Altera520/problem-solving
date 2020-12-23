#include <iostream>
#include <vector>
#include <queue>
#define LEN 101
#define CHEEZE 1
#define EMPTY 0

using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int map[LEN][LEN] = {0};
int n, m;

bool possible(int y, int x){
    bool visit[LEN][LEN] = {false};
    queue<pair<int, int>> q;

    q.push({x,y});
    visit[y][x] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;

        for(int k=0; k<4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(1 > nx || nx > m || 1 > ny || ny > n){ //공기통함
                return true;
            }
            if(visit[ny][nx]) continue;
            if(map[ny][nx] == EMPTY){
                q.push({nx, ny});
                visit[ny][nx] = true;
            }
        }

        q.pop();
    }

    return false;
}

int main() {
    int size = 0, hour = 0;
    queue<pair<int, int>> q;

    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> map[i][j];
            if(map[i][j] == CHEEZE) size++;
        }
    }

    while(true){
        int cnt = 0;
        hour++;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(map[i][j] == EMPTY) continue;

                int contact = 0;

                for(int k=0; k<4; k++){
                    int nx = j + dx[k];
                    int ny = i + dy[k];

                    if(map[ny][nx] == EMPTY && possible(ny,nx)){
                        contact++;
                    }
                }

                if(contact >= 2){
                    q.push({j, i}); //x,y
                }
            }
        }

        cnt = q.size();

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;

            map[y][x] = EMPTY;
            q.pop();
        }

        if(size - cnt <= 0){
            break;
        }

        size -= cnt;
    }

    cout << hour << endl;
}