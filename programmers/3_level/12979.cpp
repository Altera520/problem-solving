#include <iostream>
#include <vector>
using namespace std;

int calc(int st, int ed, int w) {
    int len = ed - st;
    int range = w * 2 + 1;
    int add = 0;
    if(len % range != 0) add++;
    return len / range + add;
}

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    
    // side 검출
    stations.insert(stations.begin(), w * -1);
    stations.push_back(n + w + 1);

    for(int i = 0; i < stations.size() - 1; i++) {
        int cur = stations[i] + w + 1;
        int next = stations[i + 1] - w;
        
        if(cur < left) {
            answer += calc(cur, next, w);
        }
    }

    return answer;
}