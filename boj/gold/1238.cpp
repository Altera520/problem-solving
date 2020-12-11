#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9

using namespace std;

vector<int> table; //shortest path table
vector<int> students;
vector<vector<pair<int, int>>> map;
int ans = 0;

typedef struct info{
    int from;
    int to;
    int cost;
}info;

struct cmp{
    bool operator()(pair<int,int> &t, pair<int,int> &u){
        return t.second > u.second;
    }
};

void dijkstra(int start, int vertex){
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> heap; //O(ElogV)

    fill(table.begin(), table.end(), INF); // table init
    table[start] = 0;
    heap.push({start, 0}); //node, cost

    while(!heap.empty()){
        int current_node = heap.top().first;
        int current_cost = heap.top().second;

        heap.pop();

        for(pair<int, int> next : map[current_node]){
            int next_node = next.first;
            int next_cost = next.second;
            int cost = table[current_node] + next_cost;

            if(table[next_node] > cost){
                table[next_node] = cost;
                heap.push({next_node, table[next_node]}); //node, cost
            }
        }
    }

    for(int i=1; i <= vertex; i++){
        students[i] += table[i];
        ans = max(students[i], ans);
    }
}

int main() {
    int vertex, edge, x;
    queue<info> q;
    cin >> vertex >> edge >> x;

    map.resize(vertex + 1); //1 ~ vertex
    table.resize(vertex + 1);
    students.resize(vertex + 1);

    for(int i=1; i <= edge; i++){
        int from, to, cost;
        cin >> from >> to >> cost;

        map[from].push_back({to, cost}); //node, cost
    }

    dijkstra(x, vertex); //first dijkstra

    //reverse from and to
    for(int i=1; i<=vertex; i++){
        for(int j=0; j < map[i].size(); j++){
            int from = i;
            int to = map[i][j].first;
            int cost = map[i][j].second;
            q.push({to, from, cost});
        }
        map[i].clear();
    }
    while(!q.empty()){
        info tmp = q.front();
        map[tmp.from].push_back({tmp.to, tmp.cost});
        q.pop();
    }

    dijkstra(x, vertex); //second dijkstra

    cout << ans;
}