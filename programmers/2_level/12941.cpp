#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    int sz = A.size();
    int pt = 0;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    while(pt < sz){
        answer += A[pt] * B[sz-1-pt];
        pt++;
    }

    return answer;
}