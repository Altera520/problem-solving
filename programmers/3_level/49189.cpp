#include <string>
#include <vector>
#include <queue>
#define INF 1e9
#define LEN 20001

using namespace std;

vector<int> table;
vector<vector<pair<int,int>>> graph;

struct cmp{
    bool operator()(pair<int,int> &t, pair<int,int> &u){
        return t.second > u.second;    
    }
};

void dijkstra(int start, int len){
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    fill(table.begin(), table.end(), INF);
    
    pq.push({start, 0});
    table[start] = 0;
    
    while(!pq.empty()){
        int current_node = pq.top().first;
        int current_cost = pq.top().second;
        pq.pop();
        
        for(auto edge : graph[current_node]){
            int next_node = edge.first;
            int next_cost = edge.second;
            int cost = table[current_node] + next_cost;
            
            if(table[next_node] > cost){
                table[next_node] = cost;
                pq.push({next_node, cost});
            }
        }
    }
}


int solution(int n, vector<vector<int>> edge) {
    int answer = 0, max = 0;
    
    table.resize(n+1);
    
    //그래프 생성
    graph.resize(n+1);
    for(vector<int> e : edge){
        int from = e[0];
        int to = e[1];
        graph[from].push_back({to,1});
        graph[to].push_back({from,1});
    }
    
    dijkstra(1, n);
    
    for(int i=1; i<=n; i++){
        if(table[i] != INF){
            if(table[i] > max){
                max = table[i];
                answer = 1;   
            }
            else if(table[i] == max){
                answer++;
            }
        }
    }
    
    return answer;
}