#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int,int>>> map;
vector<bool> visit;

int prim(int start){
    int ans = 0;
    visit[start] = true;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; 

    for(pair<int,int> next : map[start]){
        int next_node = next.first;
        int next_cost = next.second;
        pq.push({next_cost, next_node}); //cost, node;
    }

    while(!pq.empty()){
        int current_node = pq.top().second;
        int current_cost = pq.top().first;

        pq.pop();

        if(visit[current_node]) continue;
        visit[current_node] = true;
        ans += current_cost;

        for(pair<int,int> next : map[current_node]){
            int next_node = next.first;
            int next_cost = next.second;
            pq.push({next_cost, next_node}); //cost, node;
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int vertex, edge;
    cin >> vertex >> edge;

    map.resize(vertex + 1);
    visit.resize(vertex + 1);

    for(int i=0; i<edge; i++){
        int from, to, cost;
        cin >> from >> to >> cost;

        map[from].push_back({to, cost}); //node, cost
        map[to].push_back({from, cost});
    }
    
    cout << prim(1);
}