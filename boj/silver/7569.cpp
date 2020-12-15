#include <iostream>
#include <vector>
#include <queue>
#define LEN 101
#define T 1
#define UT 0
#define NONE -1

using namespace std;

int box[LEN][LEN][LEN];
typedef struct info{
    int x;
    int y;
    int k;
    int day;
}info;

int main() {
    int m, n, h; //x,y,k
    int ans = 0;
    bool check = false;
    queue<info> q;
    int dx[] = {0,1,0,-1,0,0};
    int dy[] = {1,0,-1,0,0,0};
    int dk[] = {0,0,0,0,-1,1};

    cin >> m >> n >> h;

    for(int k=1; k<=h; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                cin >> box[k][i][j];

                if(box[k][i][j] == UT){
                    check = true;
                }
                else if(box[k][i][j] == T){
                    q.push({j,i,k,0}); //x,y,k,day
                }
            }
        }
    }

    if(!check){ //모두 익은 상태
        cout << 0;
        return 0;
    }

    while(!q.empty()){
        info tmp = q.front();

        for(int i=0; i<6; i++){
            int nx = tmp.x + dx[i];
            int ny = tmp.y + dy[i];
            int nk = tmp.k + dk[i];

            //범위 체크
            if(1 > nx || nx > m) continue;
            if(1 > ny || ny > n) continue;
            if(1 > nk || nk > h) continue;

            if(box[nk][ny][nx] != UT) continue;

            box[nk][ny][nx] = T;
            q.push({nx, ny, nk, tmp.day + 1});
        }

        ans = max(ans, tmp.day);
        q.pop();
    }

    for(int k=1; k<=h; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(box[k][i][j] == UT){
                    check = false;
                }
            }
        }
    }

    if(!check){
        cout << -1;
    }
    else{
        cout << ans;
    }
}