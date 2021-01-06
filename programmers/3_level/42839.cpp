#include <string>
#include <vector>
#include <set>
#define LEN 10000000

using namespace std;

bool arr[LEN] = {false};
bool check[7] = {false};
set<int> s;
string temp = "";

void permutation(int n, int r, string &numbers){
    if(r==0){
        return;
    }
    
    for(int i=0; i<n; i++){
        if(check[i]) continue;

        temp.push_back(numbers[i]);
        check[i] = true;

        int val = stoi(temp);
        if(!arr[val]){
            
            s.insert(val);
        }
        
        permutation(n,r-1, numbers);
        
        temp.pop_back();
        check[i] = false;
        
    }
}

void prime(){
    arr[0] = true;
    arr[1] = true;
    for(int i=2; i<LEN; i++){
        if(arr[i]) continue;
        
        for(int j=i*2; j<LEN; j+=i){
            arr[j] = true;
        }
    }
}

int solution(string numbers) {

    prime();
    
    permutation(numbers.length(), numbers.length(), numbers);
    
    return s.size();
}