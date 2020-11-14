#include <string>
#include <vector>
#define MAX 100001
#define DIV 1234567

using namespace std;

int memoziation[MAX] = {0};

int fibonacchi(int n){
    if(n <= 0) {
        return 0;   
    }
    else if(memoziation[n]!=0){
        return memoziation[n];
    }
    else{
        memoziation[n]  = (fibonacchi(n-1) + fibonacchi(n-2)) % DIV; 
        return memoziation[n];
    }
}

int solution(int n) {
    memoziation[1] = 1;
    return fibonacchi(n);
}