#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

vector<vector<pair<int, int>>> map; // to, cost
vector<int> table;

struct cmp{
    bool operator()(pair<int, int> &p, pair<int, int> &q){
        return p.second > q.second;
    }
};

void dijkstra(int st) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    
    pq.push({st, 0});
    table[st] = 0;
    
    while(!pq.empty()) {
        int cur_node = pq.top().first;
        pq.pop();
        
        for(auto next : map[cur_node]) {
            int next_node = next.first;
            int next_cost = next.second;
            int cost = table[cur_node] + next_cost;
            
            if(cost < table[next_node]) {
                pq.push({next_node, cost});
                table[next_node] = cost;
            }
        }
    }
}

int solution(int N, vector<vector<int>> road, int K) {
    int ans = 0;
    map.resize(N + 1);
    table.resize(N + 1);
    fill(table.begin(), table.end(), INF);
    
    // generate graph
    for(auto info : road) {
        int from = info[0];
        int to = info[1];
        int cost = info[2];
        map[from].push_back({to, cost});
        map[to].push_back({from, cost});
    }
    
    dijkstra(1);
    
    // count
    for(int node : table) {
        if(node <= K) {
            ans++;
        }
    }

    return ans;
}