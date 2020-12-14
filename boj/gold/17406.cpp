#include <iostream>
#include <vector>
#include <queue>
#define LEN 51
#define INF 1e9

using namespace std;

int ans = INF;
int n,m;
int arr[LEN][LEN];
vector<vector<int>> cmd_list;
vector<int> cmd;
int temp_arr[LEN][LEN];
bool check[6];

void lotation(int r, int c, int s){

    //right(0), down(1), left(2), up(3)
    int dx[] = {1,0,-1,0}; 
    int dy[] = {0,1,0,-1};

    // lotation
    for(int i=1; i<=s; i++){
        int x = c-i;
        int y = r-i;
        int dir = 0; //start right
        int lim = i*2; //2,4,6,...
        int cnt = 0;
        int cur_val = temp_arr[y][x];
        int next_val;

        while(cnt < lim * 4){
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            next_val = temp_arr[ny][nx]; //cache
            temp_arr[ny][nx] = cur_val;
            cur_val = next_val;

            //move
            x = nx; 
            y = ny;

            cnt++;

            //change direction
            if(cnt % lim == 0) dir++;
        }
    }
}

void permutation(int k, int r){ //kPk
    if(r==0){

        // 1. init
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                temp_arr[i][j] = arr[i][j];
            }
        }

        // 2. lotation
        for(int loc : cmd){
            int r = cmd_list[loc][0];
            int c = cmd_list[loc][1];
            int s = cmd_list[loc][2];

            lotation(r, c, s);
        }

        // 3. get min value
        for(int i=1; i<=n; i++){
            int sum = 0;
            for(int j=1; j<=m; j++){
                sum += temp_arr[i][j];
            }
            ans = min(ans, sum);
        }
    }

    for(int i=0; i<k; i++){
        if(check[i]){
           continue; 
        }

        check[i] = true;
        cmd.push_back(i);

        permutation(k,r-1); //kPk-1

        check[i] = false;
        cmd.pop_back();
    }
}

int main() {
    int k;
    cin >> n >> m >> k;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> arr[i][j];
        }
    }

    for(int i=1; i<=k; i++){
        int r, c, s;
        cin >> r >> c >> s;
        cmd_list.push_back({r,c,s});
    }

    permutation(k,k);

    cout << ans;
}