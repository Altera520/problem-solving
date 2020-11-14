#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct F{
    string head;
    int number;
    int origin_index;
}file;

bool compare(const file f1, const file f2){
    //사전순
    if(f1.head < f2.head){
        return true;
    }
    else if(f1.head > f2.head){
        return false;
    }
    
    //숫자순
    if(f1.number < f2.number){
        return true;
    }
    else if(f1.number > f2.number){
        return false;
    }
    else{
        //인덱스 순
        return f1.origin_index < f2.origin_index;
    }
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<file> in_files;
    
    //전처리
    // head, number, original index
    for(int idx=0; idx< files.size(); idx++){
        file f;
        int i=0;
        string number_string="";
        f.origin_index = idx;
        f.head="";
        string temp = files[idx];
        
        //head
        for(; i<temp.length(); i++){
            if(!(temp[i]>='0' && temp[i]<='9')){
                char ch = temp[i];
                if(ch>='A' && ch<='Z'){
                    ch = ch - ('A' - 'a');
                }
                f.head += ch;
            }
            else{
                break;
            }
        }
        
        //number
        for(; i<temp.length(); i++){
            if(temp[i]>='0' && temp[i]<='9'){
                number_string+=temp[i];
            }
            else{
                break;
            }
        }
        f.number = stoi(number_string);
        
        in_files.push_back(f);
    }
    
    sort(in_files.begin(), in_files.end(), compare);
    
    for(file f : in_files){
        answer.push_back(files[f.origin_index]);
    }        
    
    return answer;
}