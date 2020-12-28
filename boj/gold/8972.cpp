#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define LEN 101
#define CRAZY 'R'
#define PLAYER 'I'
#define EMPTY '.'
#define INF 1e9

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int R, C, step = 0;
    vector<string> map;
    pair<int,int> player;
    vector<pair<int,int>> crazy;
    string command;
    bool is_end = false;
    int dx[] = {0,-1,0,1,-1,0,1,-1,0,1}; // 1 ~ 9, 0은 dummy
    int dy[] = {0,1,1,1,0,0,0,-1,-1,-1};

    // 입력
    cin >> R >> C;
    for(int i=0; i<R; i++){
        string row;
        cin >> row;
        map.push_back(row);
        for(int j=0; j<C; j++){
            if(map[i][j] == CRAZY) crazy.push_back({i, j}); // y,x
            if(map[i][j] == PLAYER) player = {i, j};
        }
    }
    cin >> command;

    for(char c : command){
        int cmd = c - '0';

        // 플레이어 이동
        int py = player.first + dy[cmd];
        int px = player.second + dx[cmd];
        step++;

        is_end = map[py][px] == CRAZY; //R과 충돌 검사
        if(is_end) break;

        map[player.first][player.second] = EMPTY;
        map[py][px] = PLAYER;
        player = {py, px};

        //미친 아두이노 이동
        for(int i=0; i < crazy.size(); i++){
            int cy, cx, judge = INF;
            for(int k=1; k<=9; k++){
                if(k==5) continue;
                int ty = crazy[i].first + dy[k];
                int tx = crazy[i].second + dx[k];

                if(0 > ty || ty >= R || 0 > tx || tx >= C) continue;

                int val = abs(py - ty) + abs(px - tx);
                if(judge > val){
                    judge = val;
                    cy = ty;
                    cx = tx;
                }
            }

            is_end = map[cy][cx] == PLAYER; // I와 충돌 검사
            if(is_end) goto escape;

            map[crazy[i].first][crazy[i].second] = EMPTY;
            crazy[i] = {cy, cx};
        }

        //R와 충돌 검사 및 폭팔 처리
        sort(crazy.begin(), crazy.end());
        vector<pair<int,int>> temp;
        for(int i=0; i < crazy.size(); i++){
            int j = i;

            //충돌이 발생하는 인덱스는 건너뛰기
            while(j < crazy.size() && crazy[i] == crazy[j+1]){ 
                j++;
            }
            if(i==j){ // 충돌이 발생하지 않은 경우
                int cy = crazy[i].first;
                int cx = crazy[i].second;
                map[cy][cx] = CRAZY;
                temp.push_back(crazy[i]);
            }
            else i = j; // 인덱스 변경 (건너뛰기)
        }
        crazy = temp;
    }
    escape:;

    if(is_end){
        cout << "kraj " << step;
    }
    else{
        for(int i=0; i<R; i++){
            cout << map[i] << '\n';
        }
    }
}