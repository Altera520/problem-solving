#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool cmp(int a, int b){
    return a > b;
}

int solution(vector<int> priorities, int location) {
    int pt = 0;
    int cnt = 0;
    
    queue<pair<int, bool>> q;
    
    for(int i=0 ; i<priorities.size(); i++){
        q.push({priorities[i], location == i});
    }
    
    sort(priorities.begin(), priorities.end(), cmp);
    
    while(!q.empty()){
        pair<int, bool> elem = q.front();
        q.pop();
        if(elem.first < priorities[pt]){
            q.push(elem);
        }
        else{
            cnt++;
            pt++;
            
            if(elem.second){
                break;
            }
        }
    }
    
    return cnt;
}