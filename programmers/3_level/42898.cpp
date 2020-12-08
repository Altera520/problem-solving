#include <string>
#include <vector>
#include <queue>
#define LEN 101
#define PUDDLE 1
#define MOD 1000000007

using namespace std;

int map[LEN][LEN];
bool visit[LEN][LEN];
int count[LEN][LEN];
int dx[] ={1,0};
int dy[] ={0,1};
int min_step;
int _m; 
int _n;

int dfs(int x, int y, int step){
    
    for(int i=0; i<2; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(1 > nx || nx > _m || 1 > ny || ny > _n) continue;
        if(map[ny][nx] == PUDDLE) continue;
        
        if(!visit[ny][nx]){
            if(nx == _m && ny == _n){
                if(step == min_step){
                    count[y][x]++;
                    return count[y][x];     
                }
            } 
            else{
                visit[ny][nx] = true;
                count[y][x] = (count[y][x] + dfs(nx, ny, step + 1)) % MOD;
            }
            
        }
        else{
            count[y][x] = (count[y][x] + count[ny][nx]) % MOD;
        }
    }
    
    return count[y][x];
}

int solution(int m, int n, vector<vector<int>> puddles) {
    for(auto puddle : puddles) {
        int y = puddle[1];
        int x = puddle[0];
        map[y][x] = PUDDLE;
    }
    
    _m = m;
    _n = n;
    min_step = m + n - 3;
    visit[1][1] = true;
    
    return dfs(1,1,0);
}