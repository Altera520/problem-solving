#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<pair<int, int>> q;
    int sum = 0;
    int cnt = 0;
    int pt = 0;
    
    while(true){
        
        if(pt == truck_weights.size() && q.empty()){
            break;
        }
        
        if(!q.empty() && (cnt - q.front().second >= bridge_length)){
            sum -= q.front().first;
            q.pop();
        }
        
        if(pt < truck_weights.size() && (sum + truck_weights[pt] <= weight)){
            sum += truck_weights[pt];
            q.push({truck_weights[pt], cnt});
            pt++;
        }
        
        cnt++;
    }
    
    
    return cnt;
}