#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1001
using namespace std;

int cycle_table[MAX];
int depth[MAX];

typedef struct edge_info{
    int from;
    int to;
    int cost;
}e;

bool cmp(const e &t, const e &u){
    return t.cost < u.cost;
}

void init(int n){
    for(int i=1; i<=n; i++){
        cycle_table[i] = i;
    }
}

int find(int node){
    if(node == cycle_table[node]){
        return node;
    }
    else{
        return cycle_table[node] = find(cycle_table[node]);
    }
}

bool do_union(int x, int y){
    x = find(x);
    y = find(y);

    if(x==y){
        return false;
    }

    if(depth[x] < depth[y]){
        cycle_table[x] = y;
    }
    else{
        cycle_table[y] = x;

        if(depth[x] == depth[y]){
            depth[x]++;
        }
    }

    return true;
}

int main() {
    int vertex, edge, answer = 0;
    vector<e> v;

    cin >> vertex >> edge;

    init(vertex);

    for(int i=0; i<edge; i++){
        int a,b,c;
        cin >> a >> b >> c;

        v.push_back({a,b,c});
    }

    // 1st step. sort
    sort(v.begin(), v.end(), cmp);

    // 2nd step. union-find & sum
    for(e node : v){
        if(do_union(node.from, node.to)){
            answer += node.cost;
        }
    }

    cout << answer;
}