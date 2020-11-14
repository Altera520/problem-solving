#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int st = 0;
    int ed = people.size()-1;
    
    sort(people.begin(), people.end());
    
    do {
        if(people[st] + people[ed] <= limit) {
            st++;
            ed--;
        }
        else {
            ed--;
        }
        
        answer++;
        
    }while(st <= ed);
    
    return answer;
}