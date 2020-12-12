#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
#define MAX 10001

using namespace std;

int table[MAX];
vector<vector<pair<int, int>>> map;

struct lt{
    bool operator()(pair<int,int> &t, pair<int,int> &u){
        return t.second > u.second;
    }
};

void dijkstra(int start) {
    bool is_find = false;
    priority_queue<pair<int,int>, vector<pair<int,int>>, lt> heap;
    table[start] = 0;
    heap.push({start, 0});

    while(!heap.empty()){
        int current_node = heap.top().first;
        int current_cost = heap.top().second;

        heap.pop();

        for(int i = 0; i < map[current_node].size(); i++){
            pair<int,int> next = map[current_node][i];
            int next_node = next.first;
            int next_cost = next.second;

            int cost = next_cost + table[current_node];

            if(table[next_node] > cost){
                table[next_node] = cost;
                heap.push({next_node, table[next_node]});
            }
        }
    }
}


int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int tc;
    cin >> tc;

    while(tc-- > 0){
        int vertex, edge, x, ans = 0, cnt = 0;
        cin >> vertex >> edge >> x;

        fill(table, table + vertex + 1, INF);
        map.clear();
        map.resize(vertex+1);

        //generate graph
        for(int i=0; i<edge; i++){
            int a, b, cost;
            cin >> a >> b >> cost;
            map[b].push_back({a, cost}); // to, cost
        }

        dijkstra(x);

        for(int i=1; i <= vertex; i++){
            if(table[i] != INF){
                ans = max(ans, table[i]);
                cnt++;
            }
        }

        cout << cnt << ' ' << ans << '\n';
    }
}