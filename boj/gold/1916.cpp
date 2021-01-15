#include <iostream> 
#include <vector>
#include <queue>
#define LEN 100001
#define INF 1e11

using namespace std;

vector<vector<pair<int,int>>> graph;
long long table[LEN];
int n, m;

void dijkstra(int st){
    fill(table, table + n + 1, INF);
    priority_queue<pair<int, int>> pq;
    pq.push({0, st}); //node, cost
    table[st] = 0;

    while(!pq.empty()){
        int cur_node = pq.top().second;
        pq.pop();

        for(auto next : graph[cur_node]){
            int next_node = next.first;
            int next_cost = next.second;
            int cost = next_cost + table[cur_node];

            if(table[next_node] > cost){
                table[next_node] = cost;
                pq.push({-cost, next_node});
            }
        }
    }
}

int main(){
    int a, b;

    cin >> n >> m;
    graph.resize(n + 1);
    for(int i=1; i <= m; i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back({to, cost});
    }
    cin >> a >> b;

    dijkstra(a);
    cout << table[b];
}