#include <string>
#include <vector>
#include <set>
#define MAX 10000001

using namespace std;

int arr[MAX] = {0};
set<int> s;

void permutation(string &source, string &target, vector<bool> &check, int n, int r){
    if(r==0){
        s.insert(stoi(target));
        return;
    }

    for(int i=0; i<n; i++){
        if(check[i]){
            continue;
        }

        check[i] = true;
        target += source[i];

        permutation(source, target, check, n, r-1);

        check[i] = false;
        target.erase(target.length()-1,1);
    }
}

int solution(string numbers) {
    
    int cnt =0;
    int sz = numbers.length();
    vector<bool> check = vector<bool>(sz,false);
    
    //전처리
    arr[0]=1;
    arr[1]=1;
    for(int i=2; i<MAX; i++){
        if(arr[i]==1){
            continue;
        }
        
        for(int j=i*i; j<MAX; j+=i){
            arr[j]=1;
        }
    }
    
    string str="";
    for(int i=sz; i>0; i--){
        permutation(numbers, str, check, sz, i);
    }
    
    for(int elem : s){
        if(arr[elem]==0){
            cnt++;
        }
    }
    
    return cnt;
}