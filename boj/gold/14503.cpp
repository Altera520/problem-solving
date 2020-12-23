#include <iostream>
#include <vector>
#include <queue>
#define LEN 51
#define CLEAR 2
#define WALL 1
#define EMPTY 0

using namespace std;

int main() {
    int map[LEN][LEN];
    int dx[] = {0,1,0,-1}; //nesw
    int dy[] = {-1,0,1,0};
    int n, m, y, x, d, ans = 0;

    cin >> n >> m;
    cin >> y >> x >> d;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }

    do{
        int cnt = 0;

        map[y][x] = CLEAR;
        ans++;

        while(true){
            int tmp = d - 1;
            int ny, nx;
            if(tmp < 0) tmp = 3;

            if(cnt == 4){
                ny = y - dy[d];
                nx = x - dx[d];
                if(map[ny][nx] == WALL){
                    goto escape;
                }
                else{
                    y = ny;
                    x = nx;
                    cnt = 0;
                    continue;
                }
            }

            ny = y + dy[tmp];
            nx = x + dx[tmp];            

            if(map[ny][nx] == EMPTY){
                d = tmp;
                y = ny;
                x = nx;
                break;
            }
            else{
                d = tmp;
                cnt++;
            }
        }
    }while(true);
    escape:;

    cout << ans;
}