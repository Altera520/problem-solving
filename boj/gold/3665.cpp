#include <iostream>
#include <vector>
#include <queue>
#define LEN 501

using namespace std;

int graph[LEN][LEN];
int indegree[LEN];
bool check[LEN];
bool uncertain = false;

//O(V+E)
void topology_sort(vector<int> &seq, int vertex){
    queue<int> q;

    for(int i=1; i<= vertex; i++){
        if(indegree[i] == 0){
            q.push(i);
            break;
        }
    }

    while(!q.empty()){
        uncertain = q.size() > 1;
        if(uncertain) break;

        int cur = q.front();

        seq.push_back(cur);

        for(int i=1; i<=vertex; i++){
            if(graph[cur][i] == 0) continue;
            indegree[i] -= 1;

            if(indegree[i] == 0){ 
                q.push(i);
            }
        }

        q.pop();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;

    cin >> tc;
    while(tc-- > 0){
        int vertex, m;
        vector<int> ans;
        uncertain = false;

        cin >> vertex;

        for(int i=1; i <= vertex; i++){
            indegree[i] = 0;
            check[i] = false;
        }

        for(int i=1; i <= vertex; i++){
            int n;
            cin >> n;
            check[n] = true;
            for(int j=1; j <= vertex; j++){
                if(!check[j]){
                    graph[n][j] = 1; //from -> to
                    indegree[j] += 1;
                }
                else{
                    graph[n][j] = 0;
                }
            }
        }

        cin >> m;
        for(int i=1; i <= m; i++){
            int winner, loser;
            cin >> winner >> loser;

            //위상 뒤바꾸기
            if(graph[winner][loser] == 1){
                graph[winner][loser] = 0; 
                graph[loser][winner] = 1;
                indegree[winner]++;
                indegree[loser]--;
            }
            else{
                graph[winner][loser] = 1; 
                graph[loser][winner] = 0;
                indegree[winner]--;
                indegree[loser]++;
            }
        }

        topology_sort(ans, vertex);

        //확실한 순위를 찾을 수 없는 경우(테크트리가 완료되는 노드가 동시에 2개이상 생성 = 큐에 2개 이상의 노드가 들어감)
        if(uncertain){
            cout << "?\n";
        }
        //데이터에 일관성이 없는 경우 (DAG가 성립X)
        else if(ans.size() != vertex){
            cout << "IMPOSSIBLE\n";
        }
        //순위를 만드는 것이 가능한 경우
        else{
            for(int i=1; i <= vertex; i++){
                cout << ans[i-1] << ' ';
            }
            cout << '\n';
        }
    }
}