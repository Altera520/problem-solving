#include <iostream>
#include <vector>
#include <queue>
#define LEN 16

using namespace std;

int ans = 0;
int enemy[LEN][LEN];
int enemy_count = 0;
vector<int> loc; //hunter x position
int n,m,d;

int simulation(){
    int temp[LEN][LEN];
    int cnt = 0;
    int castle = n + 1;

    queue<pair<int,int>> process;

    //배열 복사
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            temp[i][j] = enemy[i][j];
        }
    }

    while(castle > 1 && cnt != enemy_count){ //end conclusion

        //1.search
        for(int k=0; k<3; k++){
            for(int i=0; i<d; i++){
                int dx = loc[k] - i;
                int dy = castle - 1;

                for(int j=1; j<=i*2+1; j++){
                    if(dx >= 1 && dx <= m && dy >= 1 && temp[dy][dx] == 1){
                        process.push({dx, dy});
                        goto escape;
                    }

                    if(dx < loc[k]){
                        dy--;
                    }
                    else{
                        dy++;
                    }
                    dx++;
                }
            }
            escape:;
        }

        //2.attack
        while(!process.empty()){
            int x = process.front().first;
            int y = process.front().second;

            if(temp[y][x]==1){
                temp[y][x] = 0;
                cnt++;
            }

            process.pop();
        }

        //3.move
        castle--;
    }

    return cnt;
}

void combination(int r, int index){ //mC3
    if(r==0){
        ans = max(simulation(), ans);
    }

    for(int i=index; i<=m; i++){
        loc.push_back(i);
        combination(r-1, i + 1);
        loc.pop_back();
    }
}

int main() {
    cin >> n >> m >> d;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> enemy[i][j];
            if(enemy[i][j] == 1){
                enemy_count++;
            }
        }
    }

    combination(3,1);

    cout << ans;
}