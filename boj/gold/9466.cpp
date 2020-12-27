#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while(tc-- > 0){
        int n, ans = 0;
        vector<vector<int>> graph;
        vector<int> indegree;
        vector<bool> visit;
        queue<int> q;

        cin >> n;

        graph.resize(n+1);
        indegree.resize(n+1);
        visit.resize(n+1);

        //그래프 생성
        for(int from=1; from<=n; from++){
            int to;
            cin >> to;
            graph[from].push_back(to);
            indegree[to]++;
        }

        //진입차수가 0인 그래프 탐색
        for(int i=1; i<=n; i++){
            if(!visit[i] && indegree[i] == 0){
                q.push(i);                

                while(!q.empty()){
                    int cur = q.front();
                    visit[cur] = true;
                    ans++;
                    q.pop();

                    //진입차수 제거
                    for(int next : graph[cur]){
                        indegree[next] -= 1;

                        //새롭게 진입차수가 0이 되는 노드 삽입
                        if(indegree[next] == 0){ 
                            q.push(next);
                        }
                    }
                }
            }
        }

        cout << ans << '\n';
    }
}