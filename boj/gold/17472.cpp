#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <algorithm>

#define LAND 1
#define LEN 11
#define MAX 7

using namespace std;

int country[LEN][LEN];
bool visit[LEN][LEN];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

unordered_map<int, int> vertex_index;
int sz = 1;
vector<vector<int>> edge; //from ,to, cost

int root[MAX];
int depth[MAX]; //union by rank

int hash_func(int y, int x){
    return y*10 + x;
}

void get_vertex(int m, int n){ // y, x
    queue<pair<int,int>> q;

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(country[i][j] == LAND && !visit[i][j]){
                q.push({i,j}); //y,x
                visit[i][j] = true;

                while(!q.empty()){
                    pair<int,int> tmp = q.front();

                    for(int k=0; k<4; k++){
                        int y = tmp.first + dy[k];
                        int x = tmp.second + dx[k];

                        if(1 <= x && x <= n && 1 <= y && y<= m){
                            if(country[y][x] == LAND && !visit[y][x]){
                                q.push({y, x});
                                visit[y][x] = true;
                            }
                        }
                    }

                    q.pop();
                    vertex_index[hash_func(tmp.first,tmp.second)] = sz;
                }

                sz++;
            }
        }
    }
    sz--;
}

void find_edge(int y, int x, bool flag){
    for(int i=1; i<=y; i++){
        int from = 0, to = 0, cost = 0;

        for(int j=1; j<=x; j++){
            int node = flag ? country[i][j] : country[j][i];
            if(node == LAND){
                int tmp = flag ? vertex_index[hash_func(i,j)] : vertex_index[hash_func(j,i)];

                if(from == 0){
                    from = tmp;
                }
                else{
                    to = tmp;

                    if(from != to){ //to를 만난 경우
                        if(cost >= 2){
                            edge.push_back({from, to, cost});
                        }
                        cost = 0;
                        from = to;
                        to = 0;
                    }
                    else cost = 0;
                }
            }
            else if(from != 0) cost++;
        }
    }
}

void get_edge(int m, int n){
    find_edge(m, n, true); //horizontal
    find_edge(n, m, false); //vertical
}

bool cmp(vector<int> &t, vector<int> &u){
    return t[2] < u[2]; //cost 기준
}

void init(int n){
    for(int i=1; i<=n; i++){
        root[i] = i;
        depth[i] = 0;
    }
}

int find(int node){
    if(root[node] == node){
        return node;
    }
    else{
        return root[node] = find(root[node]);
    }
}

bool do_union(int x, int y){
    x = find(x);
    y = find(y);

    if(x==y) return false;

    if(depth[x] < depth[y]){
        root[x] = y;
    }
    else{
        root[y] = x;

        if(depth[x] == depth[y]){
            depth[x]++;
        }
    }
    
    return true;
}

int main() {
    int m, n, cnt = 0, answer = 0;
    cin >> m >> n;

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            cin >> country[i][j];
        }
    }

    get_vertex(m, n);
    get_edge(m, n);
    sort(edge.begin(), edge.end(), cmp);

    init(MAX - 1);

    for(vector<int> e : edge){
        if(do_union(e[0], e[1])){
            answer += e[2];
            cnt++;
        }

        if(cnt == sz-1) break;
    }

    if(sz < 2 || cnt != sz - 1) answer = -1;

    cout << answer;
}