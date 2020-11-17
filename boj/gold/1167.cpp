#include <iostream>
#include <vector>
#include <queue>
#define LEN 100001

using namespace std;

void bfs(int st, pair<int,int> &node, vector<vector<pair<int,int>>> &tree){
    int visit[LEN] = {0};
    queue<pair<int,int>> q;

    q.push({st,0});
    visit[st]=1;

    while(!q.empty()){
        int idx = q.front().first;
        int val = q.front().second;

        if(node.second < val){
            node.first = idx;
            node.second = val;
        }

        for(auto edge : tree[idx]){
            if(visit[edge.first]==0){
                visit[edge.first]=1;
                q.push({edge.first, val+edge.second});
            }
        }
        q.pop();
    }
}

int main() {
    cin.tie(0);
	ios_base::sync_with_stdio(false);

    vector<vector<pair<int,int>>> tree;
    pair<int,int> node = {1,0};
    int v;
    cin >> v;
    tree.resize(v+1);

    for(int i=1; i<=v; i++){
        int from;
        cin >> from;

        while(true){
            int to, val;
            cin >> to;
            if(to==-1) break;
            cin >> val;

            tree[from].push_back({to,val});
        }
    }

    //1번 노드에서 지름이 가장 큰 노드 구하기(bfs)
    bfs(1,node,tree);

    //기존에 구한 노드에서 다시 지름이 가장 큰 노드 구하기(bfs)
    bfs(node.first,node,tree);

    cout << node.second;
}