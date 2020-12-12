#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 100001

using namespace std;

int root[MAX];
int depth[MAX];

typedef struct info{
    int from;
    int to;
    int cost;
}info;

bool cmp(info &t, info &u){
    return t.cost < u.cost;
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
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<info> path_list;
    int vertex, edge, ans = 0, path = 0, cnt;
    cin >> vertex >> edge;

    for(int i=1; i<=edge; i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        path_list.push_back({from, to, cost});
    }

    sort(path_list.begin(), path_list.end(), cmp);
    init(vertex);

    for(info tmp : path_list){
        if(do_union(tmp.from, tmp.to)){
            ans += tmp.cost;
            path = max(path, tmp.cost);
            cnt++;
        }

        if(cnt == vertex) break;
    }

    cout << ans - path;
}