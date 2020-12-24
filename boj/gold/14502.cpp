#include <iostream>
#include <vector>
#include <queue>
#define LEN 9
#define SAFE 0
#define WALL 1
#define VIRUS 2

using namespace std;

int n, m, ans = 0;
int map[LEN][LEN];
int safe_cnt = 0;
vector<pair<int, int>> safe;
vector<pair<int, int>> virus;
vector<int> table;
queue<pair<int, int>> q;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int get_infection(){
    bool visit[LEN][LEN] = {false};
    int cnt = 0;

    for(auto v : virus){
        int vy = v.first;
        int vx = v.second;

        q.push({vy, vx});

        while(!q.empty()){
            int y = q.front().first;
            int x = q.front().second;

            for(int k=0; k<4; k++){
                int ny = y + dy[k];
                int nx = x + dx[k];

                if(1 > ny || ny > n || 1 > nx || nx > m) continue;
                if(visit[ny][nx]) continue;
                if(map[ny][nx] != SAFE) continue;

                q.push({ny, nx});
                visit[ny][nx] = true;
            }

            cnt++;
            q.pop();
        }
        cnt--;
    }

    return cnt;
}

void change_map(int item){
    for(int t : table){
        int y = safe[t].first;
        int x = safe[t].second;
        map[y][x] = item;
    }
}

void comb(int n, int r, int index){ //nCr
    if(r==0){
        change_map(WALL);
        ans = max(safe_cnt - get_infection(), ans);
        change_map(SAFE);
        return;
    }

    for(int i=index; i<n; i++){
        table.push_back(i);
        comb(n, r-1, i+1);
        table.pop_back();
    }
}

int main() {

    cin >> n >> m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> map[i][j];
            if(map[i][j] == SAFE){
                safe_cnt++;
                safe.push_back({i,j}); //y,x
            }
            else if(map[i][j] == VIRUS){
                virus.push_back({i,j});
            }
        }
    }
    safe_cnt -= 3;

    comb(safe.size(), 3, 0);

    cout << ans;
}