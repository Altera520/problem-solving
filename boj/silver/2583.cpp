#include <iostream>
#include <vector>
#include <queue>
#define LEN 101

using namespace std;

int main(){
    int m, n, k;
    queue<pair<int,int>> q;
    int map[LEN][LEN] = {0};
    bool visit[LEN][LEN] = {false};
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};
    priority_queue<int> pq;
    cin >> m >> n >> k;

    while(k-- > 0){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i = y1 + 1; i <= y2; i++){
            for(int j = x1 + 1; j <= x2; j++){
                map[i][j] = 1;
            }
        }
    }

    for(int i=1 ; i<=m; i++){
        for(int j=1 ; j<=n; j++){
            if(map[i][j] == 1) continue;
            if(visit[i][j]) continue;

            int cnt = 0;
            q.push({i,j}); //y,x
            visit[i][j] = true;

            while(!q.empty()){
                int y = q.front().first;
                int x = q.front().second;
                q.pop();
                cnt++;

                for(int k=0; k<4; k++){
                    int ny = y + dy[k];
                    int nx = x + dx[k];

                    if(1 > ny || ny > m || 1 > nx || nx > n) continue;
                    if(map[ny][nx] == 1) continue;
                    if(visit[ny][nx]) continue;

                    q.push({ny,nx}); //y,x
                    visit[ny][nx] = true;
                }
            }

            pq.push(-cnt);
        }
    }

    cout << pq.size() << endl;
    while(!pq.empty()){
        cout << -pq.top() << ' ';
        pq.pop();
    }
}