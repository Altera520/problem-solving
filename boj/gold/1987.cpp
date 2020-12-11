#include <iostream>
#include <vector>
#define LEN 21
#define SZ 26
using namespace std;

int step = 1;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool dic[SZ] = { false };
vector<string> map;
int r, c;// row, col

int get_index(int y, int x){
    return map[y][x] - 'A';
}

bool possible(int y, int x){
    int index = get_index(y, x);
    return !dic[index];
}

//use stack, Possibility check before putting it on the stack
void dfs(int y, int x, int k){
    int index = get_index(y, x);
    dic[index] = true;

    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(1 <= nx && nx <= c && 1 <= ny && ny <= r){
            if(possible(ny, nx)){
                dfs(ny, nx, k+1);
            }
        }
    }

    dic[index] = false;
    step = max(step, k);
}

int main() {
    cin >> r >> c;

    map.resize(r+1);
    for(int i=1; i<=r; i++){
        cin >> map[i];
        map[i] = " " + map[i];
    }

    dfs(1,1,1);

    cout << step;
}