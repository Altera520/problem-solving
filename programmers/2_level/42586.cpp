#include <string>
#include <vector>
#define CLEAR 100

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int pt = 0;
    int sz = progresses.size();
    
    while(pt < sz){
        int deploy_cnt = 0;
        
        for(int i = pt; i < sz; i++){
            progresses[i] += speeds[i];
        }
        
        while(pt < sz && progresses[pt] >= CLEAR){
            pt++;
            deploy_cnt++;
        }
        
        if(deploy_cnt > 0){
            answer.push_back(deploy_cnt);   
        }
    }
    
    return answer;
}