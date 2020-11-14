#include <string>
#include <vector>
#include <queue>

using namespace std;

bool link(string &s1, string &s2){
    int sz = s1.size(), cnt = 0;
    for(int i=0; i<sz; i++){
        if(s1[i]==s2[i]) cnt++;
    }
    
    return cnt == sz-1;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int min = 250;
    int st = words.size();
    
    vector<vector<int>> map;
    queue<pair<int,int>> q;
    words.push_back(begin);
    
    vector<bool> visit(words.size(), false);
    map.resize(words.size());
    
    for(int i=0; i<words.size(); i++){  
        for(int j=i+1; j<words.size(); j++){
            if(link(words[i], words[j])){
                map[i].push_back(j);
                map[j].push_back(i);
            }
        }
    }
    
    q.push({st, 0});
    visit[st] = true;
    
    while(!q.empty()){
        pair<int, int> tmp = q.front();
        
        for(int j=0; j < map[tmp.first].size(); j++){
            int idx = map[tmp.first][j];
            
            if(words[idx]==target){
                if(min > tmp.second+1){
                    min = tmp.second+1;
                }
            }
            else if(!visit[idx]){
                q.push({idx, tmp.second+1});
                visit[idx] = true;
            }
        }
        
        q.pop();
    }
    
    answer = min==250 ? 0 : min;
    
    return answer;
}