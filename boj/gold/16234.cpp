#include <iostream>
#include <vector>
#include <queue>
#define LEN 51

using namespace std;

int main() {
    int n, l, r, ans = 0;
    int map[LEN][LEN];
    bool visit[LEN][LEN];
    queue<pair<int, int>> q, country;
    int dx[] = {0,1,0,-1};
    int dy[] = {1,0,-1,0};

    cin >> n >> l >> r;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> map[i][j];
        }
    }

    while(true){
        bool is_move = false;
        int temp[LEN][LEN];
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                visit[i][j] = false;
                temp[i][j] = map[i][j];
            }
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(visit[i][j]) continue;
                int union_cnt = 0;
                int union_sum = 0;

                q.push({i, j}); //y,x
                visit[i][j] = true;

                while(!q.empty()){
                    int y = q.front().first;
                    int x = q.front().second;

                    for(int k=0; k<4; k++){
                        int ny = y + dy[k];
                        int nx = x + dx[k];
                        int val = 0;

                        if(1 > nx || nx > n || 1 > ny || ny > n) continue;
                        if(visit[ny][nx]) continue;
                        val = abs(map[y][x] - map[ny][nx]);

                        if(l <= val && val <= r){
                            q.push({ny, nx});
                            visit[ny][nx] = true;
                        }
                    }

                    union_cnt++;
                    union_sum += map[y][x];
                    country.push({y, x});
                    q.pop();
                }

                if(union_cnt > 1) is_move = true;
                else visit[i][j] = false;

                while(!country.empty()){
                    int y = country.front().first;
                    int x = country.front().second;

                    temp[y][x] = union_sum / union_cnt; 
                    country.pop();
                }
            }
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                map[i][j] = temp[i][j];
            }
        }

        if(is_move) ans++;
        else break;
    }

    cout << ans;
}