#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = -1, cnt = 0, sz = scoville.size();
    int first, second, third;
    
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    
    while(sz-- > 1){
        cnt++;
    
        first = pq.top();
        pq.pop();
        
        second = pq.top() * 2;
        pq.pop();
        
        third = first+second;

        if(third >= K){
            answer = cnt;
            break;  
        } 

        pq.push(third);
    }   
    
    return answer;
}