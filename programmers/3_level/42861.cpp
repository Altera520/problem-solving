#include <string>
#include <vector>
#include <algorithm>
#define MAX 101

using namespace std;

int root[MAX];
int depth[MAX]; //union by rank

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

bool cmp(vector<int> &t, vector<int> &u){
    return t[2] < u[2];
}

int solution(int n, vector<vector<int>> costs) { //from, to, cost
    int answer = 0;
    int cnt = 0;
    
    init(MAX);
    sort(costs.begin(), costs.end(), cmp);
    for(vector<int> cost : costs){
        if(do_union(cost[0], cost[1])){
            answer += cost[2];
            cnt++;
        }
        if(cnt == n) break;
    }
    
    return answer;
}