#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9

using namespace std;

vector<int> table; //갱신 테이블
vector<vector<pair<int, int>>> map;
vector<int> parent;
int check_p1, check_p2;
bool is_first = true;

struct lt{
    bool operator()(pair<int,int> &t, pair<int,int> &u){
        return t.second > u.second;
    }
};

int dijkstra(int start, int vertex) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, lt> heap;
    fill(table.begin(), table.end(), INF);
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

            // 검문지점 이라면
            if(current_node == check_p1 && next_node == check_p2) continue; 
            if(current_node == check_p2 && next_node == check_p1) continue;

            int cost = next_cost + table[current_node];

            if(table[next_node] > cost){
                table[next_node] = cost;
                heap.push({next_node, table[next_node]});

                if(is_first){
                    parent[next_node] = current_node;
                }
            }
        }
    }

    return table[vertex];
}


int main() {
    int vertex, edge, longest = 0, shortest, ans;
    cin >> vertex >> edge;

    map.resize(vertex+1);
    table.resize(vertex+1);
    parent.resize(vertex+1);

    //generate graph
    for(int i=0; i<edge; i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        map[from].push_back({to, cost}); // to, cost
        map[to].push_back({from, cost});
    }

    parent[1] = 1;
    shortest = dijkstra(1, vertex);
    is_first = false;

    int cnt = vertex;
    while(parent[cnt] != cnt){
        check_p1 = cnt;
        check_p2 = parent[cnt]; //검문 path (from-to, to-from)
        
        longest = max(longest, dijkstra(1, vertex));

        if(longest == INF){
            break;
        }

        cnt = parent[cnt];
    }

    if(longest == INF) ans = -1;
    else ans = longest - shortest;

    cout << ans;
}