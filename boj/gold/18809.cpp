#include <iostream>
#include <vector>
#include <queue>
#define LEN 51
#define WATER 0
#define EMPTY 1
#define POS 2
#define RED 3
#define GREEN 4
#define FLOWER 5
using namespace std;

int n, m, g, r;
int ans = 0;
int source[LEN][LEN];
vector<pair<int, int>> pos; // y, x
vector<pair<int, int>> table; // index, type
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int bfs(){
    int ret = 0;
    queue<pair<int,int>> q;
    pair<int,int> target[LEN][LEN]; // type, depth

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            target[i][j] = {source[i][j], -1};
        }
    }

    for(auto start : table){
        int y = pos[start.first].first;
        int x = pos[start.first].second;
        q.push({y, x});
        target[y][x] = {start.second, 0};
    }

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        int depth = target[y][x].second;
        int type = target[y][x].first;
        q.pop();

        if(target[y][x].first == FLOWER) continue;

        for(int k=0; k<4; k++){
            int ny = y + dy[k];
            int nx = x + dx[k];

            if(1 > nx || nx > m || 1 > ny || ny > n) continue;
            if(source[ny][nx] == WATER) continue;

            if(target[ny][nx].first == RED){
                if(target[y][x].first == GREEN && target[ny][nx].second == depth + 1){
                    ret++;
                    target[ny][nx].first = FLOWER;
                }
            }
            else if(target[ny][nx].first == GREEN){
                if(target[y][x].first == RED && target[ny][nx].second == depth + 1){
                    ret++;
                    target[ny][nx].first = FLOWER;
                }
            }
            else if(target[ny][nx].first == EMPTY || target[ny][nx].first == POS){
                q.push({ny, nx});
                target[ny][nx] = {type, depth + 1};
            }
        }
    }

    return ret;
}

void comb(int sz, int _g, int _r, int index){
    if(_g==0 && _r==0 && table.size() == g + r){
        ans = max(ans, bfs());
        return;
    }

    for(int i=index; i<sz; i++){
        if(_g > 0){
            table.push_back({i, GREEN});
            comb(sz, _g-1, _r, i+1);
            table.pop_back();
        }
        if(_r > 0){
            table.push_back({i, RED});
            comb(sz, _g, _r-1, i+1);
            table.pop_back();
        }
    }
}

int main() {

    cin >> n >> m >> g >> r;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> source[i][j];
            if(source[i][j] == POS){
                pos.push_back({i, j}); // y,x
            }
        }
    }

    comb(pos.size(), g, r, 0);
    cout << ans;
}