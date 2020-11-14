#include <string>
#include <vector>
#include <queue>

using namespace std;

struct ls{
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.first < b.first;
    }
};

struct gt{
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.first > b.first;
    }
};

void max_clear(priority_queue<pair<int, int>, vector<pair<int,int>>, ls> &pq, vector<bool> &dic){
    while(pq.size() > 0 && !dic[pq.top().second]){
        pq.pop();   
    }
}

void min_clear(priority_queue<pair<int, int>, vector<pair<int,int>>, gt> &pq, vector<bool> &dic){
    while(pq.size() > 0 && !dic[pq.top().second]){
        pq.pop();   
    }
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    int cnt = 0, min =0, max = 0;
    priority_queue<pair<int, int>, vector<pair<int,int>>, gt> min_heap;
    priority_queue<pair<int, int>, vector<pair<int,int>>, ls> max_heap;
    vector<bool> dic;
    
    for(string op : operations){
        if(op=="D 1"){
            max_clear(max_heap, dic);
            
            if(max_heap.size() > 0){
                dic[max_heap.top().second] = false;
                max_heap.pop();
                max++;
            }
        }
        else if(op=="D -1"){
            min_clear(min_heap, dic);
            
            if(min_heap.size() > 0){
                dic[min_heap.top().second] = false;
                min_heap.pop();
                min++;
            }
        }
        else{
            int num = stoi(op.substr(2, op.length()-2));
            
            dic.push_back(true);
            
            min_heap.push({num, cnt});
            max_heap.push({num, cnt});
            cnt++;
        }
    }
    
    if(max+min == cnt){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        max_clear(max_heap, dic);
        min_clear(min_heap, dic);
        
        answer.push_back(max_heap.top().first);
        answer.push_back(min_heap.top().first);
    }
    
    return answer;
}