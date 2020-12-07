#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct hdd{
    bool is_act;
    int start;
    int exec_time;
    int head;
}hdd;

hdd hard_disk;

void alloc_job(int start, int end){
    hard_disk.is_act = true;
    hard_disk.start = start;
    hard_disk.exec_time = end;
}

void free_job(){
    hard_disk.is_act = false;
}

bool cmp(vector<int> &t, vector<int> &u){
    if(t[0] == u[0]) return t[1] < u[1];
    return t[0] < u[0];
}

struct pq_cmp{
    bool operator()(pair<int,int> &t, pair<int,int> &u){
        return t.second > u.second;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int counter = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, pq_cmp> pq;
    hard_disk.head = 0;
    
    sort(jobs.begin(), jobs.end(), cmp);
    
    while(true){
        if(hard_disk.is_act){ //작업 처리중이라면
            int end_time = hard_disk.start + hard_disk.exec_time;
            
            if(hard_disk.head < jobs.size()){
                int next_start = jobs[hard_disk.head][0];
                int next_exec_time = jobs[hard_disk.head][1];
                
                if(next_start < end_time){ //작업 처리 중에 새로운 작업 요청
                    pq.push({next_start, next_exec_time});   
                    hard_disk.head += 1;
                }
            }
            
            if(counter == end_time){ //job이 끝날 때
                free_job();
                
                if(!pq.empty()){ //heap에 들어온 작업이 있다면
                    pair<int,int> job = pq.top();
                    pq.pop();
                    answer += ((counter - job.first) + job.second);
                    alloc_job(counter, job.second);
                }
            }
        }
        else if(hard_disk.head < jobs.size()){ //작업 수행중이 아닌 경우
            int next_start = jobs[hard_disk.head][0];
            int next_exec_time = jobs[hard_disk.head][1];
            
            if(next_start == counter){
                answer += ((counter - next_start) + next_exec_time);
                alloc_job(counter, next_exec_time);
                hard_disk.head += 1;
            }
            
        }
        else if(pq.empty()) break; //더이상 처리할 작업이 없다면 종료
    
        counter++;
    }
    
    return answer / jobs.size();
}