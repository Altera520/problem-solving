#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for(int i=0; i < skill_trees.size(); i++){
        string tmp = "";
        for(int j = 0; j < skill_trees[i].length(); j++){
            for(char k : skill){
                if(k == skill_trees[i][j]){
                    tmp += k;
                    break;
                }
            }
        }
        
        skill_trees[i] = tmp;
    }
    
    for(int i=0; i < skill_trees.size(); i++){
        if(skill.substr(0,skill_trees[i].length()) == skill_trees[i]) answer++;
    }
    
    return answer;
}