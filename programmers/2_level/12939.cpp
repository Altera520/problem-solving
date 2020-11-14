#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int pt = 0, max = 0, min = 0;
    
    
    while(pt < s.length()){
        int len = 1;
        if(s[pt]=='-'){   
            len = 2;
        }
        
        while(s[pt+len]!=' '){
            len++;
        }
        
        int tmp = stoi(s.substr(pt,len));
            
        if(tmp > max || pt==0){
            max = tmp;
        }
        if(tmp < min || pt==0){
            min = tmp;
        }
        
        pt += (len + 1);
    }
    
    answer = to_string(min) + " " + to_string(max);
    
    return answer;
}