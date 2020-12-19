#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<int> indegree;
vector<bool> visit;
int vertex, edge;
int k;

//O(V+E)
void topology_sort(){
    queue<int> q;

    //진입차수가 0인 그래프 탐색
    for(int i=1; i<= vertex; i++){
        if(indegree[i] == 0 && !visit[i]){
            q.push(i);
            break;
        }
    }

    while(!q.empty()){
        int cur = q.front();
        visit[cur] = true;

        k--;
        cout << cur << ' ';

        //진입차수 제거
        for(int next : graph[cur]){
            indegree[next] -= 1;

            //새롭게 진입차수가 0이 되는 노드 삽입
            if(indegree[next] == 0){ 
                q.push(next);
            }
        }

        q.pop();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> vertex >> edge;
    graph.resize(vertex + 1);
    indegree.resize(vertex + 1);
    visit.resize(vertex + 1);
    k = vertex;

    for(int i=0; i < edge; i++){
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        indegree[to] += 1;
    }

    while(k > 0){
        topology_sort();
    }
}