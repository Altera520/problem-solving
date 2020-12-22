#include <iostream>
#include <vector>
#include <unordered_map>
#define LEN 101
#define L 'L'
#define R 'R'
#define F 'F'

using namespace std;

typedef struct robot{
    int x;
    int y;
    int dir;
}robot;

int main() {
    int map[LEN][LEN] = {0};
    vector<robot> robots;
    unordered_map<char, int> dic;
    int dx[] = {0,-1,0,1}; //NWSE
    int dy[] = {1,0,-1,0};
    int a, b, n, m;
    cin >> a >> b >> n >> m;

    dic['N'] = 0;
    dic['W'] = 1;
    dic['S'] = 2;
    dic['E'] = 3;
    robots.resize(n+1);

    for(int i=1; i<=n; i++){
        int x, y;
        char dir;

        cin >> x >> y >> dir;
        robots[i] = {x,y,dic[dir]};
        map[y][x] = 1;
    }

    for(int i=1; i<=m; i++){
        int index, loop;
        char cmd;
        cin >> index >> cmd >> loop;
        while(loop-- > 0){
            if(cmd == L){
                robots[index].dir = (robots[index].dir + 1) % 4;
            }
            else if(cmd == R){
                robots[index].dir--;
                if(robots[index].dir < 0) robots[index].dir = 3;
            }
            else if(cmd == F){
                int x = robots[index].x;
                int y = robots[index].y;
                int nx = x + dx[robots[index].dir];
                int ny = y + dy[robots[index].dir];

                if(1 > nx || a < nx || 1 > ny || b < ny){
                    cout << "Robot " << index << " crashes into the wall";
                    goto escape;
                }
                if(map[ny][nx] == 1){
                    int pt;
                    for(pt=1; pt<=n; pt++){
                        if(nx == robots[pt].x && ny == robots[pt].y) break;
                    }

                    cout << "Robot " << index << " crashes into robot " << pt;
                    goto escape;
                }

                map[y][x] = 0;
                map[ny][nx] = 1;
                robots[index].x = nx;
                robots[index].y = ny;
            }
        }
    }

    cout << "OK";
    escape:;
}