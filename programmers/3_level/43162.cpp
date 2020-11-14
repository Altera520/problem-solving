#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<bool> visit(n, false);
    queue<int> q;
    
    for(int i=0; i<n; i++){
        if(!visit[i]){
            q.push(i);
            visit[i] = true;
            
            while(!q.empty()){
                int idx = q.front();
                
                for(int j=0; j<n; j++){
                    if(!visit[j] && computers[idx][j]==1){
                        q.push(j);
                        visit[j] = true;
                    }
                }
                
                q.pop();
            }
            
            answer++;
        }
    }
    
    return answer;
}