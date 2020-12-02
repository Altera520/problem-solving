#include <iostream>
#include <vector>
#include <queue>
#define LEN 301
using namespace std;

int map[LEN][LEN] ={0};
bool visit[LEN][LEN] = {false};
queue<pair<int,int>> q;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void clear_visit(int n, int m){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            visit[i][j] = false;
        }
    }
}

bool year_change(int n, int m){
    int result = 0;
    int tmp[LEN][LEN] = {0};

    //year change
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int cnt = 0;

            for(int k=0; k<4; k++){
                int y = i + dy[k];
                int x = j + dx[k];

                if(y >=1 && y <= n && x >=1 && x <= m && map[y][x] <= 0){
                    cnt++;
                }
            }

            tmp[i][j] = cnt;
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            map[i][j] -= tmp[i][j];
            if(map[i][j] <= 0){
                result++;
            }
        }
    }

    return n*m == result;
}

int bfs(int n, int m){
    int cnt = 0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(map[i][j] > 0 && !visit[i][j]){
                q.push({i,j}); //y,x
                visit[i][j] = true;

                while(!q.empty()){
                    pair<int,int> tmp = q.front();

                    for(int k=0; k<4; k++){
                        int y = tmp.first + dy[k];
                        int x = tmp.second + dx[k];

                        if(y >=1 && y <= n && x >=1 && x <= m && map[y][x]>0 && !visit[y][x]){
                            q.push({y,x}); //y,x
                            visit[y][x] = true;
                        }
                    }

                    q.pop();
                }
                cnt++;
            }
        }
    }

    return cnt > 1;
}

int main() {
    int n, m, year = 0;

    cin >> n >> m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> map[i][j];
        }
    }

    while(true){
        if(year_change(n,m)){
            year = 0;
            break;
        }

        clear_visit(n,m);
        year++;

        if(bfs(n,m)){
            break;
        }
    }

    cout << year;
}